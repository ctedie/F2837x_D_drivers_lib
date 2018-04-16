/*********************************************************************************************************************
 *                                                      COMECA
 ********************************************************************************************************************/
/**
 ********************************************************************************************************************
 *  \author		tedie.cedric
 *  \date		9 mars 2018
 *  \addtogroup	DRV_SCI
 *  \{
 ********************************************************************************************************************/
/**
 ********************************************************************************************************************
 *  \file		drv_sci.c
 *  
 *  \brief		The SCI driver source file
 *
 *  \details	
 *
 ********************************************************************************************************************/

/* Includes --------------------------------------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "F28x_Project.h"

#ifdef OS
#include <ti/sysbios/family/c28/Hwi.h>
#include <ti/sysbios/knl/Swi.h>
#endif



#include "hw_ints.h"
#include "drv_utils.h"
#include "drv_sci.h"


/* Macro definition ------------------------------------------------------------------------------------------------*/
/* Constant definition ---------------------------------------------------------------------------------------------*/
/* Type definition  ------------------------------------------------------------------------------------------------*/
#ifdef OS
/** The local hwi paramters structure */
typedef struct
{
    Hwi_Handle rxHwiHandle;
    Hwi_Params rxHwiParams;
    Hwi_Handle txHwiHandle;
    Hwi_Params txHwiParams;
}HwiParams_t;
#endif

/** The SCI Handle structure */
typedef struct
{
    volatile struct SCI_REGS *sci;

    drvSciReceiveCallback_t cbReception;
    void* pReceptionData;
    drvSciTransmitCallback_t cbTransmission;
    void* pTransmitionData;
    drvSciEndOfTransmissionCallback_t cbEndOfTransmition;
    void* pEndOfTransmitionArg;
#ifdef OS
    HwiParams_t hwiConf;
#endif
    bool initOk;
    bool isBusy;
    uint32_t _RX_ERRORS;
    uint32_t _TX_ERRORS;
}UARTHandle_t;

/* Public variables ------------------------------------------------------------------------------------------------*/
/* Private variables -----------------------------------------------------------------------------------------------*/

/** Th list of available uart handle */
static UARTHandle_t m_UARTList[NB_SERIAL] =
{
     {
          .sci = &SciaRegs,
          .initOk = false,
          .isBusy = false
     },
     {
          .sci = &ScibRegs,
          .initOk = false,
          .isBusy = false
     },
     {
          .sci = &ScicRegs,
          .initOk = false,
          .isBusy = false
     }
};

/* Private functions prototypes ------------------------------------------------------------------------------------*/
static bool setBaudRate(volatile struct SCI_REGS *pSci, drvSciSpeed_t speed);
static void sciGeneralRxIsr(drvSciNumber_t uartNb);
static void sciGeneralTxIsr(drvSciNumber_t uartNb);
#ifdef OS
#else
static void sciaRxIsr(void);
static void sciaTxIsr(void);
static void scibRxIsr(void);
static void scibTxIsr(void);
static void scicRxIsr(void);
static void scicTxIsr(void);
static void scidRxIsr(void);
static void scidTxIsr(void);
#endif /* OS */

/* Private functions -----------------------------------------------------------------------------------------------*/

/**
 **********************************************************
 * \brief Set the baudrate with the choosen parameters
 *
 * \param [in]  pSci    A pointer to sci register
 * \param [in]  speed   One of the baudrate value of drvSciSpeed_t
 *
 * \return
 **********************************************************/
static bool setBaudRate(volatile struct SCI_REGS *pSci, drvSciSpeed_t speed)
{
    uint16_t brr_Value;

    //TODO Get CPU clock instead of 200000000
    brr_Value = 200000000 / ((uint32_t)speed * 8 * (ClkCfgRegs.LOSPCP.bit.LSPCLKDIV * 2));
    pSci->SCIHBAUD.all = (brr_Value >> 8) & 0xFF;
    pSci->SCILBAUD.all = (brr_Value & 0xFF);

    return true;
}

#ifdef OS
//TODO define HWI function that post a SWI (The swi are sciGeneralRxIsr & sciGeneralTxIsr)
#else
/**
 **********************************************************
 * \brief   Default Interrupt handler for SCIA RX
 **********************************************************/
static __interrupt void sciaRxIsr(void)
{
    sciGeneralRxIsr(SCI_A);
}

/**
 **********************************************************
 * \brief   Default Interrupt handler for SCIA TX
 **********************************************************/
static __interrupt void sciaTxIsr(void)
{
    sciGeneralTxIsr(SCI_A);
}

/**
 **********************************************************
 * \brief   Default Interrupt handler for SCIB RX
 **********************************************************/
interrupt void scibRxIsr(void)
{
    sciGeneralRxIsr(SCI_B);
}

/**
 **********************************************************
 * \brief   Default Interrupt handler for SCIB TX
 **********************************************************/
interrupt void scibTxIsr(void)
{
    sciGeneralTxIsr(SCI_B);
}

/**
 **********************************************************
 * \brief   Default Interrupt handler for SCIC RX
 **********************************************************/
interrupt void scicRxIsr(void)
{
    sciGeneralRxIsr(SCI_C);
}

/**
 **********************************************************
 * \brief   Default Interrupt handler for SCIC RX
 **********************************************************/
interrupt void scicTxIsr(void)
{
    sciGeneralTxIsr(SCI_C);
}

/**
 **********************************************************
 * \brief   Default Interrupt handler for SCID RX
 **********************************************************/
interrupt void scidRxIsr(void)
{
    sciGeneralRxIsr(SCI_D);
}

/**
 **********************************************************
 * \brief   Default Interrupt handler for SCID RX
 **********************************************************/
interrupt void scidTxIsr(void)
{
    sciGeneralTxIsr(SCI_D);
}

#endif /* OS */

/**
 **********************************************************
 * \brief The genreral interrupt handler.
 *        Each default handler call this function with
 *        their own SCI Number
 *
 * \param [in]    uartNb  The SCI number
 **********************************************************/
static void sciGeneralRxIsr(drvSciNumber_t uartNb)
{
    UARTHandle_t *pHandle = &m_UARTList[uartNb];
    uint16_t car;

    if(pHandle->cbReception != NULL)
    {
        if(pHandle->sci->SCIFFRX.bit.RXFFST)
        {
            car = pHandle->sci->SCIRXBUF.bit.SAR;
            pHandle->cbReception(pHandle->pReceptionData, car);
        }
        else
        {
            pHandle->_RX_ERRORS++;
        }
    }

    pHandle->sci->SCIFFRX.bit.RXFFOVRCLR=1;   // Clear Overflow flag
    pHandle->sci->SCIFFRX.bit.RXFFINTCLR=1;   // Clear Interrupt flag

    PieCtrlRegs.PIEACK.all|=0x100;       // Issue PIE ACK
}

/**
 **********************************************************
 * \brief   The global Tx interrupt function
 *
 * \param [in]    uartNb  The SCI number
 *
 * \return
 **********************************************************/
static void sciGeneralTxIsr(drvSciNumber_t uartNb)
{
    UARTHandle_t *pHandle = &m_UARTList[uartNb];
    uint16_t car;

    if(pHandle->cbTransmission != NULL)
    {
        while(pHandle->sci->SCIFFTX.bit.TXFFST < 15)
        {
            //Send the first characters
            if(pHandle->cbTransmission(pHandle->pTransmitionData, &car))
            {
                    pHandle->sci->SCITXBUF.all = car;
            }
            else
            {
                //No more character to send
                pHandle->isBusy = false;
                pHandle->sci->SCIFFTX.bit.TXFFIENA = 0;
                break;
            }
        }

    }

    pHandle->sci->SCIFFTX.bit.TXFFINTCLR=1;   // Clear SCI Interrupt flag

    PieCtrlRegs.PIEACK.all|=0x100;       // Issue PIE ACK
}

/* Public functions ------------------------------------------------------------------------------------------------*/

/**
 *********************************************************
 * \brief The driver function to start the transmission process
 *
 * \param [in]    uartNb  The SCI number
 *
 * \return
 *********************************************************/
drvSciReturn_t DRV_SCI_StartTx(drvSciNumber_t uartNb)
{
    UARTHandle_t *pHandle = &m_UARTList[uartNb];
    uint16_t car;

    if(pHandle->isBusy)
    {
        return DRV_SCI_TX_BUSY;
    }

    if(pHandle->cbTransmission(pHandle->pTransmitionData, &car))
    {
        pHandle->sci->SCITXBUF.bit.TXDT = car;
        pHandle->sci->SCIFFTX.bit.TXFFIENA = 1;
        //TODO Send first character
        return DRV_SCI_SUCCESS;
    }


    return DRV_SCI_TX_ERROR;
}

/**
 *********************************************************
 * \brief The driver basic initialization function
 *        Only basics interrupt handler have to be provided
 * \warning GPIO pins must be configured before
 *
 * \param [in]  uartNb      The UART number
 * \param [in]  baudrate    The baudrate
 * \param [in]  databits    The data bit size
 * \param [in]  parity      The parity
 * \param [in]  stopBit     The number of stop bit
 * \param [in]  cbRxIsr     A pionter to a function called
 *                          in case of received character interrupt
 * \param [in]  cbTxIsr     A pionter to a function called
 *                          in case of received character interrupt
 *
 * \return  One of \ref drvSciReturn_t values
 *********************************************************/
drvSciReturn_t DRV_SCI_BasicInit(drvSciNumber_t uartNb,
                                 uint32_t baudrate,
                                 uint16_t databits,
                                 drvSciParity_t parity,
                                 drvSciStopBit_t stopBit,
                                 drvSciRxIsr_t cbRxIsr,
                                 drvSciTxIsr_t cbTxIsr)
{
    drvSciReturn_t ret = DRV_SCI_SUCCESS;
    UARTHandle_t* pHandle = &m_UARTList[uartNb];
    uint16_t rxIntVal, txIntVal;

    if(pHandle->initOk)
    {
        return DRV_SCI_ALREADY_INIT;
    }

    switch (uartNb)
    {
        case SCI_A:
#ifdef OS
            rxIntVal = EXTRACT_INT_NUMBER(INT_SCIRXINTA);
            txIntVal = EXTRACT_INT_NUMBER(INT_SCITXINTA);
#else
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.SCIA_RX_INT = cbRxIsr;
            PieVectTable.SCIA_TX_INT = cbTxIsr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
#endif
            break;
        case SCI_B:
#ifdef OS
            rxIntVal = EXTRACT_INT_NUMBER(INT_SCIRXINTB);
            txIntVal = EXTRACT_INT_NUMBER(INT_SCITXINTB);
#else
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.SCIB_RX_INT = cbRxIsr;
            PieVectTable.SCIB_TX_INT = cbTxIsr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
#endif
            break;
        case SCI_C:
#ifdef OS
            rxIntVal = EXTRACT_INT_NUMBER(INT_SCICRX);
            txIntVal = EXTRACT_INT_NUMBER(INT_SCICTX);
#else
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.SCIC_RX_INT = cbRxIsr;
            PieVectTable.SCIC_TX_INT = cbTxIsr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
#endif
            break;
        case SCI_D:
#ifdef OS
            rxIntVal = EXTRACT_INT_NUMBER(INT_SCIDRX);
            txIntVal = EXTRACT_INT_NUMBER(INT_SCIDTX);
#else
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.SCID_RX_INT = cbRxIsr;
            PieVectTable.SCID_TX_INT = cbTxIsr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
#endif
            break;
        default:
            return DRV_SCI_BAD_CONFIG;
    }

#ifdef OS
    Hwi_Params_init(&pHandle->hwiConf.rxHwiParams);
    pHandle->hwiConf.rxHwiParams.arg = NULL;
    pHandle->hwiConf.rxHwiHandle = Hwi_create(rxIntVal, (Hwi_FuncPtr)cbRxIsr, &pHandle->hwiConf.rxHwiParams, NULL);

    Hwi_Params_init(&pHandle->hwiConf.txHwiParams);
    pHandle->hwiConf.txHwiParams.arg = NULL;
    pHandle->hwiConf.txHwiHandle = Hwi_create(txIntVal, (Hwi_FuncPtr)cbTxIsr, &pHandle->hwiConf.txHwiParams, NULL);
#else

#endif

//    pHandle->sci->SCICCR.all = 0;

    /* Data size config */
    pHandle->sci->SCICCR.bit.SCICHAR = (databits - 1);

    pHandle->sci->SCICTL1.bit.SWRESET = 0;  //Set in reset state

    /* Parity Config */
    if (parity != DRV_SCI_PARITY_NONE)
    {
        pHandle->sci->SCICCR.bit.PARITYENA = 1;
        pHandle->sci->SCICCR.bit.PARITY = parity - 1;
    }

    /* Stop bit config */
    pHandle->sci->SCICCR.bit.STOPBITS = stopBit;

    /* Baud Rate config */
    setBaudRate(pHandle->sci, (drvSciSpeed_t)baudrate);

    pHandle->sci->SCICTL1.bit.RXENA = 1;
//    pHandle->sci->SCICTL2.bit.RXBKINTENA;
    pHandle->sci->SCICTL1.bit.TXENA = 1;

    pHandle->sci->SCICTL2.bit.TXINTENA = 1;
    pHandle->sci->SCICTL2.bit.RXBKINTENA = 1;

    pHandle->sci->SCIFFTX.all = 0xC000; //Disable Fifo Tx Interrupts
    pHandle->sci->SCIFFRX.all = 0x0021; //Enable Fifo Rx Interrupts
    pHandle->sci->SCIFFCT.all = 0x00;

    pHandle->sci->SCICTL1.bit.SWRESET = 1; //Release from reset state
    pHandle->sci->SCIFFTX.bit.TXFIFORESET = 1;
    pHandle->sci->SCIFFRX.bit.RXFIFORESET = 1;

    pHandle->initOk = true;
    return ret;

}

/**
 *********************************************************
 * \brief The driver initialization function
 * \warning GPIO pins must be configured before
 *
 * \param [in]  uartNb  The uart number
 * \param [in]  pConfig A pointer to a \ref drvSciConfig_t
 *                      structure initialized
 *
 * \return  One of \ref drvSciReturn_t values
 *********************************************************/
drvSciReturn_t DRV_SCI_Init(drvSciNumber_t uartNb, drvSciConfig_t *pConfig)
{
    drvSciReturn_t ret = DRV_SCI_SUCCESS;
    UARTHandle_t* pHandle = &m_UARTList[uartNb];

    if(pHandle->initOk)
    {
        return DRV_SCI_ALREADY_INIT;
    }


    if(pConfig == NULL)
    {
        //Error
        return DRV_SCI_BAD_CONFIG;
    }

//    pHandle->sci->SCIFFTX.all=0xE040;
//    pHandle->sci->SCIFFRX.all=0x204f;
//    pHandle->sci->SCIFFCT.all=0x0;
//
#ifdef OS
#warning "Do not use DRV_SCI_Init function for now"
#else
    switch (uartNb)
    {
        case SCI_A:
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.SCIA_RX_INT = &sciaRxIsr;
            PieVectTable.SCIA_TX_INT = &sciaTxIsr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
            break;
        case SCI_B:
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.SCIB_RX_INT = &scibRxIsr;
            PieVectTable.SCIB_TX_INT = &scibTxIsr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
            break;
        case SCI_C:
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.SCIC_RX_INT = &scicRxIsr;
            PieVectTable.SCIC_TX_INT = &scicTxIsr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
            break;
        case SCI_D:
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.SCID_RX_INT = &scidRxIsr;
            PieVectTable.SCID_TX_INT = &scidTxIsr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
            break;
        default:
            break;
    }

#endif
    pHandle->sci->SCICCR.all = 0;

    pHandle->cbReception = pConfig->cbReception;
    pHandle->pReceptionData = pConfig->pReceptionData;
    pHandle->cbTransmission = pConfig->cbTransmission;
    pHandle->pTransmitionData = pConfig->pTransmitionData;
    pHandle->cbEndOfTransmition = pConfig->cbEndOfTransmition;
    pHandle->pEndOfTransmitionArg = pConfig->pEndOfTransmitionArg;

    /* Data size config */
    pHandle->sci->SCICCR.bit.SCICHAR = pConfig->dataSize;

    pHandle->sci->SCICTL1.bit.SWRESET = 0;  //Set in reset state

    /* Parity Config */
    if (pConfig->parity != DRV_SCI_PARITY_NONE)
    {
        pHandle->sci->SCICCR.bit.PARITYENA = 1;
        pHandle->sci->SCICCR.bit.PARITY = pConfig->parity - 1;
    }

    /* Stop bit config */
    pHandle->sci->SCICCR.bit.STOPBITS = pConfig->stopBit;

    /* Baud Rate config */
    setBaudRate(pHandle->sci, pConfig->baudrate);

    pHandle->sci->SCICTL1.bit.RXENA = 1;
    pHandle->sci->SCICTL1.bit.TXENA = 1;

    pHandle->sci->SCICTL2.bit.TXINTENA = 0;
    pHandle->sci->SCICTL2.bit.RXBKINTENA = 0;

    pHandle->sci->SCIFFTX.all = 0xC01F;
    pHandle->sci->SCIFFRX.all = 0x0021;
    pHandle->sci->SCIFFCT.all = 0x00;

    pHandle->sci->SCICTL1.bit.SWRESET = 1; //Release from reset state
    pHandle->sci->SCIFFTX.bit.TXFIFORESET = 1;
    pHandle->sci->SCIFFRX.bit.RXFIFORESET = 1;

    pHandle->initOk = true;
    return ret;
}

/**
 **********************************************************
 * \brief   The non blocking function to write a char
 *
 * \param   [in]    uartNb  The uart number
 * \param   [in]    car     The car to write
 *
 * \return  One of \ref drvSciReturn_t values
 **********************************************************/
drvSciReturn_t DRV_SCI_WriteChar_NonBlocking(drvSciNumber_t uartNb, uint16_t car)
{
    drvSciReturn_t ret = DRV_SCI_TX_BUSY;

    if(m_UARTList[uartNb].sci->SCICTL2.bit.TXRDY)
    {
        m_UARTList[uartNb].sci->SCITXBUF.all = car;
        ret = DRV_SCI_NO_INPUT_CHAR;
    }

    return ret;
}

/**
 **********************************************************
 * \brief   The non blocking function to read a char
 *
 * \param   [in]    uartNb  The uart number
 * \param   [out]   pCar     The read character
 *
 * \return  One of \ref drvSciReturn_t values
 **********************************************************/
drvSciReturn_t DRV_SCI_ReadChar_NonBlocking(drvSciNumber_t uartNb, uint16_t* pCar)
{
    drvSciReturn_t ret = DRV_SCI_NO_INPUT_CHAR;

    if(m_UARTList[uartNb].sci->SCIFFRX.bit.RXFFST > 0)
    {
        *pCar = m_UARTList[uartNb].sci->SCIRXBUF.bit.SAR;
        ret = DRV_SCI_SUCCESS;
    }

    return ret;
}

/**
 **********************************************************
 * \brief   Enable receive process on a SCI
 *
 * \param   [in]    uartNb  The uart number
 * \param   [in]    enable  true to enable, false to disable
 **********************************************************/
void DRV_SCI_EnableRx(drvSciNumber_t uartNb, bool enable)
{
    m_UARTList[uartNb].sci->SCICTL1.bit.RXENA = enable;
}

/**
 **********************************************************
 * \brief   Enable transmit process on a SCI
 *
 * \param   [in]    uartNb  The uart number
 * \param   [in]    enable  true to enable, false to disable
 **********************************************************/
void DRV_SCI_EnableTx(drvSciNumber_t uartNb, bool enable)
{
    m_UARTList[uartNb].sci->SCICTL1.bit.TXENA = enable;
}

/**
 **********************************************************
 * \brief   Enable receive interrupt on a SCI
 *
 * \param   [in]    uartNb  The uart number
 * \param   [in]    enable  true to enable, false to disable
 **********************************************************/
void DRV_SCI_Enable_RxINT(drvSciNumber_t uartNb, bool enable)
{
    m_UARTList[uartNb].sci->SCIFFRX.bit.RXFFIENA = enable;
}

/**
 **********************************************************
 * \brief   Enable transmit interrupt on a SCI
 *
 * \param   [in]    uartNb  The uart number
 * \param   [in]    enable  true to enable, false to disable
 **********************************************************/
void DRV_SCI_Enable_TxINT(drvSciNumber_t uartNb, bool enable)
{
    m_UARTList[uartNb].sci->SCIFFTX.bit.TXFFIENA = enable;
}

/**
 **********************************************************
 * \brief   Clear pending receive interrupt
 *
 * \param   [in]    uartNb  The uart number
 **********************************************************/
void DRV_SCI_ClearIT_Rx(drvSciNumber_t uartNb)
{
    m_UARTList[uartNb].sci->SCIFFRX.bit.RXFFOVRCLR=1;   // Clear Overflow flag
    m_UARTList[uartNb].sci->SCIFFRX.bit.RXFFINTCLR=1;   // Clear Interrupt flag
#ifdef OS
#else
    PieCtrlRegs.PIEACK.all|=0x100;
#endif
}

/**
 **********************************************************
 * \brief   Clear pending transmit interrupt
 *
 * \param   [in]    uartNb  The uart number
 **********************************************************/
void DRV_SCI_ClearIT_Tx(drvSciNumber_t uartNb)
{
    m_UARTList[uartNb].sci->SCIFFTX.bit.TXFFINTCLR=1;
#ifdef OS
#else
    PieCtrlRegs.PIEACK.all|=0x100;
#endif

}

/** \} */
/******************************************************** EOF *******************************************************/

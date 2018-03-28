/****************************************************** COMECA *******************************************************
 *  \author		tedie.cedric
 *  \date		9 mars 2018
 *  \addtogroup	DRIVERS
 *  \{
 ********************************************************************************************************************/
/*********************************************************************************************************************
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

#include "F2837xD_device.h"

#include "drv_sci.h"

/* Macro definition ------------------------------------------------------------------------------------------------*/
/* Constant definition ---------------------------------------------------------------------------------------------*/
/* Type definition  ------------------------------------------------------------------------------------------------*/

/** The SCI Handle structure */
typedef struct
{
    volatile struct SCI_REGS *sci;

    drvSciReceiveCallback_t cbReception;
    void* pReceptionData;
    drvSciTransmitCallback_t cbTransmission;
    void* pTransmitionData;
    drvSciEndOfTransmitionCallback_t cbEndOfTransmition;
    void* pEndOfTransmitionArg;


    bool initOk;
    bool isBusy;
    uint32_t _RX_ERRORS;
    uint32_t _TX_ERRORS;
}UARTHandle_t;

/* Public variables ------------------------------------------------------------------------------------------------*/
/* Private variables -----------------------------------------------------------------------------------------------*/

UARTHandle_t m_UARTList[NB_SERIAL] =
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
interrupt void sciaRxIsr(void);
interrupt void sciaTxIsr(void);
interrupt void scibRxIsr(void);
interrupt void scibTxIsr(void);
interrupt void scicRxIsr(void);
interrupt void scicTxIsr(void);
/* Private functions -----------------------------------------------------------------------------------------------*/

/***********************************************************
 * \brief
 *
 * \param
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

/***********************************************************
 * \brief
 *
 * \param
 *
 * \return
 **********************************************************/
interrupt void sciaRxIsr(void)
{
    sciGeneralRxIsr(SCI_A);
}

/***********************************************************
 * \brief
 *
 * \param
 *
 * \return
 **********************************************************/
interrupt void sciaTxIsr(void)
{
    sciGeneralTxIsr(SCI_A);
}

/***********************************************************
 * \brief
 *
 * \param
 *
 * \return
 **********************************************************/
interrupt void scibRxIsr(void)
{
    sciGeneralRxIsr(SCI_B);
}

/***********************************************************
 * \brief
 *
 * \param
 *
 * \return
 **********************************************************/
interrupt void scibTxIsr(void)
{
    sciGeneralTxIsr(SCI_B);
}

/***********************************************************
 * \brief
 *
 * \param
 *
 * \return
 **********************************************************/
interrupt void scicRxIsr(void)
{
    sciGeneralRxIsr(SCI_C);
}

/***********************************************************
 * \brief
 *
 * \param
 *
 * \return
 **********************************************************/
interrupt void scicTxIsr(void)
{
    sciGeneralTxIsr(SCI_C);
}

/***********************************************************
 * \brief
 *
 * \param
 *
 * \return
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

/***********************************************************
 * \brief
 *
 * \param
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

/**********************************************************
 * \brief The driver function to start the transmission process
 *
 * \param [in]  uartNb
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

/**********************************************************
 * \brief The driver basic initialization function
 *        Only basics interrupt handler have to be provided
 * \warning GPIO pins must be configured before
 *
 * \param [in]  uartNb
 * \param [in]  pConfig
 *
 * \return
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

    if(pHandle->initOk)
    {
        return DRV_SCI_ALREADY_INIT;
    }


    switch (uartNb)
    {
        case SCI_A:
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.SCIA_RX_INT = cbRxIsr;
            PieVectTable.SCIA_TX_INT = cbTxIsr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
            break;
        case SCI_B:
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.SCIB_RX_INT = cbRxIsr;
            PieVectTable.SCIB_TX_INT = cbTxIsr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
            break;
        case SCI_C:
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.SCIC_RX_INT = cbRxIsr;
            PieVectTable.SCIC_TX_INT = cbTxIsr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
            break;
        default:
            break;
    }

    pHandle->sci->SCICCR.all = 0;

    /* Data size config */
    pHandle->sci->SCICCR.bit.SCICHAR = databits;

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

    pHandle->sci->SCIFFTX.all = 0xC000;
    pHandle->sci->SCIFFRX.all = 0x0021;
    pHandle->sci->SCIFFCT.all = 0x00;

    pHandle->sci->SCICTL1.bit.SWRESET = 1; //Release from reset state
    pHandle->sci->SCIFFTX.bit.TXFIFORESET = 1;
    pHandle->sci->SCIFFRX.bit.RXFIFORESET = 1;

    pHandle->initOk = true;
    return ret;

}

/**********************************************************
 * \brief The driver initialization function
 * \warning GPIO pins must be configured before
 *
 * \param [in]  uartNb
 * \param [in]  pConfig
 *
 * \return
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
        default:
            break;
    }


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
//    pHandle->sci->SCICTL2.bit.RXBKINTENA;
    pHandle->sci->SCICTL1.bit.TXENA = 1;

    pHandle->sci->SCICTL2.bit.TXINTENA = 1;
    pHandle->sci->SCICTL2.bit.RXBKINTENA = 1;

    pHandle->sci->SCIFFTX.all = 0xC01F;
    pHandle->sci->SCIFFRX.all = 0x0021;
    pHandle->sci->SCIFFCT.all = 0x00;

    pHandle->sci->SCICTL1.bit.SWRESET = 1; //Release from reset state
    pHandle->sci->SCIFFTX.bit.TXFIFORESET = 1;
    pHandle->sci->SCIFFRX.bit.RXFIFORESET = 1;

    pHandle->initOk = true;
    return ret;
}

/***********************************************************
 * \brief
 *
 * \param
 *
 * \return
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

/***********************************************************
 * \brief
 *
 * \param
 *
 * \return
 **********************************************************/
drvSciReturn_t DRV_SCI_ReadChar_NonBlocking(drvSciNumber_t uartNb, uint16_t* pCar)
{
    drvSciReturn_t ret = DRV_SCI_NO_INPUT_CHAR;

    if(m_UARTList[uartNb].sci->SCIRXST.bit.RXRDY)
    {
        *pCar = m_UARTList[uartNb].sci->SCIRXBUF.bit.SAR;
        ret = DRV_SCI_SUCCESS;
    }

    return ret;
}

/** \} */
/******************************************************** EOF *******************************************************/

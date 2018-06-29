/*********************************************************************************************************************
 *                                                      COMECA
 ********************************************************************************************************************/
/**
 ********************************************************************************************************************
 *  \author     tedie.cedric
 *  \date       12 mars 2018
 *  \addtogroup DRV_SPI
 *  \{
 ********************************************************************************************************************/
/**
 ********************************************************************************************************************
 *  \file       drv_spi.c
 *
 *  \brief      The SPI driver source file
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
//#undef OS
#include <ti/sysbios/family/c28/Hwi.h>
#include <ti/sysbios/knl/Swi.h>
#endif

#include "mapping.h"
#include "hw_ints.h"
#include "drv_utils.h"
#include "drv_gpio.h"
#include "drv_spi.h"
#include "drv_dma.h"

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

typedef enum
{
    CS_LOW = 0,
    CS_HIGH
}CS_State_t;

typedef struct
{
	volatile struct SPI_REGS *spiReg;
	drvGpioPin_t *cs_pin;
	bool autoChipSelect;

#ifdef OS
    HwiParams_t hwiConf;
#endif

	bool isInit;
    bool _useFifo;
    bool _useDMA;
	drvDmaChannelNumber_t _dmaCh;
    uint32_t _RX_ERRORS;
    uint32_t _TX_ERRORS;
}SPI_Handle_t;

static drvGpioPin_t m_spiPins[NB_SPI][4] =
{
     // {MOSI_PIN, MISO_PIN, CLK_PIN, CS_PIN }
     {SPIA_MOSI, SPIA_MISO, SPIA_CLK, SPIA_CS}, //SPIA
     {SPIB_MOSI, SPIB_MISO, SPIB_CLK, SPIB_CS},                  //SPIB
     {NULL, NULL, NULL, NULL}                   //SPIC
};
/* Public variables ------------------------------------------------------------------------------------------------*/
/* Private variables -----------------------------------------------------------------------------------------------*/

SPI_Handle_t m_spiHandle[NB_SPI] =
{
	{
		.spiReg = &SpiaRegs,
		.isInit = false,
		._useFifo = false
	},
	{
		.spiReg = &SpibRegs,
		.isInit = false,
        ._useFifo = false
	},
	{
		.spiReg = &SpicRegs,
		.isInit = false,
        ._useFifo = false
	}
};
/* Private functions prototypes ------------------------------------------------------------------------------------*/
drvSpiReturn_t SpiGpioInit(drvSpiNb_t spiNb);
drvSpiReturn_t SpiSpeedConfig(drvSpiNb_t spiNb, uint32_t speed);
static void spiGeneralRxIsr(drvSpiNb_t uartNb);
static void spiGeneralTxIsr(drvSpiNb_t uartNb);
#ifdef OS
#else
static void spiaRxIsr(void);
static void spiaTxIsr(void);
static void spibRxIsr(void);
static void spibTxIsr(void);
static void spicRxIsr(void);
static void spicTxIsr(void);
#endif /* OS */
/* Private functions -----------------------------------------------------------------------------------------------*/
/**
 **********************************************************
 * \brief   The drivers initialization function
 *
 * \param   [in]    spiNb       The spi number to configure
 *
 * \return  One of \ref drvSpiReturn_t values
 **********************************************************/
drvSpiReturn_t SpiGpioInit(drvSpiNb_t spiNb)
{
    uint16_t index;

    for (index = 0; index < 4; ++index)
    {
        DRV_GPIO_PinInit(&m_spiPins[spiNb][index]);
    }
    return DRV_SPI_SUCCESS;
}

/**
 **********************************************************
 * \brief   The speed configuration function
 *
 * \param   [in]    spiNb       The spi number to configure
 * \param   [in]    speed       The spi clock speed in Hz
 *
 * \return  One of \ref drvSpiReturn_t values
 **********************************************************/
drvSpiReturn_t SpiSpeedConfig(drvSpiNb_t spiNb, uint32_t speed)
{
    uint16_t brr_val;
    //TODO use CPU_FREQ instead of 200MHz

    if(ClkCfgRegs.LOSPCP.bit.LSPCLKDIV == 0)
    {
        //TODO
        return DRV_SPI_ERROR;
    }
    else
    {
        brr_val = (200000000 / ((ClkCfgRegs.LOSPCP.bit.LSPCLKDIV << 1) * speed)) - 1;
    }


    if(brr_val < 3)
    {
        //TODO
        // SPEED = LSPCLK/4
    }

    m_spiHandle[spiNb].spiReg->SPIBRR.bit.SPI_BIT_RATE = brr_val;

    return DRV_SPI_SUCCESS;
}

/**
 **********************************************************
 * \brief   Set the chip select
 *
 * \param   [in]    spiNb       The spi number to configure
 * \param   [in]    state       The CS state
 *
 * \return  One of \ref drvSpiReturn_t values
 **********************************************************/
drvSpiReturn_t SetCS(drvSpiNb_t spiNb, CS_State_t state)
{
    if(m_spiHandle[spiNb].autoChipSelect == false)
    {
        DRV_GPIO_PinSet(&m_spiPins[spiNb][3], (drvGpioPinState_t)state);
    }
}

/**
 **********************************************************
 * \brief The genreral interrupt handler.
 *        Each default handler call this function with
 *        their own SCI Number
 *
 * \param [in]    uartNb  The SCI number
 **********************************************************/
static void spiGeneralRxIsr(drvSpiNb_t uartNb)
{

}

/**
 **********************************************************
 * \brief   The global Tx interrupt function
 *
 * \param [in]    uartNb  The SCI number
 *
 * \return
 **********************************************************/
static void spiGeneralTxIsr(drvSpiNb_t uartNb)
{

}


/* Public functions ------------------------------------------------------------------------------------------------*/
/**
 **********************************************************
 * \brief   The drivers initialization function
 *
 * \param   [in]    spiNb       The spi number to configure
 * \param   [in]    pConfig     A pointer to a predefined
 *                              configuration structure
 *
 * \return  One of \ref drvSpiReturn_t values
 **********************************************************/
drvSpiReturn_t DRV_SPI_Init(drvSpiNb_t spiNb, drvSpiConfig_t *pConfig)
{
    drvSpiReturn_t ret = DRV_SPI_SUCCESS;
	SPI_Handle_t *pSpiHdl = &m_spiHandle[spiNb];

	SpiGpioInit(spiNb);
	pSpiHdl->cs_pin = &m_spiPins[spiNb][3];


    /* Put SPI in reset */
    pSpiHdl->spiReg->SPICCR.bit.SPISWRESET = 0;

    //configure speed
    SpiSpeedConfig(spiNb, (uint32_t)pConfig->speed);


    pSpiHdl->spiReg->SPICCR.bit.HS_MODE = 1;

	//configure Word Length
    pSpiHdl->spiReg->SPICCR.bit.SPICHAR = pConfig->wordLength;

    pSpiHdl->spiReg->SPICTL.bit.MASTER_SLAVE = pConfig->mode;

	//Configure Clock mode
    switch(pConfig->clkMode)
    {
        case SPI_MODE0_CPOL0_CPHA0:
            pSpiHdl->spiReg->SPICCR.bit.CLKPOLARITY = 0;
            pSpiHdl->spiReg->SPICTL.bit.CLK_PHASE = 0;
            break;
        case SPI_MODE1_CPOL0_CPHA1:
            pSpiHdl->spiReg->SPICCR.bit.CLKPOLARITY = 0;
            pSpiHdl->spiReg->SPICTL.bit.CLK_PHASE = 1;
            break;
        case SPI_MODE2_CPOL1_CPHA0:
            pSpiHdl->spiReg->SPICCR.bit.CLKPOLARITY = 1;
            pSpiHdl->spiReg->SPICTL.bit.CLK_PHASE = 0;
            break;
        case SPI_MODE3_CPOL1_CPHA1:
            pSpiHdl->spiReg->SPICCR.bit.CLKPOLARITY = 1;
            pSpiHdl->spiReg->SPICTL.bit.CLK_PHASE = 1;
            break;
        default:
            break;
    }

    pSpiHdl->spiReg->SPIPRI.bit.STEINV = 1;
    pSpiHdl->spiReg->SPISTS.bit.OVERRUN_FLAG = 1;

    pSpiHdl->spiReg->SPICTL.bit.TALK = 1;


    /* Configure interrupts and callbacks */
    //TODO

    /* Release from reset */
    pSpiHdl->spiReg->SPICCR.bit.SPISWRESET = 1;


	pSpiHdl->isInit = true;

	return ret;
}

/**
 **********************************************************
 * \brief   Configure the SPI FIFO
 *
 * \param   [in]    spiNb       The spi number to use
 * \param   [in]    pConf       A pointer to fifo configuration structure
 *
 * \return  One of \ref drvSpiReturn_t values
 **********************************************************/
drvSpiReturn_t DRV_SPI_FifoConfig(drvSpiNb_t spiNb, drvSpiFifoConf_t *pConf)
{
    drvSpiReturn_t ret = DRV_SPI_SUCCESS;
    SPI_Handle_t *pHandle = &m_spiHandle[spiNb];
    uint16_t rxIntNum, txIntNum;

//#ifdef OS
//
//    switch (spiNb)
//    {
//        case SPI_A:
//            rxIntNum = EXTRACT_INT_NUMBER(INT_SPIRXINTA);
//            txIntNum = EXTRACT_INT_NUMBER(INT_SPITXINTA);
//
//            break;
//        case SPI_B:
//            rxIntNum = EXTRACT_INT_NUMBER(INT_SPIRXINTB);
//            txIntNum = EXTRACT_INT_NUMBER(INT_SPITXINTB);
//
//            break;
//        case SPI_C:
//            rxIntNum = EXTRACT_INT_NUMBER(INT_SPIRXINTC);
//            txIntNum = EXTRACT_INT_NUMBER(INT_SPITXINTC);
//
//            break;
//        default:
//            return DRV_SPI_BAD_CONFIG;
//    }
//
//
//#endif
//
//#ifdef OS
//    Hwi_Params_init(&pHandle->hwiConf.rxHwiParams);
//    pHandle->hwiConf.rxHwiParams.arg = pConf->pRxCallbackData;
//    pHandle->hwiConf.rxHwiHandle = Hwi_create(rxIntNum, (Hwi_FuncPtr)pConf->rxCallback, &pHandle->hwiConf.rxHwiParams, NULL);
//    if(pHandle->hwiConf.rxHwiHandle == NULL)
//    {
//        return DRV_SPI_BAD_CONFIG;
//    }
//
//    Hwi_Params_init(&pHandle->hwiConf.txHwiParams);
//    pHandle->hwiConf.txHwiParams.arg = pConf->pTxCallbackData;
//    pHandle->hwiConf.txHwiHandle = Hwi_create(txIntNum, (Hwi_FuncPtr)pConf->txCallbabk, &pHandle->hwiConf.txHwiParams, NULL);
//    if(pHandle->hwiConf.txHwiHandle == NULL)
//    {
//        return DRV_SPI_BAD_CONFIG;
//    }
//#else
//#endif

    pHandle->spiReg->SPIFFRX.all = 0x2040;             // RX FIFO enabled, clear FIFO int
    pHandle->spiReg->SPIFFRX.bit.RXFFIENA = 0;      //No interrupt
    pHandle->spiReg->SPIFFRX.bit.RXFFIL = pConf->rxIntLevel;  // Set RX FIFO level

    pHandle->spiReg->SPIFFTX.all=0xE040;             // FIFOs enabled, TX FIFO released,
    pHandle->spiReg->SPIFFTX.bit.TXFFIL = pConf->txIntLevel;  // Set TX FIFO level
    pHandle->spiReg->SPIFFCT.bit.TXDLY =pConf->txDelay;




    pHandle->_useFifo = true;

    return ret;
}

/**
 **********************************************************
 * \brief   Configure the SPI DMA
 *
 * \param   [in]    spiNb       The spi number to use
 * \param   [in]    pConf       A pointer to DMA configuration structure
 *
 * \return  One of \ref drvSpiReturn_t values
 **********************************************************/
drvSpiReturn_t DRV_SPI_DMAConfig(drvSpiNb_t spiNb, drvDmaChannelNumber_t dmaCh, drvSpiDmaConf_t *pConf)
{
    drvSpiReturn_t ret = DRV_SPI_SUCCESS;

    SPI_Handle_t *pSpiHdl = &m_spiHandle[spiNb];

    if(DRV_DMA_Init(dmaCh, pConf->pDMAConfig) != DRV_DMA_SUCCESS)
    {
        return DRV_SPI_ERROR;
    }

    pSpiHdl->_dmaCh = dmaCh;
    pSpiHdl->spiReg->SPIFFRX.all = 0x2040;             // RX FIFO enabled, clear FIFO int
    pSpiHdl->spiReg->SPIFFRX.bit.RXFFIENA = 0;      //No interrupt
    pSpiHdl->spiReg->SPIFFRX.bit.RXFFIL = pConf->pFifoConfig->rxIntLevel;  // Set RX FIFO level

    pSpiHdl->spiReg->SPIFFTX.all=0xE040;             // FIFOs enabled, TX FIFO released,
    pSpiHdl->spiReg->SPIFFTX.bit.TXFFIL = pConf->pFifoConfig->txIntLevel;  // Set TX FIFO level
    pSpiHdl->spiReg->SPIFFCT.bit.TXDLY =pConf->pFifoConfig->txDelay;
    pSpiHdl->_useFifo = true;
    pSpiHdl->_useDMA = true;

    return ret;
}

/**
 **********************************************************
 * \brief   Write data to SPI
 *
 * \param   [in]    spiNb       The spi number to use
 * \param   [in]    pDataTx     A pointer to the data to transmit
 * \param   [in]    size        The number of data to transmit
 *
 * \return  One of \ref drvSpiReturn_t values
 **********************************************************/
drvSpiReturn_t DRV_SPI_Write(drvSpiNb_t spiNb, void *pDataTx, uint16_t size)
{
    drvSpiReturn_t ret = DRV_SPI_SUCCESS;
    uint16_t *data = (uint16_t*)pDataTx;
    SetCS(spiNb, CS_LOW);
    m_spiHandle[spiNb].spiReg->SPIDAT = *data;
    SetCS(spiNb, CS_HIGH);

    return ret;
}

/**
 **********************************************************
 * \brief   Read data from SPI
 *
 * \param   [in]    spiNb       The spi number to use
 * \param   [out]   pDataRx     A pointer to store the received data
 * \param   [in]    size        The number of data to receive (received data)
 *
 * \return  One of \ref drvSpiReturn_t values
 **********************************************************/
drvSpiReturn_t DRV_SPI_Read(drvSpiNb_t spiNb, void *pDataRx, uint16_t size)
{
    drvSpiReturn_t ret = DRV_SPI_SUCCESS;
    uint16_t *data = (uint16_t*)pDataRx;
    uint16_t dummy = 0x55AA;

    m_spiHandle[spiNb].spiReg->SPIDAT = dummy;

//    m_spiHandle[spiNb].spiReg->
    while (m_spiHandle[spiNb].spiReg->SPISTS.bit.INT_FLAG == 0)
    {

    }

    *data = m_spiHandle[spiNb].spiReg->SPIRXBUF;

    return ret;
}

/**
 **********************************************************
 * \brief   Simultaneous Read and Wrte on the SPI bus
 *
 * \param   [in]    spiNb       The spi number to use
 * \param   [in]    pDataTx     A pointer to the data to transmit
 * \param   [out]   pDataRx     A pointer to store the received data
 * \param   [in]    size        The number of data to transmit
 *
 * \return  One of \ref drvSpiReturn_t values
 **********************************************************/
drvSpiReturn_t DRV_SPI_ReadWrite(drvSpiNb_t spiNb, void *pDataTx, void *pDataRx, uint16_t size)
{
    drvSpiReturn_t ret = DRV_SPI_SUCCESS;

    uint16_t *txData = (uint16_t*)pDataTx;
    uint16_t *rxData = (uint16_t*)pDataRx;

    m_spiHandle[spiNb].spiReg->SPITXBUF = *txData;

    while (m_spiHandle[spiNb].spiReg->SPISTS.bit.INT_FLAG == 0)
    {

    }

    *rxData = m_spiHandle[spiNb].spiReg->SPIRXBUF;

    return ret;
}

/** \} */
/******************************************************** EOF *******************************************************/

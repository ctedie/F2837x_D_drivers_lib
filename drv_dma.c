/*********************************************************************************************************************
 *                                                      COMECA
 ********************************************************************************************************************/
/**
 *********************************************************************************************************************
 *  \author		tedie.cedric
 *  \date		17 mai 2018
 *  \addtogroup	DRV_DMA
 *  \{
 ********************************************************************************************************************/
/**
 *********************************************************************************************************************
 *  \file		drv_dma.c
 *  
 *  \brief		The DMA driver source file
 *
 *  \details	
 *
 ********************************************************************************************************************/

/* Includes --------------------------------------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>

#include "F28x_Project.h"

#ifdef OS
#include <ti/sysbios/family/c28/Hwi.h>
#include <ti/sysbios/knl/Swi.h>
#endif

#include "hw_ints.h"
#include "drv_utils.h"
#include "drv_dma.h"

/* Macro definition ------------------------------------------------------------------------------------------------*/
/* Constant definition ---------------------------------------------------------------------------------------------*/
/* Type definition  ------------------------------------------------------------------------------------------------*/
#ifdef OS
/** The local hwi paramters structure */
typedef struct
{
    Hwi_Handle dmaHwiHandle;
    Hwi_Params dmaHwiParams;
}HwiParams_t;
#endif

typedef struct
{
    volatile struct CH_REGS *channel;

    drvDmaEOTCallback_t EOTCallback;
    void *pCallbackData;
#ifdef OS
    HwiParams_t hwiConf;
#endif

    uint16_t intSrc;
    bool is32bits;
    uint16_t size;

    bool isInit;
}DMAChannel_t;


/* Public variables ------------------------------------------------------------------------------------------------*/
/* Private variables -----------------------------------------------------------------------------------------------*/
static DMAChannel_t m_dmaChannel[DRV_DMA_NB_CHANNELS] =
{
 {
  .channel = &DmaRegs.CH1,
  .isInit = false
 },
 {
  .channel = &DmaRegs.CH2,
  .isInit = false
 },
 {
  .channel = &DmaRegs.CH3,
  .isInit = false
 },
 {
  .channel = &DmaRegs.CH4,
  .isInit = false
 },
 {
  .channel = &DmaRegs.CH5,
  .isInit = false
 },
 {
  .channel = &DmaRegs.CH6,
  .isInit = false
 }
};


/* Private functions prototypes ------------------------------------------------------------------------------------*/
static void generalIT(drvDmaChannelNumber_t dmaNb);

#ifdef OS
#else
__interrupt static void channel1IT(void);
__interrupt static void channel2IT(void);
__interrupt static void channel3IT(void);
__interrupt static void channel4IT(void);
__interrupt static void channel5IT(void);
__interrupt static void channel6IT(void);
#endif

/* Private functions -----------------------------------------------------------------------------------------------*/
#ifdef OS
#else

/**
 *********************************************************
 * \brief The Channel 1 interrupt handler
 *********************************************************/
__interrupt static void channel1IT(void)
{
    generalIT(DRV_DMA_CHANNEL1);
}

/**
 *********************************************************
 * \brief The Channel 2 interrupt handler
 *********************************************************/
__interrupt static void channel2IT(void)
{
    generalIT(DRV_DMA_CHANNEL2);
}

/**
 *********************************************************
 * \brief The Channel 3 interrupt handler
 *********************************************************/
__interrupt static void channel3IT(void)
{
    generalIT(DRV_DMA_CHANNEL3);
}

/**
 *********************************************************
 * \brief The Channel 4 interrupt handler
 *********************************************************/
__interrupt static void channel4IT(void)
{
    generalIT(DRV_DMA_CHANNEL4);
}

/**
 *********************************************************
 * \brief The Channel 5 interrupt handler
 *********************************************************/
__interrupt static void channel5IT(void)
{
    generalIT(DRV_DMA_CHANNEL5);
}

/**
 *********************************************************
 * \brief The Channel 6 interrupt handler
 *********************************************************/
__interrupt static void channel6IT(void)
{
    generalIT(DRV_DMA_CHANNEL6);
}
#endif


static void generalIT(drvDmaChannelNumber_t dmaNb)
{
    if(m_dmaChannel[dmaNb].EOTCallback != NULL)
    {
        m_dmaChannel[dmaNb].EOTCallback(m_dmaChannel[dmaNb].pCallbackData);
    }
#ifdef OS
#else
    PieCtrlRegs.PIEACK.bit.ACK7 = 1;
#endif
}

/* Public functions ------------------------------------------------------------------------------------------------*/

/**
 *********************************************************
 * \brief 
 *
 * \param [in]      chNb
 * \param [in]      pConfig
 *
 * \return
 *********************************************************/
drvDmaReturn_t DRV_DMA_Init(drvDmaChannelNumber_t chNb, drvDmaChannelConfig_t *pConfig)
{
    DMAChannel_t *pHandle;
    uint16_t dmaIntNum;

    if(chNb >= DRV_DMA_NB_CHANNELS)
    {
        return DRV_DMA_BAD_CONFIG;
    }

    pHandle = &m_dmaChannel[chNb];



    pHandle->EOTCallback = pConfig->callback;
    pHandle->pCallbackData = pConfig->pCallbackData;
    pHandle->intSrc = pConfig->dmaIntSrc;
    pHandle->size = pConfig->transferSize;

    // DMA initialization
    DMAInitialize();

#ifdef OS
    Hwi_Params_init(&pHandle->hwiConf.dmaHwiParams);
#endif
EALLOW;
    switch(chNb)
    {
        case DRV_DMA_CHANNEL1:
#ifdef OS
            dmaIntNum = EXTRACT_INT_NUMBER(INT_DMA1INT);
            pHandle->hwiConf.dmaHwiParams.arg = DRV_DMA_CHANNEL1;

#else
            PieVectTable.DMA_CH1_INT= &channel1IT;
            PieCtrlRegs.PIEIER7.bit.INTx1 = 1;
#endif
            DmaClaSrcSelRegs.DMACHSRCSEL1.bit.CH1 = pHandle->intSrc;
            break;
        case DRV_DMA_CHANNEL2:
#ifdef OS
            dmaIntNum = EXTRACT_INT_NUMBER(INT_DMA2INT);
            pHandle->hwiConf.dmaHwiParams.arg = DRV_DMA_CHANNEL2;
#else
            PieVectTable.DMA_CH2_INT= &channel2IT;
            PieCtrlRegs.PIEIER7.bit.INTx2 = 1;
#endif
            DmaClaSrcSelRegs.DMACHSRCSEL1.bit.CH2 = pHandle->intSrc;
            break;
        case DRV_DMA_CHANNEL3:
#ifdef OS
            dmaIntNum = EXTRACT_INT_NUMBER(INT_DMA3INT);
            pHandle->hwiConf.dmaHwiParams.arg = DRV_DMA_CHANNEL3;
#else
            PieVectTable.DMA_CH3_INT= &channel3IT;
            PieCtrlRegs.PIEIER7.bit.INTx3 = 1;
#endif
            DmaClaSrcSelRegs.DMACHSRCSEL1.bit.CH3 = pHandle->intSrc;
            break;
        case DRV_DMA_CHANNEL4:
#ifdef OS
            dmaIntNum = EXTRACT_INT_NUMBER(INT_DMA4INT);
            pHandle->hwiConf.dmaHwiParams.arg = DRV_DMA_CHANNEL4;
#else
            PieVectTable.DMA_CH4_INT= &channel4IT;
            PieCtrlRegs.PIEIER7.bit.INTx4 = 1;
#endif
            DmaClaSrcSelRegs.DMACHSRCSEL1.bit.CH4 = pHandle->intSrc;
            break;
        case DRV_DMA_CHANNEL5:
#ifdef OS
            dmaIntNum = EXTRACT_INT_NUMBER(INT_DMA5INT);
            pHandle->hwiConf.dmaHwiParams.arg = DRV_DMA_CHANNEL5;
#else
            PieVectTable.DMA_CH5_INT= &channel5IT;
            PieCtrlRegs.PIEIER7.bit.INTx5 = 1;
#endif
            DmaClaSrcSelRegs.DMACHSRCSEL2.bit.CH5 = pHandle->intSrc;
            break;
        case DRV_DMA_CHANNEL6:
#ifdef OS
            dmaIntNum = EXTRACT_INT_NUMBER(INT_DMA6INT);
            pHandle->hwiConf.dmaHwiParams.arg = DRV_DMA_CHANNEL6;
#else
            PieVectTable.DMA_CH6_INT= &channel6IT;
            PieCtrlRegs.PIEIER7.bit.INTx6 = 1;
#endif
            DmaClaSrcSelRegs.DMACHSRCSEL2.bit.CH6 = pHandle->intSrc;
            break;
    }
    EDIS;

#ifdef OS
    pHandle->hwiConf.dmaHwiHandle = Hwi_create(dmaIntNum, (Hwi_FuncPtr)generalIT, &pHandle->hwiConf.dmaHwiParams, NULL);
    if(pHandle->hwiConf.dmaHwiHandle == NULL)
    {
        return DRV_DMA_BAD_CONFIG;
    }

#endif

    EALLOW;
    pHandle->channel->SRC_BEG_ADDR_SHADOW = (uint32_t)pConfig->pSrc;
    pHandle->channel->SRC_ADDR_SHADOW = (uint32_t)pConfig->pSrc;

    pHandle->channel->DST_BEG_ADDR_SHADOW = (uint32_t)pConfig->pDest;
    pHandle->channel->DST_ADDR_SHADOW = (uint32_t)pConfig->pDest;

    pHandle->channel->BURST_SIZE.all = pConfig->burstSize-1;
    pHandle->channel->SRC_BURST_STEP = pConfig->srcBurstStep;
    pHandle->channel->DST_BURST_STEP = pConfig->dstBurstStep;

    pHandle->channel->TRANSFER_SIZE = pHandle->size - 1;
    pHandle->channel->SRC_TRANSFER_STEP = pConfig->srcTransferStep;
    pHandle->channel->DST_TRANSFER_STEP = pConfig->dstTransferStep;


    pHandle->channel->MODE.bit.PERINTSEL = chNb+1;
    pHandle->channel->MODE.bit.PERINTE = 1;
    pHandle->channel->MODE.bit.ONESHOT = pConfig->oneShotMode;
    pHandle->channel->MODE.bit.CONTINUOUS = pConfig->continuousTransfer;
    pHandle->channel->MODE.bit.OVRINTE = OVRFLOW_DISABLE;
    pHandle->channel->MODE.bit.DATASIZE = SIXTEEN_BIT;
    pHandle->channel->MODE.bit.CHINTMODE = CHINT_END;
    pHandle->channel->MODE.bit.CHINTE = CHINT_ENABLE;

    pHandle->channel->CONTROL.bit.PERINTCLR = 1;
    pHandle->channel->CONTROL.bit.ERRCLR = 1;

    EDIS;

    EALLOW;
    CpuSysRegs.SECMSEL.bit.PF2SEL = 1;
    EDIS;

    pHandle->isInit = true;

    return DRV_DMA_SUCCESS;
}

/**
 *********************************************************
 * \brief
 *
 * \param [in]      chNb
 *
 * \return
 *********************************************************/
void DRV_DMA_Start(drvDmaChannelNumber_t chNb)
{
    if(m_dmaChannel[chNb].isInit)
    {
        EALLOW;
        m_dmaChannel[chNb].channel->CONTROL.bit.RUN = 1;
        EDIS;
    }
}

/**
 *********************************************************
 * \brief
 *
 * \param [in]      chNb
 *
 * \return
 *********************************************************/
void DRV_DMA_Force(drvDmaChannelNumber_t chNb)
{
    if(m_dmaChannel[chNb].isInit)
    {
        EALLOW;
        m_dmaChannel[chNb].channel->CONTROL.bit.PERINTFRC = 1;
        EDIS;
    }
}

/**
 *********************************************************
 * \brief
 *
 * \param [in]      chNb
 *
 * \return
 *********************************************************/
void DRV_DMA_ClearIT(drvDmaChannelNumber_t chNb)
{
    if(m_dmaChannel[chNb].isInit)
    {
        EALLOW;
        m_dmaChannel[chNb].channel->CONTROL.bit.PERINTCLR = 1;
        EDIS;
    }
}

/**
 *********************************************************
 * \brief
 *
 * \param [in]      chNb
 *
 * \return
 *********************************************************/
void DRV_DMA_Stop(drvDmaChannelNumber_t chNb)
{
    if(m_dmaChannel[chNb].isInit)
    {
        EALLOW;
        m_dmaChannel[chNb].channel->CONTROL.bit.HALT = 1;
        EDIS;
    }
}

/** \} */
/******************************************************** EOF *******************************************************/

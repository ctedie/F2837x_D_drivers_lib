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

#include "hw_ints.h"
#include "drv_utils.h"
#include "drv_dma.h"

/* Macro definition ------------------------------------------------------------------------------------------------*/
/* Constant definition ---------------------------------------------------------------------------------------------*/
/* Type definition  ------------------------------------------------------------------------------------------------*/
typedef struct
{
    struct CH_REGS *channel;

    drvDmaEOTCallback_t EOTCallback;
    void *pCallbackData;

    uint16_t intSrc;
    void *src;
    void *dest;
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
__interrupt static void generalInterrupt(void);
static void generalIT(drvDmaChannelNumber_t dmaNb);

__interrupt static void channel1IT(void);
__interrupt static void channel2IT(void);
__interrupt static void channel3IT(void);
__interrupt static void channel4IT(void);
__interrupt static void channel5IT(void);
__interrupt static void channel6IT(void);
/* Private functions -----------------------------------------------------------------------------------------------*/

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

static void generalIT(drvDmaChannelNumber_t dmaNb)
{
    if(m_dmaChannel[dmaNb].EOTCallback != NULL)
    {
        m_dmaChannel[dmaNb].EOTCallback(m_dmaChannel[dmaNb].pCallbackData);
    }

    PieCtrlRegs.PIEACK.bit.ACK7 = 1;
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

    if(chNb >= DRV_DMA_NB_CHANNELS)
    {
        return DRV_DMA_BAD_CONFIG;
    }

    pHandle = &m_dmaChannel[chNb];

    EALLOW;
    switch(chNb)
    {
        case DRV_DMA_CHANNEL1:
            PieVectTable.DMA_CH1_INT= &channel1IT;
            break;
        case DRV_DMA_CHANNEL2:
            PieVectTable.DMA_CH2_INT= &channel2IT;
            break;
        case DRV_DMA_CHANNEL3:
            PieVectTable.DMA_CH3_INT= &channel3IT;
            break;
        case DRV_DMA_CHANNEL4:
            PieVectTable.DMA_CH4_INT= &channel4IT;
            break;
        case DRV_DMA_CHANNEL5:
            PieVectTable.DMA_CH5_INT= &channel5IT;
            break;
        case DRV_DMA_CHANNEL6:
            PieVectTable.DMA_CH6_INT= &channel6IT;
            break;
    }
    EDIS;


    pHandle->EOTCallback = pConfig->callback;
    pHandle->pCallbackData = pConfig->pCallbackData;

    EALLOW;
    // DMA initialization
    DMAInitialize();
    pHandle->channel->SRC_BEG_ADDR_SHADOW = (uint32_t)&pHandle->src;
    pHandle->channel->SRC_ADDR_SHADOW = (uint32_t)&pHandle->src;

    pHandle->channel->DST_BEG_ADDR_SHADOW = (uint32_t)&pHandle->dest;
    pHandle->channel->DST_ADDR_SHADOW = (uint32_t)&pHandle->dest;

    pHandle->channel->BURST_SIZE.all = 1;
    pHandle->channel->SRC_BURST_STEP = 1;
    pHandle->channel->DST_BURST_STEP = 0;

    pHandle->channel->TRANSFER_SIZE = pHandle->size;
    pHandle->channel->SRC_TRANSFER_STEP = 1;
    pHandle->channel->DST_TRANSFER_STEP = 0;

    //TODO SOURCE SEL
    /* For test only CH1 */
    DmaClaSrcSelRegs.DMACHSRCSEL1.bit.CH1 = pHandle->intSrc;
    pHandle->channel->MODE.bit.PERINTSEL = chNb+1;
    pHandle->channel->MODE.bit.PERINTE = 1;
    pHandle->channel->MODE.bit.ONESHOT = ONESHOT_DISABLE;
    pHandle->channel->MODE.bit.CONTINUOUS = CONT_DISABLE;
    pHandle->channel->MODE.bit.OVRINTE = OVRFLOW_DISABLE;
    pHandle->channel->MODE.bit.DATASIZE = SIXTEEN_BIT;
    pHandle->channel->MODE.bit.CHINTMODE = CHINT_END;
    pHandle->channel->MODE.bit.CHINTE = CHINT_ENABLE;

    pHandle->channel->CONTROL.bit.PERINTCLR = 1;
    pHandle->channel->CONTROL.bit.ERRCLR = 1;

    switch(chNb)
    {
        case DRV_DMA_CHANNEL1:
            PieCtrlRegs.PIEIER7.bit.INTx1 = 1;
            break;
        case DRV_DMA_CHANNEL2:
            PieCtrlRegs.PIEIER7.bit.INTx2 = 1;
            break;
        case DRV_DMA_CHANNEL3:
            PieCtrlRegs.PIEIER7.bit.INTx3 = 1;
            break;
        case DRV_DMA_CHANNEL4:
            PieCtrlRegs.PIEIER7.bit.INTx4 = 1;
            break;
        case DRV_DMA_CHANNEL5:
            PieCtrlRegs.PIEIER7.bit.INTx5 = 1;
            break;
        case DRV_DMA_CHANNEL6:
            PieCtrlRegs.PIEIER7.bit.INTx6 = 1;
            break;
    }

    EDIS;

}

/** \} */
/******************************************************** EOF *******************************************************/

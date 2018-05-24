/*********************************************************************************************************************
 *                                                      COMECA
 ********************************************************************************************************************/
/**
 *********************************************************************************************************************
 *  \author		tedie.cedric
 *  \date		17 mai 2018
 *
 *  \addtogroup	DRIVERS
 *  \{
 *  \addtogroup	DRV_DMA
 *  \{
 *  
 *  \brief A drivers to use DMA "capabilities'
 *  
 *  \details 
 ********************************************************************************************************************/
/**
 *********************************************************************************************************************
 *  \file		drv_dma.h
 *  
 *  \brief		TODO
 *
 *  \details	
 *
 ********************************************************************************************************************/
#ifndef DRV_DMA_H_
#define DRV_DMA_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes --------------------------------------------------------------------------------------------------------*/
#include <stdint.h>
#include "F28x_Project.h"
/* Public Macro definition -----------------------------------------------------------------------------------------*/
/* Public Constant definition --------------------------------------------------------------------------------------*/
/* Public Type definition  -----------------------------------------------------------------------------------------*/

typedef void (*drvDmaEOTCallback_t)(void* pData);

/** Return type enum */
typedef enum
{
    DRV_DMA_SUCCESS = 0,
    DRV_DMA_ERROR,
    DRV_DMA_NOT_INIT,
    DRV_DMA_BAD_CONFIG,
    DRV_DMA_ALREADY_INIT
}drvDmaReturn_t;

typedef enum
{
    DRV_DMA_CHANNEL1 = 0,
    DRV_DMA_CHANNEL2,
    DRV_DMA_CHANNEL3,
    DRV_DMA_CHANNEL4,
    DRV_DMA_CHANNEL5,
    DRV_DMA_CHANNEL6,

    DRV_DMA_NB_CHANNELS
}drvDmaChannelNumber_t;

typedef struct
{
    uint16_t transferSize;
    uint16_t burstSize;
    uint16_t *src;
    uint16_t *dest;
    drvDmaEOTCallback_t callback;
    void* pCallbackData;

    uint16_t dmaIntSrc;

}drvDmaChannelConfig_t;

/* Public variables ------------------------------------------------------------------------------------------------*/
/* Public functions ------------------------------------------------------------------------------------------------*/
drvDmaReturn_t DRV_DMA_Init(drvDmaChannelNumber_t chNb, drvDmaChannelConfig_t *pConfig);
void DRV_DMA_Start(drvDmaChannelNumber_t chNb);
void DRV_DMA_Stop(drvDmaChannelNumber_t chNb);
void DRV_DMA_Force(drvDmaChannelNumber_t chNb);
void DRV_DMA_ClearIT(drvDmaChannelNumber_t chNb);

#endif /* DRV_DMA_H_ */

#ifdef __cplusplus
}
#endif

/** \} */
/** \} */
/******************************************************** EOF *******************************************************/

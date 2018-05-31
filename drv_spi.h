/*********************************************************************************************************************
 *                                                      COMECA
 ********************************************************************************************************************/
/**
 ********************************************************************************************************************
 *  \author     tedie.cedric
 *  \date       9 mars 2018
 *  \addtogroup DRIVERS
 *  \{
 *  \addtogroup DRV_SPI
 *  \{
 *
 *  \brief This module contains SPI API functions
 *
 *  \details
 ********************************************************************************************************************/
/**
 ********************************************************************************************************************
 *  \file       drv_spi.h
 *
 *  \brief      The SPI driver header file
 *
 *  \details
 *
 *********************************************************************************************************************/

#ifndef DRV_SPI_H_
#define DRV_SPI_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes --------------------------------------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "F2837xD_device.h"

/* Public Macro definition -----------------------------------------------------------------------------------------*/
/* Public Constant definition --------------------------------------------------------------------------------------*/
/* Public Type definition  -----------------------------------------------------------------------------------------*/
/**
 *********************************************************
 * \brief The receive callback type
 *
 * \details The purpose of this function is to get the
 *          char to received on SPI. \n
 *          This callback is called as long as the
 *          receive fifo is not full
 *
 * \param [in]  pData    A pointer to user defined arg
 * \param [in]  car      The read character
 *********************************************************/
typedef void (*drvSpiReceiveCallback_t)(uintptr_t pData);

/**
 *********************************************************
 * \brief The transmit callback type
 *
 * \details The purpose of this function is to get the
 *          char to send via SPI. \n
 *          This callback is called when there is
 *          space in the transmit fifo
 *
 * \param [in]  pData    A pointer to user defined arg
 * \param [out] car      The read character
 *********************************************************/
typedef bool (*drvSpiTransmitCallback_t)(uintptr_t pData);

typedef enum
{
	DRV_SPI_SUCCESS,
	SPI_ERROR,
	DRV_SPI_BAD_CONFIG
}drvSpiReturn_t;

typedef enum
{
	SPI_A,
	SPI_B,
	SPI_C,

	NB_SPI
}drvSpiNb_t;

typedef enum
{
	SPI_1MHz = 1000000,
	SPI_2MHz = 2000000,
	SPI_5MHz = 5000000,
	SPI_10MHz = 10000000,
	SPI_20MHz = 20000000
}drvSpiSpeed_t;


typedef enum
{
	SPI_8bits = 7,
	SPI_12bits = 11,
	SPI_16bits = 15
}drvSpiWordLength_t;

typedef enum
{
	SPI_MODE0_CPOL0_CPHA0,
	SPI_MODE1_CPOL0_CPHA1,
	SPI_MODE2_CPOL1_CPHA0,
	SPI_MODE3_CPOL1_CPHA1
}drvSpiClkMode_t;

typedef enum
{
    DRV_SPI_SLAVE = 0,
    DRV_SPI_MASTER
}drvSpiNetworkMode_t;

typedef struct
{
    uint16_t txIntLevel;
    uint16_t rxIntLevel;
    uint16_t txDelay;

    drvSpiReceiveCallback_t rxCallback;
    uintptr_t pRxCallbackData;
    drvSpiTransmitCallback_t txCallbabk;
    uintptr_t pTxCallbackData;
}drvSpiFifoConf_t;

typedef struct
{
    //TODO
}drvSpiDmaConf_t;

typedef struct
{
    drvSpiNetworkMode_t mode;
	drvSpiSpeed_t speed;
	drvSpiWordLength_t wordLength;
	drvSpiClkMode_t clkMode;

	bool manualCS;
	uint16_t cs_pin;
}drvSpiConfig_t;

/* Public variables ------------------------------------------------------------------------------------------------*/
/* Public functions ------------------------------------------------------------------------------------------------*/
drvSpiReturn_t DRV_SPI_Init(drvSpiNb_t spiNb, drvSpiConfig_t *pConfig);
drvSpiReturn_t DRV_SPI_FifoConfig(drvSpiNb_t spiNb, drvSpiFifoConf_t *pConf);
drvSpiReturn_t DRV_SPI_Write(drvSpiNb_t spiNb, void *pDataTx, uint16_t size);
drvSpiReturn_t DRV_SPI_Read(drvSpiNb_t spiNb, void *pDataRx, uint16_t size);
drvSpiReturn_t DRV_SPI_ReadWrite(drvSpiNb_t spiNb, void *pDataTx, void *pDataRx, uint16_t size);

#ifdef __cplusplus
}
#endif

#endif /* DRV_SPI_H_ */
/** \} */
/** \} */
/******************************************************** EOF *******************************************************/

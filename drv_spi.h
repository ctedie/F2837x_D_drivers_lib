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
typedef enum
{
	SPI_SUCCESS,
	SPI_ERROR
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

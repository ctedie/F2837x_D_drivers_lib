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
	//FIXME with family
#ifdef F28_2837xD
	SPI_B,
	SPI_C,
#endif

	NB_SPI
}drvSpiNb_t;

typedef enum
{
	SPI_1MHz,
	SPI_2MHz,
	SPI_5MHz,
	SPI_10MHz,
	SPI_15MHz,
	SPI_20MHz,
	SPI_25MHz
}drvSpiSpeed_t;


typedef enum
{
	SPI_8bits,
	SPI_12bits,
	SPI_16bits
}drvSpiWordLength_t;

typedef enum
{
	SPI_MODE_0,
	SPI_MODE_1,
	SPI_MODE_2,
	SPI_MODE_3
}drvSpiMode_t;


typedef struct
{
	drvSpiSpeed_t speed;
	drvSpiWordLength_t wordLength;
	drvSpiMode_t mode;

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

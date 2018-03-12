/****************************************************** COMECA *******************************************************
 *  \author     tedie.cedric
 *  \date       9 mars 2018
 *  \addtogroup DRIVERS
 *  \{
 ********************************************************************************************************************/
/*********************************************************************************************************************
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

/* Public Macro definition -----------------------------------------------------------------------------------------*/
/* Public Constant definition --------------------------------------------------------------------------------------*/
/* Public Type definition  -----------------------------------------------------------------------------------------*/
typedef enum
{
	SPI_SUCCESS,
	SPI_ERROR
}DRV_SPI_Return_t;
typedef enum
{
	SPI_A,
	//FIXME with family
#ifdef DSP28_28346
	SPI_B,
	SPI_C,
#endif
	SPI_D,

	NB_SPI
}DRV_SPI_Nb_t;

typedef enum
{
	SPI_1MHz,
	SPI_2MHz,
	SPI_5MHz,
	SPI_10MHz,
	SPI_15MHz,
	SPI_20MHz,
	SPI_25MHz
}DRV_SPI_Speed_t;


typedef enum
{
	SPI_8bits,
	SPI_12bits,
	SPI_16bits
}DRV_SPI_WordLength_t;

typedef enum
{
	SPI_MODE_0,
	SPI_MODE_1,
	SPI_MODE_2,
	SPI_MODE_3
}DRV_SPI_Mode_t;


//FIXME
typedef struct
{

}DRV_GPIO_Pin_t;

typedef struct
{
	DRV_SPI_Speed_t speed;
	DRV_SPI_WordLength_t wordLength;
	DRV_SPI_Mode_t mode;

	bool manualCS;
	DRV_GPIO_Pin_t cs_pin;
}DRV_SPI_Config_t;

/* Public variables ------------------------------------------------------------------------------------------------*/
/* Public functions ------------------------------------------------------------------------------------------------*/
DRV_SPI_Return_t DRV_SPI_Init(DRV_SPI_Nb_t spiNb, DRV_SPI_Config_t *pConfig);

#ifdef __cplusplus
}
#endif

#endif /* DRV_SPI_H_ */
/** \} */
/******************************************************** EOF *******************************************************/

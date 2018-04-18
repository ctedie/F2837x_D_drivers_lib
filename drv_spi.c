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

#include "F2837xD_device.h"

#include "drv_spi.h"

/* Macro definition ------------------------------------------------------------------------------------------------*/
/* Constant definition ---------------------------------------------------------------------------------------------*/
/* Type definition  ------------------------------------------------------------------------------------------------*/

typedef struct
{
	volatile struct SPI_REGS *spiReg;
//	DRV_GPIO_Pin_t cs_pin;

	bool isInit;
}SPI_Handle_t;

/* Public variables ------------------------------------------------------------------------------------------------*/
/* Private variables -----------------------------------------------------------------------------------------------*/

SPI_Handle_t m_spiHandle[NB_SPI] =
{
	{
		.spiReg = &SpiaRegs,
		.isInit = false
	},
	{
		.spiReg = &SpibRegs,
		.isInit = false
	},
	{
		.spiReg = &SpicRegs,
		.isInit = false
	}
};
/* Private functions prototypes ------------------------------------------------------------------------------------*/
/* Private functions -----------------------------------------------------------------------------------------------*/

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
    drvSpiReturn_t ret = SPI_SUCCESS;
	SPI_Handle_t *pSpiHdl = &m_spiHandle[spiNb];


	//TODO configure speed

	//TODO configure Word Length

	//TODO Configure Mode

	pSpiHdl->isInit = true;

	return ret;
}

/** \} */
/******************************************************** EOF *******************************************************/

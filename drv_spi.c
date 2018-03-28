/****************************************************** COMECA *******************************************************
 *  \author     tedie.cedric
 *  \date       12 mars 2018
 *  \addtogroup DRIVERS
 *  \{
 ********************************************************************************************************************/
/*********************************************************************************************************************
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
	DRV_GPIO_Pin_t cs_pin;

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
//FIXME with family
#ifdef F28_2837xD
	{
		.spiReg = &SpibRegs,
		.isInit = false
	},
	{
		.spiReg = &SpicRegs,
		.isInit = false
	}
#endif
};
/* Private functions prototypes ------------------------------------------------------------------------------------*/
/* Private functions -----------------------------------------------------------------------------------------------*/

/***********************************************************
 * \brief
 *
 * \param
 *
 * \return
 **********************************************************/
DRV_SPI_Return_t DRV_SPI_Init(DRV_SPI_Nb_t spiNb, DRV_SPI_Config_t *pConfig)
{
	DRV_SPI_Return_t ret = SPI_SUCCESS;
	SPI_Handle_t *pSpiHdl = &m_spiHandle[spiNb];


	//TODO configure speed

	//TODO configure Word Length

	//TODO Configure Mode

	pSpiHdl->isInit = true;

	return ret;
}

/** \} */
/******************************************************** EOF *******************************************************/

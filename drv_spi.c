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

#include "mapping.h"

#include "drv_gpio.h"
#include "drv_spi.h"

/* Macro definition ------------------------------------------------------------------------------------------------*/
/* Constant definition ---------------------------------------------------------------------------------------------*/
/* Type definition  ------------------------------------------------------------------------------------------------*/

typedef struct
{
	volatile struct SPI_REGS *spiReg;
	drvGpioPin_t *cs_pin;

	bool autoChipSelect;
	bool isInit;
}SPI_Handle_t;

static drvGpioPin_t m_spiPins[NB_SPI][4] =
{
     // {MOSI_PIN, MISO_PIN, CLK_PIN, CS_PIN }
     {SPIA_MOSI, SPIA_MISO, SPIA_CLK, SPIA_CS}, //SPIA
     {NULL, NULL, NULL, NULL},                  //SPIB
     {NULL, NULL, NULL, NULL}                   //SPIC
};
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
drvSpiReturn_t SpiGpioInit(drvSpiNb_t spiNb);
drvSpiReturn_t SpiSpeedConfig(drvSpiNb_t spiNb, uint32_t speed);
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
    return SPI_SUCCESS;
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
        return SPI_ERROR;
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

    return SPI_SUCCESS;
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
    drvSpiReturn_t ret = SPI_SUCCESS;
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

    pSpiHdl->spiReg->SPIPRI.bit.STEINV = 0;
    pSpiHdl->spiReg->SPISTS.bit.OVERRUN_FLAG = 1;

    pSpiHdl->spiReg->SPICTL.bit.TALK = 1;

    /* For TEST Loopback enabled */
    //TODO remove
    pSpiHdl->spiReg->SPICCR.bit.SPILBK = 1;

    /* Configure interrupts and callbacks */
    //TODO

    /* Release from reset */
    pSpiHdl->spiReg->SPICCR.bit.SPISWRESET = 1;


	pSpiHdl->isInit = true;

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
    drvSpiReturn_t ret = SPI_SUCCESS;
    uint16_t *data = (uint16_t*)pDataTx;

    m_spiHandle[spiNb].spiReg->SPITXBUF = *data;

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
    drvSpiReturn_t ret = SPI_SUCCESS;
    uint16_t *data = (uint16_t*)pDataRx;

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
    drvSpiReturn_t ret = SPI_SUCCESS;
    return ret;
}

/** \} */
/******************************************************** EOF *******************************************************/

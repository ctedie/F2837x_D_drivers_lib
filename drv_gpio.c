/*********************************************************************************************************************
 *                                                      COMECA
 ********************************************************************************************************************/
/**
 *********************************************************************************************************************
 *  \author		tedie.cedric
 *  \date		19 avr. 2018
 *  \addtogroup	DRV_GPIO
 *  \{
 ********************************************************************************************************************/
/**
 *********************************************************************************************************************
 *  \file		drv_gpio.c
 *  
 *  \brief		The DRV_GPIO module source file
 *
 *  \details	
 *
 ********************************************************************************************************************/

/* Includes --------------------------------------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>

#include "F28x_Project.h"

#include "drv_gpio.h"
#include "drv_gpio_defines.h"

/* Macro definition ------------------------------------------------------------------------------------------------*/
/* Constant definition ---------------------------------------------------------------------------------------------*/
/* Type definition  ------------------------------------------------------------------------------------------------*/
/* Public variables ------------------------------------------------------------------------------------------------*/
/* Private variables -----------------------------------------------------------------------------------------------*/
/* Private functions prototypes ------------------------------------------------------------------------------------*/
/* Private functions -----------------------------------------------------------------------------------------------*/
/* Public functions ------------------------------------------------------------------------------------------------*/

/**
 *********************************************************
 * \brief   Initialize a GPIO with some configuration
 *
 * \param [in]  pin     The gpio pin structure
 *
 * \return  One of \ref drvGpioReturn_t values
 *********************************************************/
drvGpioReturn_t DRV_GPIO_PinInit(drvGpioPin_t *pin)
{

    //TODO improvements

    GPIO_SetupPinMux(pin->pin_number, (uint16_t)pin->cpu, pin->pin_type);
//    GPIO_SetupPinOptions(pin->pin_number, pin->direction, flags)
    if(pin->pin_type == DRV_GPIO_DIR_OUTPUT)
    {
        GPIO_WritePin(pin->pin_number, pin->defaultState);
    }

    GPIO_SetupPinOptions(pin->pin_number, pin->direction, 0);

    return DRV_GPIO_SUCCESS;
}

/**
 *********************************************************
 * \brief   Set the GPIO to a defined state
 *
 * \param [in]  pin     The gpio pin structure
 * \param [in]  state   The pin state. The real state of the pin
 *                      is function of \ref drvGpioPolarity
 *
 *********************************************************/
void DRV_GPIO_PinSet(drvGpioPin_t *pin, drvGpioPinState_t state)
{
    uint16_t realState;
//TODO improvements

    realState = (pin->polarity == DRV_GPIO_POL_NORMAL ? state : !state);

    GPIO_WritePin(pin->pin_number, realState);
}

/**
 *********************************************************
 * \brief   Toggle the GPIO state
 *
 * \param [in]  pin     The gpio pin structure
 *
 *********************************************************/
void DRV_GPIO_PinToggle(drvGpioPin_t *pin)
{

    volatile Uint32 *gpioDataReg;
    Uint32 pinMask;

    gpioDataReg = (volatile Uint32 *)&GpioDataRegs + (pin->pin_number/32)*GPY_DATA_OFFSET;
    pinMask = 1UL << (pin->pin_number % 32);

    gpioDataReg[GPYTOGGLE] = pinMask;

}

/**
 *********************************************************
 * \brief   Read back the GPIO state
 *
 * \param [in]  pin     The gpio pin structure
 *
 * \return  The state of the pin (\ref drvGpioPinState_t )
 *********************************************************/
drvGpioPinState_t DRV_GPIO_PinRead(drvGpioPin_t *pin)
{

    return (drvGpioPinState_t)GPIO_ReadPin(pin->pin_number);
}


/** \} */
/******************************************************** EOF *******************************************************/

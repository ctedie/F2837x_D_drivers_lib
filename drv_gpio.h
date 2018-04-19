/*********************************************************************************************************************
 *                                                      COMECA
 ********************************************************************************************************************/
/**
 *********************************************************************************************************************
 *  \author		tedie.cedric
 *  \date		19 avr. 2018
 *  \addtogroup	DRIVERS
 *  \{
 *  \addtogroup	DRV_GPIO
 *  \{
 *  
 *  \brief This module contains GPIO API functions
 *  
 *  \details 
 ********************************************************************************************************************/
/**
 *********************************************************************************************************************
 *  \file		drv_gpio.h
 *  
 *  \brief		The DRV_GPIO module header file
 *
 *  \details	
 *
 ********************************************************************************************************************/
#ifndef DRV_GPIO_H_
#define DRV_GPIO_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes --------------------------------------------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>

/* Public Macro definition -----------------------------------------------------------------------------------------*/
/* Public Constant definition --------------------------------------------------------------------------------------*/
/* Public Type definition  -----------------------------------------------------------------------------------------*/

typedef enum
{
    DRV_GPIO_SUCCESS,
    DRV_GPIO_ERROR
}drvGpioReturn_t;

typedef enum
{
    DRV_GPIO_DIR_INPUT = 0,
    DRV_GPIO_DIR_OUTPUT
}drvGpioPinDirection;

typedef enum
{
    DRV_GPIO_POL_NORMAL= 0, /**< The Inactive state is 0 */
    DRV_GPIO_POL_INVERTED   /**< The inactive state is 1 */
}drvGpioPolarity;

typedef enum
{
    DRV_GPIO_PIN_INACTIVE = 0,
    DRV_GPIO_PIN_ACTIVE
}drvGpioPinState_t;

//TODO Add GPIO FLAGS
/** The GPIO pin structure */
typedef struct
{
    uint16_t pin_number;    /**< Pin number */
    uint16_t pin_type;      /**< The pin type \see DRV_GPIO_DEFINES */
    uint16_t cpu;
    drvGpioPinDirection direction;
    drvGpioPolarity polarity;
    drvGpioPinState_t defaultState;

//    bool isInit;

}drvGpioPin_t;

/* Public variables ------------------------------------------------------------------------------------------------*/
/* Public functions ------------------------------------------------------------------------------------------------*/
drvGpioReturn_t DRV_GPIO_PinInit(drvGpioPin_t *pin);
void DRV_GPIO_PinSet(drvGpioPin_t *pin, drvGpioPinState_t state);
void DRV_GPIO_PinToggle(drvGpioPin_t *pin);
drvGpioPinState_t DRV_GPIO_PinRead(drvGpioPin_t *pin);

#endif /* DRV_GPIO_H_ */

#ifdef __cplusplus
}
#endif

/** \} */
/** \} */
/******************************************************** EOF *******************************************************/

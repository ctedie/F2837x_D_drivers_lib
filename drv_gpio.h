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


typedef enum
{
    DRV_GPIO_CPU1 = 0,
    DRV_GPIO_CLA1,
    DRV_GPIO_CPU2,
    DRV_GPIO_CLA2
}drvGpioCpu_t;

//typedef enum
//{
//    DRV_GPIO_CPU1 = 0,
//    DRV_GPIO_CLA1,
//    DRV_GPIO_CPU2,
//    DRV_GPIO_CLA2
//}drvGpioCpu_t;


//TODO Add GPIO FLAGS
typedef enum
{
    DRV_GPIO_FLAGS_SYNC,
    DRV_GPIO_FLAGS_QUAL3,
    DRV_GPIO_FLAGS_QUAL6,
    DRV_GPIO_FLAGS_ASYNC
}drvGpioFlags_t;


/** The GPIO pin structure */
typedef struct
{
    uint16_t pin_number;    /**< Pin number */
    uint16_t pin_type;      /**< The pin type \see DRV_GPIO_DEFINES */
    drvGpioCpu_t cpu;
    drvGpioPinDirection direction;
    drvGpioPolarity polarity;
//    bool pullup;
//    bool openDrain;
//    drvGpioFlags_t sync;
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

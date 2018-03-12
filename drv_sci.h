/****************************************************** COMECA *******************************************************
 *  \author		tedie.cedric
 *  \date		9 mars 2018
 *  \addtogroup	DRIVERS
 *  \{
 ********************************************************************************************************************/
/*********************************************************************************************************************
 *  \file		drv_sci.h
 *  
 *  \brief		The SCI driver header file
 *
 *  \details	
 *
 *********************************************************************************************************************/

#ifndef DRV_SCI_H_
#define DRV_SCI_H_

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
typedef void (*drvSciReceiveCallback_t)(void *pData, uint16_t car);
typedef bool (*drvSciTransmitCallback_t)(void *pData, uint16_t *car);
typedef void (*drvSciEndOfTransmitionCallback_t)(void *pData);

/** The specific return type enum */
typedef enum
{
    DRV_SCI_SUCCESS = 0,    /**!< SERIAL_LINK_SUCCESS     */
    DRV_SCI_ERROR,          /**!< SERIAL_LINK_ERROR       */
    DRV_SCI_BAD_CONFIG,     /**!< SERIAL_LINK_BAD_CONFIG  */
    DRV_SCI_NOT_INIT,       /**!< SERIAL_LINK_NOT_INIT    */
    DRV_SCI_TX_ERROR,       /**!< SERIAL_LINK_TX_ERROR    */
    DRV_SCI_BAD_ID          /**!< SERIAL_LINK_BAD_ID      */
}drvSciReturn_t;

/** The SCI number enum */
typedef enum
{
    SCI_A = 0,
    SCI_B,
    SCI_C,

    NB_SERIAL
}drvSciNumber_t;

/** The SCI baudrate enum */
typedef enum
{
    DRV_SCI_B9600 = 9600,
    DRV_SCI_B19200 = 19200,
    DRV_SCI_B57600 = 57600,
    DRV_SCI_B115200 = 115200,
    DRV_SCI_B460800 = 460800
}drvSciSpeed_t;

/** The SCI data size enum */
typedef enum
{
    DRV_SCI_BIT_1 = 0,
    DRV_SCI_BIT_2,
    DRV_SCI_BIT_3,
    DRV_SCI_BIT_4,
    DRV_SCI_BIT_5,
    DRV_SCI_BIT_6,
    DRV_SCI_BIT_7,
    DRV_SCI_BIT_8
}drvSciDataSize_t;

/** The SCI parity enum */
typedef enum
{
    DRV_SCI_PARITY_NONE,
    DRV_SCI_PARITY_ODD,
    DRV_SCI_PARITY_EVEN
}drvSciParity_t;

/** The SCI stop bit enum */
typedef enum
{
    DRV_SCI_STOP_BIT_1 = 0,
    DRV_SCI_STOP_BIT_2
}drvSciStopBit_t;

/** The SCI configuration structure */
typedef struct
{

    drvSciSpeed_t baudrate;
    drvSciDataSize_t dataSize;
    drvSciParity_t parity;
    drvSciStopBit_t stopBit;
    drvSciReceiveCallback_t cbReception;
    void* pReceptionData;
    drvSciTransmitCallback_t cbTransmission;
    void* pTransmitionData;
    drvSciEndOfTransmitionCallback_t cbEndOfTransmition;
    void* pEndOfTransmitionArg;
    bool initOk;
}drvSciConfig_t;

/* Public variables ------------------------------------------------------------------------------------------------*/
/* Public functions ------------------------------------------------------------------------------------------------*/

drvSciReturn_t DRV_SCI_Init(drvSciNumber_t uartNb, drvSciConfig_t *pConfig);
drvSciReturn_t DRV_SCI_WriteChar(drvSciNumber_t uartNb, uint16_t car);
drvSciReturn_t DRV_SCI_ReadChar(drvSciNumber_t uartNb, uint16_t* pCar);

#ifdef __cplusplus
}
#endif

#endif /* DRV_SCI_H_ */

/** \} */
/******************************************************** EOF *******************************************************/

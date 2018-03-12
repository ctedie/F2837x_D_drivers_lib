/****************************************************** COMECA *******************************************************
 *  \author		tedie.cedric
 *  \date		9 mars 2018
 *  \addtogroup	DRIVERS
 *  \{
 ********************************************************************************************************************/
/*********************************************************************************************************************
 *  \file		drv_uart.h
 *  
 *  \brief		The UART driver header file
 *
 *  \details	
 *
 *********************************************************************************************************************/

#ifndef DRV_UART_H_
#define DRV_UART_H_

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
typedef void (*drvUartReceiveCallback_t)(void *pData, uint16_t car);
typedef bool (*drvUartTransmitCallback_t)(void *pData, uint16_t *car);
typedef void (*drvUartEndOfTransmitionCallback_t)(void *pData);

/** The specific return type enum */
typedef enum
{
    DRV_UART_SUCCESS,     /**!< SERIAL_LINK_SUCCESS     */
    DRV_UART_ERROR,       /**!< SERIAL_LINK_ERROR       */
    DRV_UART_BAD_CONFIG,  /**!< SERIAL_LINK_BAD_CONFIG  */
    DRV_UART_NOT_INIT,    /**!< SERIAL_LINK_NOT_INIT    */
    DRV_UART_TX_ERROR,    /**!< SERIAL_LINK_TX_ERROR    */
    DRV_UART_BAD_ID       /**!< SERIAL_LINK_BAD_ID      */
}drvUartReturn_t;

/** The UART number enum */
typedef enum
{
    SCI_A = 0,
    SCI_B,
    SCI_C,

    NB_SERIAL
}drvUartNumber_t;

/** The UART baudrate enum */
typedef enum
{
    DRV_UART_B9600 = 9600,
    DRV_UART_B19200 = 19200,
    DRV_UART_B57600 = 57600,
    DRV_UART_B115200 = 115200,
    DRV_UART_B460800 = 460800
}drvUartSpeed_t;

/** The UART data size enum */
typedef enum
{
    DRV_UART_BIT_7,
    DRV_UART_BIT_8,
    DRV_UART_BIT_9
}drvUartDataSize_t;

/** The UART parity enum */
typedef enum
{
    DRV_UART_PARITY_NONE,
    DRV_UART_PARITY_EVEN,
    DRV_UART_PARITY_ODD
}drvUartParity_t;

/** The UART stop bit enum */
typedef enum
{
    DRV_UART_STOP_BIT_1,
    DRV_UART_STOP_BIT_2
}drvUartStopBit_t;

/** The UART configuration structure */
typedef struct
{

    drvUartSpeed_t baudrate;
    drvUartDataSize_t dataSize;
    drvUartParity_t parity;
    drvUartStopBit_t stopBit;
    drvUartReceiveCallback_t cbReception;
    void* pReceptionData;
    drvUartTransmitCallback_t cbTransmission;
    void* pTransmitionData;
    drvUartEndOfTransmitionCallback_t cbEndOfTransmition;
    void* pEndOfTransmitionArg;
    bool initOk;
}drvUartConfig_t;

/* Public variables ------------------------------------------------------------------------------------------------*/
/* Public functions ------------------------------------------------------------------------------------------------*/

drvUartReturn_t DRV_UART_Init(drvUartNumber_t uartNb, drvUartConfig_t *pConfig);
drvUartReturn_t DRV_UART_Write(void);
drvUartReturn_t DRV_UART_Read(void);

#ifdef __cplusplus
}
#endif

#endif /* DRV_UART_H_ */

/** \} */
/******************************************************** EOF *******************************************************/

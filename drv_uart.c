/****************************************************** COMECA *******************************************************
 *  \author		tedie.cedric
 *  \date		9 mars 2018
 *  \addtogroup	DRIVERS
 *  \{
 ********************************************************************************************************************/
/****************************************************** COMECA *******************************************************
 *  \file		drv_uart.c
 *  
 *  \brief		The UART driver source file
 *
 *  \details	
 *
 ********************************************************************************************************************/

/* Includes --------------------------------------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "DSP2834x_Device.h"

#include "drv_uart.h"

/* Macro definition ------------------------------------------------------------------------------------------------*/
/* Constant definition ---------------------------------------------------------------------------------------------*/
/* Type definition  ------------------------------------------------------------------------------------------------*/

/** The UART Handle structure */
typedef struct
{
    volatile struct SCI_REGS *sci;

    drvUartReceiveCallback_t cbReception;
    void* pReceptionData;
    drvUartTransmitCallback_t cbTransmission;
    void* pTransmitionData;
    drvUartEndOfTransmitionCallback_t cbEndOfTransmition;
    void* pEndOfTransmitionArg;


    bool initOk;

}UARTHandle_t;

/* Public variables ------------------------------------------------------------------------------------------------*/
/* Private variables -----------------------------------------------------------------------------------------------*/

UARTHandle_t m_UARTList[NB_SERIAL] =
{
     {
          .sci = &SciaRegs,
          .initOk = false
     },
     {
          .sci = &ScibRegs,
          .initOk = false
     },
     {
          .sci = &ScicRegs,
          .initOk = false
     }
};

/* Private functions prototypes ------------------------------------------------------------------------------------*/
static bool setBaudRate(volatile struct SCI_REGS *pSci, drvUartSpeed_t speed);

/* Private functions -----------------------------------------------------------------------------------------------*/

/***********************************************************
 * \brief
 *
 * \param
 *
 * \return
 **********************************************************/
static bool setBaudRate(volatile struct SCI_REGS *pSci, drvUartSpeed_t speed)
{
    uint16_t brr_Value;

    //TODO CPU clock
    brr_Value = 300000000 / ((uint32_t)speed * 8 * (SysCtrlRegs.LOSPCP.bit.LSPCLK * 2));
    pSci->SCIHBAUD = (brr_Value >> 8) & 0xFF;
    pSci->SCILBAUD = (brr_Value & 0xFF);

    return true;
}

/* Public functions ------------------------------------------------------------------------------------------------*/

/**********************************************************
 * \brief The driver initialization function
 * \warning GPIO pins must be configured before
 *
 * \param [in]  uartNb
 * \param [in]  pConfig
 *
 * \return
 *********************************************************/
drvUartReturn_t DRV_UART_Init(drvUartNumber_t uartNb, drvUartConfig_t *pConfig)
{
    drvUartReturn_t ret = DRV_UART_SUCCESS;

    if(pConfig == NULL)
    {
        //Error
        return DRV_UART_BAD_CONFIG;
    }

    m_UARTList[uartNb].cbReception = pConfig->cbReception;
    m_UARTList[uartNb].pReceptionData = pConfig->pReceptionData;
    m_UARTList[uartNb].cbTransmission = pConfig->cbTransmission;
    m_UARTList[uartNb].pTransmitionData = pConfig->pTransmitionData;
    m_UARTList[uartNb].cbEndOfTransmition = pConfig->cbEndOfTransmition;
    m_UARTList[uartNb].pEndOfTransmitionArg = pConfig->pEndOfTransmitionArg;

    /* Baud Rate config */
    setBaudRate( m_UARTList[uartNb].sci, pConfig->baudrate);



    return ret;
}

/***********************************************************
 * \brief
 *
 * \param
 *
 * \return
 **********************************************************/
drvUartReturn_t DRV_UART_Write(void)
{
    return true;
}

drvUartReturn_t DRV_UART_Read(void)
{
    return true;
}

/** \} */
/******************************************************** EOF *******************************************************/

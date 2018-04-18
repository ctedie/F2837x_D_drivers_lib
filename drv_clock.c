/*********************************************************************************************************************
 *                                                      COMECA
 ********************************************************************************************************************/
/**
 *********************************************************************************************************************
 *  \author     tedie.cedric
 *  \date       21 avril 2018
 *  \addtogroup DRV_CLOCK
 *  \{
 ********************************************************************************************************************/
/**
 ********************************************************************************************************************
 *  \file       DRV_CLOCK.c
 *
 *  \brief      The clock driver source file
 *
 *  \details
 *
 ********************************************************************************************************************/
#ifdef OS
/* Includes --------------------------------------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>

#include "F28x_Project.h"

#include <ti/sysbios/knl/Clock.h>

#include "hw_ints.h"
#include "drv_utils.h"
#include "drv_clock.h"

/* Macro definition ------------------------------------------------------------------------------------------------*/
/* Constant definition ---------------------------------------------------------------------------------------------*/
/* Type definition  ------------------------------------------------------------------------------------------------*/

/** The timer handle structure */
typedef struct
{
    Clock_Handle    clockHandle;
    drvClockIsrCallback_t cbEndOfPeriod;   /** The callback at the end of period */
    void* pData;                           /** Data passed to the callback */

    uint32_t timeoutVal_ms;                /** The timeout period */

    bool initOk;                        /** INTERNAL true if struct is initialized */

}CLOCKHandle_t;

/* Public variables ------------------------------------------------------------------------------------------------*/
/* Private variables -----------------------------------------------------------------------------------------------*/
static CLOCKHandle_t m_CLOCKList[NB_CLOCK] =
{
     {
      .initOk = false
     },
     {
      .initOk = false
     },
     {
      .initOk = false
     },
     {
      .initOk = false
     },
     {
      .initOk = false
     },
     {
      .initOk = false
     },
     {
      .initOk = false
     },
     {
      .initOk = false
     },
};

/* Private functions prototypes ------------------------------------------------------------------------------------*/
/* Private functions -----------------------------------------------------------------------------------------------*/
/* Public functions ------------------------------------------------------------------------------------------------*/

/**
 *********************************************************
 * \brief   Initialize the driver
 *
 * \param [in]  timNb           The timer number
 * \param [in]  period_ms       The period in us
 * \param [in]  autoreload      True if autoreload
 * \param [in]  cbEndOfPeriod   The callback at the end of period
 * \param [in]  pCallbackData   The data to pass to the callback
 *
 * \return  One of \ref drvClockReturn_t values
 *********************************************************/
drvClockReturn_t DRV_CLOCK_Init(drvClockNumber_t timNb, uint32_t period_ms, bool autoreload, drvClockIsrCallback_t cbEndOfPeriod, void* pCallbackData)
{
    drvClockReturn_t ret = DRV_CLOCK_SUCCESS;

    CLOCKHandle_t *pHandle = &m_CLOCKList[timNb];

    Clock_Params params;

    if(pHandle->initOk)
    {
        return DRV_CLOCK_ALREADY_INIT;
    }

    if(cbEndOfPeriod == NULL)
    {
        return DRV_CLOCK_BAD_CONFIG;
    }

    //TODO Make sure InitCpuTimers() was called before


    pHandle->timeoutVal_ms = period_ms;
//    pHandle->cbEndOfPeriod = cbEndOfPeriod;
//    pHandle->pData = pCallbackData;
    Clock_Params_init(&params);
    params.arg = (xdc_UArg)pCallbackData;
    params.startFlag = false;
    params.period = period_ms;

    pHandle->clockHandle = Clock_create((Clock_FuncPtr)cbEndOfPeriod, params.period, &params, NULL);
    if(pHandle->clockHandle == NULL)
    {
        return DRV_CLOCK_NO_MORE_CLOCK;
    }

    pHandle->initOk = true;
    return ret;

}

/**
 *********************************************************
 * \brief   Start the timer
 *
 * \param [in]  timNb   The timer number
 *
 * \return  The status
 *********************************************************/
drvClockReturn_t DRV_CLOCK_Start(drvClockNumber_t timNb)
{

    if(!m_CLOCKList[timNb].initOk)
    {
        return DRV_CLOCK_NOT_INIT;
    }
    Clock_start(m_CLOCKList[timNb].clockHandle);

    return DRV_CLOCK_SUCCESS;
}

/**
 *********************************************************
 * \brief   Stop the timer
 *
 * \param [in]  timNb   The timer number
 *
 * \return  The status
 *********************************************************/
drvClockReturn_t DRV_CLOCK_Stop(drvClockNumber_t timNb)
{

    if(!m_CLOCKList[timNb].initOk)
    {
        return DRV_CLOCK_NOT_INIT;
    }

    Clock_stop(m_CLOCKList[timNb].clockHandle);

    return DRV_CLOCK_SUCCESS;
}

/**
 *********************************************************
 * \brief   Stop the timer then set a new timeout period
 *
 * \param [in]  timNb   The timer number
 * \param [in]  period_ms  The new period
 *
 * \return  The status
 *********************************************************/
drvClockReturn_t DRV_CLOCK_SetPeriod(drvClockNumber_t timNb, uint32_t period_ms)
{
    if(!m_CLOCKList[timNb].initOk)
    {
        return DRV_CLOCK_NOT_INIT;
    }

    Clock_setPeriod(m_CLOCKList[timNb].clockHandle, period_ms);

    return DRV_CLOCK_SUCCESS;
}

#else   /* OS */
#error "This module can't be use without OS"
#endif

/** \} */
/******************************************************** EOF *******************************************************/

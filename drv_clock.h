/*********************************************************************************************************************
 *                                                      COMECA
 ********************************************************************************************************************/
/**
 ********************************************************************************************************************
 *  \author     tedie.cedric
 *  \date       18 avril 2018
 *  \addtogroup DRIVERS
 *  \{
 *  \addtogroup DRV_CLOCK
 *  \{
 *  \brief A driver for periodical functions
 ********************************************************************************************************************/
/**
 ********************************************************************************************************************
 *  \file       DRV_CLOCK.h
 *  
 *  \brief      The clock driver header file
 *
 *  \details
 *
 ********************************************************************************************************************/
#ifndef DRV_CLOCK_H_
#define DRV_CLOCK_H_

#ifdef OS
#ifdef __cplusplus
extern "C"
{
#endif

/* Includes --------------------------------------------------------------------------------------------------------*/
#include "F28x_Project.h"

/* Public Macro definition -----------------------------------------------------------------------------------------*/

/* Public Constant definition --------------------------------------------------------------------------------------*/
/* Public Type definition  -----------------------------------------------------------------------------------------*/
typedef void (*drvClockIsrCallback_t)(void* pData);

/** Return type enum */
typedef enum
{
    DRV_CLOCK_SUCCESS = 0,
    DRV_CLOCK_ERROR,
    DRV_CLOCK_NOT_INIT,
    DRV_CLOCK_BAD_CONFIG,
    DRV_CLOCK_ALREADY_INIT,
    DRV_CLOCK_NO_MORE_CLOCK
}drvClockReturn_t;

/** Timer number enum */
typedef enum
{
    CLOCK0,
    CLOCK1,
    CLOCK2,
    CLOCK3,
    CLOCK4,
    CLOCK5,
    CLOCK6,
    CLOCK7,
    NB_CLOCK
}drvClockNumber_t;

/** Driver configuration structure */
typedef struct
{
    drvClockIsrCallback_t cbTimerEnd;
    void* pData;
}drvClockConfig_t;

/* Public variables ------------------------------------------------------------------------------------------------*/
/* Public functions ------------------------------------------------------------------------------------------------*/

drvClockReturn_t DRV_CLOCK_Init(drvClockNumber_t timNb, uint32_t period_ms, bool autoreload, drvClockIsrCallback_t cbEndOfPeriod, void* pCallbackData);
drvClockReturn_t DRV_CLOCK_Start(drvClockNumber_t timNb);
drvClockReturn_t DRV_CLOCK_Stop(drvClockNumber_t timNb);
drvClockReturn_t DRV_CLOCK_SetPeriod(drvClockNumber_t timNb, uint32_t period_ms);

#endif /* OS */

#endif /* DRV_CLOCK_H_ */

#ifdef __cplusplus
}
#endif

/** \} */
/** \} */
/******************************************************** EOF *******************************************************/

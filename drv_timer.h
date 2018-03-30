/****************************************************** COMECA *******************************************************
 *  \author		tedie.cedric
 *  \date		28 mars 2018
 *  \addtogroup	DRV_TIMER
 *  \{
 ********************************************************************************************************************/
/*********************************************************************************************************************
 *  \file		drv_timer.h
 *  
 *  \brief		The timer driver header file
 *
 *  \details	
 *
 ********************************************************************************************************************/
#ifndef DRV_TIMER_H_
#define DRV_TIMER_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes --------------------------------------------------------------------------------------------------------*/
#include "F28x_Project.h"

/* Public Macro definition -----------------------------------------------------------------------------------------*/
#define DRV_TIMER_CLEAR_IT_TIM0()   (PieCtrlRegs.PIEACK.all = PIEACK_GROUP1)

/* Public Constant definition --------------------------------------------------------------------------------------*/
/* Public Type definition  -----------------------------------------------------------------------------------------*/
typedef void (*drvTimerIsrCallback_t)(void* pData);

typedef enum
{
    DRV_TIMER_SUCCESS = 0,
    DRV_TIMER_ERROR,
    DRV_TIMER_BAD_CONFIG,
    DRV_TIMER_ALREADY_INIT
}drvTimerReturn_t;

typedef enum
{
    TIMER0,
    TIMER1,
    TIMER2,

    NB_TIMER
}drvTimerNumber_t;

typedef struct
{
    drvTimerIsrCallback_t cbTimerEnd;
    void* pData;
}drvTimerConfig_t;

/* Public variables ------------------------------------------------------------------------------------------------*/
/* Public functions ------------------------------------------------------------------------------------------------*/

drvTimerReturn_t DRV_TIMER_Init(drvTimerNumber_t timNb, float period_us, bool autoreload, drvTimerIsrCallback_t cbTimerEnd, void* pCallbackData);
drvTimerReturn_t DRV_TIMER_Start(drvTimerNumber_t timNb);
drvTimerReturn_t DRV_TIMER_Stop(drvTimerNumber_t timNb);
drvTimerReturn_t DRV_TIMER_SetPeriod(drvTimerNumber_t timNb, float period);
drvTimerReturn_t DRV_TIMER_Reload(drvTimerNumber_t timNb);
inline uint32_t DRV_TIMER_GetCounter(drvTimerNumber_t timNb);

#endif /* DRV_TIMER_H_ */

#ifdef __cplusplus
}
#endif

/** \} */
/******************************************************** EOF *******************************************************/

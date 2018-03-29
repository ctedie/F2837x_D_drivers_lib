/****************************************************** COMECA *******************************************************
 *  \author		tedie.cedric
 *  \date		28 mars 2018
 *  \addtogroup	DRV_TIMER
 *  \{
 ********************************************************************************************************************/
/*********************************************************************************************************************
 *  \file		drv_timer.c
 *  
 *  \brief		The timer driver source file
 *
 *  \details	
 *
 ********************************************************************************************************************/

/* Includes --------------------------------------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>

#include "F28x_Project.h"

#include "drv_timer.h"

/* Macro definition ------------------------------------------------------------------------------------------------*/
/* Constant definition ---------------------------------------------------------------------------------------------*/
/* Type definition  ------------------------------------------------------------------------------------------------*/

/** The timer handle structure */
typedef struct
{
    struct CPUTIMER_VARS *timer;        /**!< A pointer to the timer_var structure */
    drvTimerIsrCallback_t cbTimerEnd;   /**!< The callback when timeout interrupt orccurs */
    void* pData;                        /**!< Data passed to the callback */

    float timeoutVal_us;                /**!< The timeout period */

    bool initOk;                        /**!< INTERNAL true if struct is initialized */

}TIMERHandle_t;

/* Public variables ------------------------------------------------------------------------------------------------*/
/* Private variables -----------------------------------------------------------------------------------------------*/
static TIMERHandle_t m_TIMERList[NB_TIMER] =
{
     {
      .timer = &CpuTimer0,
      .initOk = false
     },
     {
      .timer = &CpuTimer1,
      .initOk = false
     },
     {
      .timer = &CpuTimer2,
      .initOk = false
     },
};

/* Private functions prototypes ------------------------------------------------------------------------------------*/
__interrupt void timer0_isr(void);
__interrupt void timer1_isr(void);
__interrupt void timer2_isr(void);

/* Private functions -----------------------------------------------------------------------------------------------*/
/**********************************************************
 * \brief
 *********************************************************/
__interrupt void timer0_isr(void)
{
    m_TIMERList[TIMER0].cbTimerEnd(m_TIMERList[TIMER0].pData);
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

/**********************************************************
 * \brief
 *********************************************************/
__interrupt void timer1_isr(void)
{
    m_TIMERList[TIMER1].cbTimerEnd(m_TIMERList[TIMER1].pData);
}

/**********************************************************
 * \brief   The timer 2 global interrupt function
 *********************************************************/
__interrupt void timer2_isr(void)
{
    m_TIMERList[TIMER2].cbTimerEnd(m_TIMERList[TIMER2].pData);
}

/* Public functions ------------------------------------------------------------------------------------------------*/

/**********************************************************
 * \brief 
 *
 * \param [in]  timNb           The timer number
 * \param [in]  period_us       The period in us
 * \param [in]  autoreload      True if autoreload
 * \param [in]  cbTimerEnd      The callback when the timeout interrupt occurs
 * \param [in]  pCallbackData   The data to pass to the callback
 *
 * \return  The status
 *********************************************************/
drvTimerReturn_t DRV_TIMER_Init(drvTimerNumber_t timNb, float period_us, bool autoreload, drvTimerIsrCallback_t cbTimerEnd, void* pCallbackData)
{
    drvTimerReturn_t ret = DRV_TIMER_SUCCESS;

    TIMERHandle_t *pHandle = &m_TIMERList[timNb];

    if(pHandle->initOk)
    {
        return DRV_TIMER_ALREADY_INIT;
    }

    if(cbTimerEnd == NULL)
    {
        return DRV_TIMER_BAD_CONFIG;
    }

    //TODO Make sure InitCpuTimers() was called before

    DINT;

    switch (timNb)
    {
        case TIMER0:
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.TIMER0_INT = &timer0_isr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
            IER |= M_INT1;
            PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
            break;
        case TIMER1:
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.TIMER1_INT = &timer1_isr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
            IER |= M_INT13;
            break;
        case TIMER2:
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.TIMER2_INT = &timer2_isr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
            IER |= M_INT14;
            break;
        default:
            return DRV_TIMER_BAD_CONFIG;
    }

    pHandle->timeoutVal_us = period_us;
    pHandle->cbTimerEnd = cbTimerEnd;
    pHandle->pData = pCallbackData;

    //TODO CPU FREQ instead of 200
    ConfigCpuTimer(pHandle->timer, 200, period_us);


    EINT;

    pHandle->initOk = true;
    return ret;

}

/**********************************************************
 * \brief   Start the timer
 *
 * \param [in]  timNb   The timer number
 *
 * \return  The status
 *********************************************************/
drvTimerReturn_t DRV_TIMER_Start(drvTimerNumber_t timNb)
{
    m_TIMERList[timNb].timer->RegsAddr->TCR.bit.TSS = 0;

    return DRV_TIMER_SUCCESS;
}

/**********************************************************
 * \brief   Stop the timer
 *
 * \param [in]  timNb   The timer number
 *
 * \return  The status
 *********************************************************/
drvTimerReturn_t DRV_TIMER_Stop(drvTimerNumber_t timNb)
{
    m_TIMERList[timNb].timer->RegsAddr->TCR.bit.TSS = 1;

    return DRV_TIMER_SUCCESS;
}

/**********************************************************
 * \brief   Stop the timer then set a new timeout period
 *
 * \param [in]  timNb   The timer number
 * \param [in]  period  The new period
 *
 * \return  The status
 *********************************************************/
drvTimerReturn_t DRV_TIMER_SetPeriod(drvTimerNumber_t timNb, float period)
{
    m_TIMERList[timNb].timer->RegsAddr->TCR.bit.TSS = 1;
    ConfigCpuTimer(m_TIMERList[timNb].timer, 200, period);


    return DRV_TIMER_SUCCESS;
}

/**********************************************************
 * \brief   Reload the timer with the configured period value
 *
 * \param [in]  timNb   The timer number
 *
 * \return  The status
 *********************************************************/
drvTimerReturn_t DRV_TIMER_Reload(drvTimerNumber_t timNb)
{
    m_TIMERList[timNb].timer->RegsAddr->TCR.bit.TRB = 1;

    return DRV_TIMER_SUCCESS;
}

/**********************************************************
 * \brief   Get the timer counter value
 *
 * \param [in]  timNb   The timer number
 *
 * \return  The counter value
 *********************************************************/
inline uint32_t DRV_TIMER_GetCounter(drvTimerNumber_t timNb)
{
    return m_TIMERList[timNb].timer->RegsAddr->TIM.all;
}
/** \} */
/******************************************************** EOF *******************************************************/

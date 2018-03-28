/****************************************************** COMECA *******************************************************
 *  \author		tedie.cedric
 *  \date		28 mars 2018
 *  \addtogroup	TODO
 *  \{
 ********************************************************************************************************************/
/*********************************************************************************************************************
 *  \file		drv_timer.c
 *  
 *  \brief		TODO
 *
 *  \details	
 *
 ********************************************************************************************************************/

/* Includes --------------------------------------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>

#include "F2837xD_device.h"

#include "drv_timer.h"

/* Macro definition ------------------------------------------------------------------------------------------------*/
/* Constant definition ---------------------------------------------------------------------------------------------*/
/* Type definition  ------------------------------------------------------------------------------------------------*/

typedef struct
{
    volatile struct CPUTIMER_REGS *timerReg;

    drvTimerIsrCallback_t cbTimerEnd;
    void* pData;

    float timeoutVal_us;

    bool initOk;

}TIMERHandle_t;

/* Public variables ------------------------------------------------------------------------------------------------*/
/* Private variables -----------------------------------------------------------------------------------------------*/
static TIMERHandle_t m_TIMERList[NB_TIMER] =
{
     {
      .timerReg = &CpuTimer0Regs,
      .initOk = false
     },
     {
      .timerReg = &CpuTimer1Regs,
      .initOk = false
     },
     {
      .timerReg = &CpuTimer2Regs,
      .initOk = false
     },
};

/* Private functions prototypes ------------------------------------------------------------------------------------*/
/* Private functions -----------------------------------------------------------------------------------------------*/
/**********************************************************
 * \brief
 *
 * \return
 *********************************************************/
interrupt void timer0_isr(void)
{
    m_TIMERList[TIMER0].cbTimerEnd(m_TIMERList[TIMER0].pData);
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

/**********************************************************
 * \brief
 *
 * \return
 *********************************************************/
interrupt void timer1_isr(void)
{
}

/**********************************************************
 * \brief
 *
 * \return
 *********************************************************/
interrupt void timer2_isr(void)
{
}

/* Public functions ------------------------------------------------------------------------------------------------*/

/**********************************************************
 * \brief 
 *
 * \param [in]  
 * \param [out]  
 *
 * \return
 *********************************************************/
drvTimerReturn_t DRV_TIMER_Init(drvTimerNumber_t timNb, float period_us, bool autoreload, drvTimerIsrCallback_t cbTimerEnd, void* pCallbackData)
{
    drvTimerReturn_t ret = DRV_TIMER_SUCCESS;
    TIMERHandle_t *pHandle = &m_TIMERList[timNb];

    if(pHandle->initOk)
    {
        return DRV_TIMER_ALREADY_INIT;
    }

    switch (timNb)
    {
        case TIMER0:
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.TIMER0_INT = &timer0_isr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
            break;
        case TIMER1:
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.TIMER1_INT = &timer1_isr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
            break;
        case TIMER2:
            EALLOW;  // This is needed to write to EALLOW protected registers
            PieVectTable.TIMER2_INT = &timer2_isr;
            EDIS;    // This is needed to disable write to EALLOW protected registers
            break;
        default:
            return DRV_TIMER_BAD_CONFIG;
            break;
    }

    // Be sure that InitCpuTimers() was called before
    pHandle->timeoutVal_us = period_us;

    //TODO CPU FREQ
    ConfigCpuTimer(pHandle->timerReg, 200, period_us);

}

/** \} */
/******************************************************** EOF *******************************************************/

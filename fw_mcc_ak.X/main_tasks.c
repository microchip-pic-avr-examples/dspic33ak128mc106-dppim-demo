//=======================================================================================================
// Copyright(c) 2018 Microchip Technology Inc. and its subsidiaries.
// Subject to your compliance with these terms, you may use Microchip software and any derivatives
// exclusively with Microchip products. It is your responsibility to comply with third party license
// terms applicable to your use of third-party software (including open source software) that may
// accompany Microchip software.
// THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
// APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
// FITNESS FOR A PARTICULAR PURPOSE.
// IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
// LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
// MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
// ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
// EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
//=======================================================================================================

//=======================================================================================================
// @file main_tasks.c
//
// @brief contains the application specific tasks that are called regularly by the os_scheduler
//        two different timings priorities are available:
//          1. 1ms Tasks called from the os_scheduler interrupt
//              the jitter that you will have in the 1ms realtime tasks called by the interrupt depends
//              on other interrupts that have a higher interrupt priority
//          2. 1ms, 10ms, 100ms, 1s Tasks called from the main loop
//              these tasks are for soft realtime and not for hard realtime
//              so in average they are called with the required timing but the jitter can be very huge,
//              depending on the calls before.
//              use this for your non-timing critical application state machines
//
// @note    you might consider to implement a watchdog and put the watchdog triggering into some Task
//
// @version v1.0
// @date 2019-08-09
// @author M52409
//
//=======================================================================================================

#include <stdint.h>
#include <stddef.h>
#include <xc.h>
#include "project_settings.h"
#include "os/os_sys_time.h"
#include "os/os_scheduler.h"

#include "sources/device/dev_led.h"
#include "sources/app/App_PBV_Demo_Frame_Map.h"
#include "sources/app/app_PBV_interface.h"

#include "sources/driver/drv_adc.h"

static OS_SYSTIME_t sysTime;
//=======================================================================================================
//
//                          put your application specific code in the following functions:
//                              choose wisely between real-time and non-realtime!
//
//  Interrupt Realtime Functions:
//  Tasks_Realtime_1ms  :   is called by the interrupt every ms - for time critical low jitter stuff
//
//
//  Mainloop Non-Realtime Functions:
//  Tasks_1ms           :   function is called by the main loop in average every 1ms
//  Tasks_10ms          :   function is called by the main loop in average every 10ms
//  Tasks_100ms         :   function is called by the main loop in average every 100ms
//  Tasks_1s            :   function is called by the main loop in average every second
//
//  @note there could be some jitter here because it is not called directly by a timer interrupt
//        the timing in average is exact (keep in mind: in average), the jitter depends on the
//        called functions before
//=======================================================================================================

#if OS_USE_SCHEDULER_100us == 1
//=======================================================================================================
//  @brief  Tasks_Realtime_100us gets called directly from the timer interrupt every 100 �s
//  @note   keep this routine as short as possible
//=======================================================================================================
/* The task functions would be written by the user who uses this scheduler in 
 the application.  Hence 65 D is being excluded. */
/* LDRA_EXCLUDE 65 D */
void Tasks_Realtime_100us(void)
{
    // put your application specific code here that needs to be called every 100 micro seconds from the interrupt
    // example: Drv_TestPin_Toggle(DBG_PIN1);
	
}
#endif /* OS_USE_SCHEDULER_100us */
//=======================================================================================================
//  @brief  Tasks_Realtime_1ms gets called directly from the timer interrupt every millisecond
//  @note   keep this routine as short as possible
//=======================================================================================================
/* The task functions would be written by the user who uses this scheduler in 
 the application.  Hence 65 D is being excluded. */
/* LDRA_EXCLUDE 65 D */
void Tasks_Realtime_1ms(void)
{
}

#if OS_USE_SCHEDULER_100us == 1
//=======================================================================================================
//  @brief  Tasks_100us gets called every 100�s, put your things in it that need to be called regularly
//  @note   there could be some jitter here because it is not called directly by a timer interrupt
//=======================================================================================================
/* LDRA_EXCLUDE 65 D */
void Tasks_100us(void)
{
    app_PBV_Task_100us();
}
#endif /* OS_USE_SCHEDULER_100us */
//=======================================================================================================
//  @brief  Tasks_1ms gets called every millisecond, put your things in it that need to be called regularly
//  @note   there could be some jitter here because it is not called directly by a timer interrupt
//=======================================================================================================
/* LDRA_EXCLUDE 65 D */
void Tasks_1ms(void)
{
//    App_ExampleSomethingOne_1ms();
//    App_ExampleSomethingTwo_1ms();
    drv_adc_Task_1ms();
}

//=======================================================================================================
//  @brief  Tasks_10ms gets called every 10ms, put your things in it that need to be called regularly
//  @note   there could be some jitter here because it is not called directly by a timer interrupt
//=======================================================================================================
/* LDRA_EXCLUDE 65 D */
void Tasks_10ms(void)
{
    // put your application specific code here that needs to be called every 10 milliseconds
    // App_Example_CheckButtons_1ms();
    app_PBV_Task_10ms();
    app_PBV_Demo_Task_10ms();
}

extern uint16_t os_resetCause;
//=======================================================================================================
//  @brief  Tasks_100ms gets called every 100 ms, put your things in it that need to be called regularly
//  @note   there could be some jitter here because it is not called directly by a timer interrupt
//=======================================================================================================
void Tasks_100ms(void)
{
    /* LDRA_EXCLUDE 8 D */
    // put your application specific code here that needs to be called every 100 milliseconds
    Dev_LED_Task_100ms();
}

//=======================================================================================================
//  @brief  Tasks_1s gets called every second, put your things in it that need to be called regularly
//  @note   there could be some jitter here because it is not called directly by a timer interrupt
//=======================================================================================================
void Tasks_1s(void)
{
    // put your application specific code here that needs to be called every second
    app_PBV_Demo_Task_1s();
}

//=======================================================================================================
//  @brief  Tasks_Background gets called all the time when no other of the above tasks are being called
//  @note   call this function when you want to implement your own timing or get code called as often
//          as possible. You can also put your timing variables into Tasks_Realtime_100us or
//          Tasks_Realtime_1ms. This way you get accurate timing variables that you can use here.
//=======================================================================================================
/* LDRA_EXCLUDE 65 D */
void Tasks_Background(void)
{
    // put your application specific code here that needs to be called in the background.
    // your application needs to take care of it's timing.
    
}

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include <stdio.h>
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/timer/tmr1.h"
#include "mcc_generated_files/system/pins.h"

#include "sources/os/os.h"
#include "sources/device/dev_led.h"
#include "sources/app/App_PBV_Demo_Frame_Map.h"


#include "mcc_generated_files/uart/uart1.h"
#include "mcc_generated_files/pwm_hs/pwm.h"
#include "mcc_generated_files/adc/adc1.h"
#include "mcc_generated_files/adc/adc2.h"










    

//void TMR_1_Callback(void);

/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();
    
    TMR1_TimeoutCallbackRegister (TMR1_CallBack);
    PWM_Enable();
    OS_Init();
    app_PBV_Demo_init();
    Dev_LED_Init();
    //printf("uart works!");
    OS_Scheduler_RunForever();
    while(1)
    {
        
    }    
}

//void TMR_1_Callback(void) {
//    if(++counter > 5000) {
//        LED_GREEN_Toggle();
//        LED_DP_PIM_Toggle();
//        LED_RED_Toggle();
//        counter=0;
//    }
//    
//    if (++counter_100us_UART > 500) // every 50ms
//    {
//        Uart_Tx[0] = (0x55);
//        Uart_Tx[1] = (0x00);
//        Uart_Tx[2] = (0x01);
//        Uart_Tx[3] = (0x00);
//        Uart_Tx[4] = (0x0C);
//        
//        Uart_Tx[5] = (uint8_t) ( (adc_val.TP5 & 0x0000FF00) >> 8);
//        Uart_Tx[6] = (uint8_t) ( (adc_val.TP5 & 0x000000FF) );
//        Uart_Tx[7] = (uint8_t) ( (adc_val.TP12 & 0x0000FF00) >> 8);
//        Uart_Tx[8] = (uint8_t) ( (adc_val.TP12 & 0x000000FF) );
//        
//        Uart_Tx[9] = (uint8_t) ( (adc_val.TP13 & 0x0000FF00) >> 8);
//        Uart_Tx[10] = (uint8_t) ( (adc_val.TP13 & 0x000000FF) );
//                
//        Uart_Tx[11] = (uint8_t) ( (adc_val.TP14 & 0x0000FF00) >> 8);
//        Uart_Tx[12] = (uint8_t) ( (adc_val.TP14 & 0x000000FF) );
//        
//        Uart_Tx[13] = (uint8_t) ( (pwm_dc_val & 0x0000FF00) >> 8);
//        Uart_Tx[14] = (uint8_t) ( (pwm_dc_val & 0x000000FF) );
//        Uart_Tx[15] = (0x0C);
//        Uart_Tx[16] = (0x0C);
//
//        Uart_Tx[17] = (0x00);
//        Uart_Tx[18] = (0x00);
//        Uart_Tx[19] = (0x0D);
//
//        counter_100us_UART = 0;
//        UartTxCounter = 0;
//        UartTxDelayCounter = 0;
//    }
//
//    if ((UartTxCounter < 20) && (UartTxDelayCounter++ > 5)) //every 500us
//    {
//        //        TP54_RD10_Toggle();
//        UART1_Write(Uart_Tx[UartTxCounter++]);
//        UartTxDelayCounter = 0;
//    }
//    
//    if (adc_trigger_counter++ > 50) // every 5ms
//    {
////        AD1SWTRGbits.CH9TRG = 1;
////        AD1SWTRGbits.CH11TRG = 1;
////        AD2SWTRGbits.CH6TRG = 1;
////        AD2SWTRGbits.CH8TRG = 1;
//        ADC1_ChannelSoftwareTriggerEnable (0);
//        ADC1_ChannelSoftwareTriggerEnable (1);
//        
//        ADC2_ChannelSoftwareTriggerEnable (0);
//        ADC2_ChannelSoftwareTriggerEnable (1);
//        adc_trigger_counter = 0;
//    }
//    
//    if (counter_100us_PWM_DC_update++ > 50) // update Duty cycle every 5ms
//
//    {
//        if (adc_val.TP5 * 4 > PG1PER)   // PER 15984; 
//            pwm_dc_val = PG1PER  ;        
//        else if (adc_val.TP5 * 4 < 128)   
//            pwm_dc_val = 128  ;
//        else
//            pwm_dc_val = adc_val.TP5 * 4; 
//        
//        PWM_DutyCycleSet(1, pwm_dc_val);
//    }
//}




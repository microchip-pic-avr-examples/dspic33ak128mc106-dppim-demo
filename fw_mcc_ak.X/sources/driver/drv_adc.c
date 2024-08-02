/**
 * @ingroup   version-information
 * @file      drv_adc.c
 * @details   <b>Description</b><br>This file defines the periodic task as well ISRs for all ADCs.
 * @author    M70027
 * @author    M70027
 * @version   1.0
 * @date      2024
 * @warning   Improper use can crash your application.
 * @copyright 
 */


#include "drv_adc.h"

/*********************************************************************************
 * @ingroup adc-drv-private-variables
 * @var     ADC_VALUES_t
 * @brief   adc values object
 * @details 'adc_val' is the object providing access to all the adc values.
 **********************************************************************************/
ADC_VALUES_t adc_val;
ADC_VALUES_t * adc_val_pt = &adc_val;


/*********************************************************************************
 * @ingroup adc-drv-private
 * @var     counter
 * @brief   ticking away
 * @details 
 *          to sample every 5ms
 **********************************************************************************/
uint8_t static counter = 0;



/***********************************************************************************
 * @ingroup drv-adc-public-functions
 * @fn     drv_adc_Task_1ms
 * @param  void
 * @return nothing
 * @brief this function needs to be called every 1ms
 *        it contains the code to trigger the ADC from software
 * @details
 *   this function needs to be called every 1ms. It triggers the ADC conversion. Since all are
 * enabled through Interrrupts, the sampled result is stored in the adc data object as soon as 
 * it is available.
 * it also uses the PG1PER (Period register of the PWM generator 1 and ADV value at TP5 to 
 * update the duty cycle)
  **********************************************************************************/

void drv_adc_Task_1ms(){
    
    ADC1_ChannelSoftwareTriggerEnable (0);
    ADC1_ChannelSoftwareTriggerEnable (1);

    ADC2_ChannelSoftwareTriggerEnable (0);
    ADC2_ChannelSoftwareTriggerEnable (1);
    
    
    // every 5ms
    if (counter++>4){
        if (adc_val.TP5 * 4 > PG1PER)   // PER 15984; 
            adc_val.pwm_dc_val = PG1PER  ;        
        else if (adc_val.TP5 * 4 < 128)   
            adc_val.pwm_dc_val = 128  ;
        else
            adc_val.pwm_dc_val = adc_val.TP5 * 4; 
        
        PWM_DutyCycleSet(1, adc_val.pwm_dc_val);
        counter = 0;
    }
}

/***********************************************************************************
 * @ingroup drv-adc-internal-functions
 * @fn     AD1CH9Interrupt
 * @param  void
 * @return nothing
 * @brief ADC 1 Channel 9 Interrupt Service Routine
  **********************************************************************************/
void __attribute__((interrupt)) _AD1CH9Interrupt(void)
{

  adc_val.TP13 = AD1CH9DATA;
 
   IFS5bits.AD1CH9IF = 0;
  
}
/***********************************************************************************
 * @ingroup drv-adc-internal-functions
 * @fn     AD1CH11Interrupt
 * @param  void
 * @return nothing
 * @brief ADC 1 Channel 11 Interrupt Service Routine
  **********************************************************************************/
void __attribute__((interrupt)) _AD1CH11Interrupt(void)
{
  adc_val.TP12 = AD1CH11DATA;
      
  IFS5bits.AD1CH11IF = 0;

}
/***********************************************************************************
 * @ingroup drv-adc-internal-functions
 * @fn     AD2CH6Interrupt
 * @param  void
 * @return nothing
 * @brief ADC 2 Channel 6 Interrupt Service Routine
  **********************************************************************************/
void __attribute__((interrupt)) _AD2CH6Interrupt(void)
{
  adc_val.TP5 = AD2CH6DATA;
      
  IFS6bits.AD2CH6IF = 0;
 
}
/***********************************************************************************
 * @ingroup drv-adc-internal-functions
 * @fn     AD2CH8Interrupt
 * @param  void
 * @return nothing
 * @brief ADC 2 Channel 8 Interrupt Service Routine
  **********************************************************************************/
void __attribute__((interrupt)) _AD2CH8Interrupt(void)
{
  adc_val.TP14 = AD2CH8DATA; 
  IFS6bits.AD2CH8IF = 0;
}


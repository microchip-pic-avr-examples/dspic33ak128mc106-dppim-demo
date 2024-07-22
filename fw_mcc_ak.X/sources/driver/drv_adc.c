#include "drv_adc.h"

ADC_VALUES_t adc_val;

ADC_VALUES_t * adc_val_pt = &adc_val;

uint8_t static counter = 0;

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


void __attribute__((interrupt)) _AD1CH9Interrupt(void)
{

  adc_val.TP13 = AD1CH9DATA;
 
   IFS5bits.AD1CH9IF = 0;
  
}

void __attribute__((interrupt)) _AD1CH11Interrupt(void)
{
  adc_val.TP12 = AD1CH11DATA;
      
  IFS5bits.AD1CH11IF = 0;

}

void __attribute__((interrupt)) _AD2CH6Interrupt(void)
{
  adc_val.TP5 = AD2CH6DATA;
      
  IFS6bits.AD2CH6IF = 0;
 
}
void __attribute__((interrupt)) _AD2CH8Interrupt(void)
{
  adc_val.TP14 = AD2CH8DATA; 
  IFS6bits.AD2CH8IF = 0;
}


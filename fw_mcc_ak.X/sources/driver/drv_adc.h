/* 
 * File:   drv_adc.h
 * Author: M70027
 *
 * Created on July 22, 2024, 2:44 PM
 */

#ifndef DRV_ADC_H
#define	DRV_ADC_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "../../mcc_generated_files/adc/adc1.h"
#include "../../mcc_generated_files/adc/adc2.h"
#include "../../mcc_generated_files/pwm_hs/pwm.h"
    
typedef struct ADC_VALUES_s
{
    uint16_t TP5;
    uint16_t TP12;
    uint16_t TP13;
    uint16_t TP14;
    uint16_t pwm_dc_val;
} ADC_VALUES_t;

extern ADC_VALUES_t * adc_val_pt;
    
void drv_adc_Task_1ms(void);
    


#ifdef	__cplusplus
}
#endif

#endif	/* DRV_ADC_H */


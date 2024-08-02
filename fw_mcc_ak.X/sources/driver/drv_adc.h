/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/**
 * @file    dev_led.h
 * @brief   ADC driver
 * @author  M70027
 * @date    05/02/2024
 */
 
// This is a guard condition so that contents of this file are not included
// more than once.  

#ifndef DRV_ADC_H
#define	DRV_ADC_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "../../mcc_generated_files/adc/adc1.h"
#include "../../mcc_generated_files/adc/adc2.h"
#include "../../mcc_generated_files/pwm_hs/pwm.h"


/*********************************************************************************
 * @ingroup DRV_ADC
 * @struct ADC_VALUES_t
 * @brief   
 * @details ADC data structure  
 *********************************************************************************/    
typedef struct ADC_VALUES_s
{
    uint16_t TP5;
    uint16_t TP12;
    uint16_t TP13;
    uint16_t TP14;
    uint16_t pwm_dc_val;
} ADC_VALUES_t;


/*********************************************************************************
 * @ingroup DRV_ADC
 * @var     adc_val_pt
 * @brief   ADC object pointer external
 * @details pointer to the Object 'ADC_VALUES_t', providing access to all the ADC Values
 *          To access it, add the header file to the project, and 
 *          then the pointer can be used to access the ADC_VALUES_t members.
 **********************************************************************************/
extern ADC_VALUES_t * adc_val_pt;


///< public function    
void drv_adc_Task_1ms(void);
    


#ifdef	__cplusplus
}
#endif

#endif	/* DRV_ADC_H */


/**
 * ADC2 Generated Driver Source File
 * 
 * @file      adc2.c
 *            
 * @ingroup   adcdriver
 *            
 * @brief     This is the generated driver source file for ADC2 driver        
 *
 * @skipline @version   PLIB Version 1.0.1
 *           
 * @skipline  Device : 
*/

/*disclaimer*/

// Section: Included Files
#include <stddef.h>
#include "../adc2.h"

// Section: File specific functions

static void (*ADC2_ChannelHandler)(enum ADC2_CHANNEL channel, uint16_t adcVal) = NULL;
static void (*ADC2_Result32BitChannelHandler)(enum ADC2_CHANNEL channel, uint32_t adcVal) = NULL;
static void (*ADC2_ComparatorHandler)(enum ADC2_CMP comparator) = NULL;

// Section: File specific data type definitions

/**
 @ingroup  adcdriver
 @enum     ADC2_PWM_TRIG_SRCS
 @brief    Defines the PWM ADC TRIGGER sources available for the module to use.
*/
enum ADC2_PWM_TRIG_SRCS {
    PWM4_TRIGGER2 = 0xb, 
    PWM4_TRIGGER1 = 0xa, 
    PWM3_TRIGGER2 = 0x9, 
};

//Defines an object for ADC_MULTICORE.
static const struct ADC_MULTICORE adc2Multicore = {
    .ChannelSoftwareTriggerEnable           = &ADC2_ChannelSoftwareTriggerEnable,
    .ChannelSoftwareTriggerDisable          = &ADC2_ChannelSoftwareTriggerDisable,
    .SampleCountGet                         = NULL,
    .SampleCountStatusGet                   = NULL,
    .ChannelTasks                           = &ADC2_ChannelTasks, 
    .ComparatorTasks                        = NULL,
    .IndividualChannelInterruptEnable       = &ADC2_IndividualChannelInterruptEnable,
    .IndividualChannelInterruptDisable      = &ADC2_IndividualChannelInterruptDisable,
    .IndividualChannelInterruptFlagClear    = &ADC2_IndividualChannelInterruptFlagClear,
    .IndividualChannelInterruptPrioritySet  = &ADC2_IndividualChannelInterruptPrioritySet,
    .ChannelCallbackRegister                = &ADC2_ChannelCallbackRegister,
    .Result32BitChannelCallbackRegister     = &ADC2_Result32BitChannelCallbackRegister,
    .ComparatorCallbackRegister             = &ADC2_ComparatorCallbackRegister,
    .CorePowerEnable                        = NULL,
    .SharedCorePowerEnable                  = &ADC2_SharedCorePowerEnable,
    .CoreCalibration                        = NULL,
    .SharedCoreCalibration                  = &ADC2_SharedCoreCalibration,
    .PWMTriggerSourceSet                    = &ADC2_PWMTriggerSourceSet
};

//Defines an object for ADC_INTERFACE.

const struct ADC_INTERFACE ADC2 = {
    .Initialize             = &ADC2_Initialize,
    .Deinitialize           = &ADC2_Deinitialize,
    .Enable                 = &ADC2_Enable,
    .Disable                = &ADC2_Disable,
    .SoftwareTriggerEnable  = &ADC2_SoftwareTriggerEnable,
    .SoftwareTriggerDisable = &ADC2_SoftwareTriggerDisable,
    .ChannelSelect          = NULL, 
    .ConversionResultGet    = &ADC2_ConversionResultGet,
    .SecondaryAccumulatorGet= NULL,
    .IsConversionComplete   = &ADC2_IsConversionComplete,
    .ResolutionSet          = NULL,
    .InterruptEnable        = NULL,
    .InterruptDisable       = NULL,
    .InterruptFlagClear     = NULL,
    .InterruptPrioritySet   = NULL,
    .CommonCallbackRegister = NULL,
    .Tasks                  = NULL,
    .adcMulticoreInterface = &adc2Multicore,
};

// Section: Driver Interface Function Definitions

void ADC2_Initialize(void)
{
    //CALCNT Wait for 2 activity free ADC clock cycles; BUFEN disabled; TSTEN disabled; SIDL disabled; ON enabled; STNDBY disabled; VREFMOD enabled; RPTCNT 1 ADC clock cycles between triggers; CALRATE Every second; ACALEN disabled; CALREQ Calibration cycle is not requested; 
    AD2CON = 0x28000UL;
    //DATAOVR 0x0; 
    AD2DATAOVR = 0x0UL;
    //CH0RDY disabled; CH1RDY disabled; CH2RDY disabled; CH3RDY disabled; CH4RDY disabled; CH5RDY disabled; CH6RDY disabled; CH7RDY disabled; CH8RDY disabled; CH9RDY disabled; CH10RDY disabled; CH11RDY disabled; CH12RDY disabled; CH13RDY disabled; CH14RDY disabled; CH15RDY disabled; CH16RDY disabled; CH17RDY disabled; CH18RDY disabled; CH19RDY disabled; 
    AD2STAT = 0x0UL;
    //CH0CMP disabled; CH1CMP disabled; CH2CMP disabled; CH3CMP disabled; CH4CMP disabled; CH5CMP disabled; CH6CMP disabled; CH7CMP disabled; CH8CMP disabled; CH9CMP disabled; CH10CMP disabled; CH11CMP disabled; CH12CMP disabled; CH13CMP disabled; CH14CMP disabled; CH15CMP disabled; CH16CMP disabled; CH17CMP disabled; CH18CMP disabled; CH19CMP disabled; 
    AD2CMPSTAT = 0x0UL;
    //CH0TRG disabled; CH1TRG disabled; CH2TRG disabled; CH3TRG disabled; CH4TRG disabled; CH5TRG disabled; CH6TRG disabled; CH7TRG disabled; CH8TRG disabled; CH9TRG disabled; CH10TRG disabled; CH11TRG disabled; CH12TRG disabled; CH13TRG disabled; CH14TRG disabled; CH15TRG disabled; CH16TRG disabled; CH17TRG disabled; CH18TRG disabled; CH19TRG disabled; 
    AD2SWTRG = 0x0UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH0CON = 0x0UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH1CON = 0x0UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH2CON = 0x0UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH3CON = 0x0UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH4CON = 0x0UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH5CON = 0x0UL;
    //TRG1SRC Software trigger initiated using ADnSWTRG register; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN6; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH6CON = 0x3001UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH7CON = 0x0UL;
    //TRG1SRC Software trigger initiated using ADnSWTRG register; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN8; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH8CON = 0x4001UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH9CON = 0x0UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH10CON = 0x0UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH11CON = 0x0UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH12CON = 0x0UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH13CON = 0x0UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH14CON = 0x0UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH15CON = 0x0UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH16CON = 0x0UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH17CON = 0x0UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH18CON = 0x0UL;
    //TRG1SRC ; SAMC 0.5 TAD; NINSEL disabled; LEFT Integer; PINSEL AD2AN0; DIFF disabled; CMPMOD NONE; TRG2SRC ; EIEN disabled; TRG1POL disabled; ACCRO disabled; ACCBRST disabled; ACCNUM 4 samples, 13 bits result; MODE Single sample initiated by TRG1SRC[4:0] trigger; 
    AD2CH19CON = 0x0UL;
    //CNT 0x0; 
    AD2CH0CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH1CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH2CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH3CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH4CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH5CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH6CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH7CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH8CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH9CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH10CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH11CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH12CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH13CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH14CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH15CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH16CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH17CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH18CNT = 0x0UL;
    //CNT 0x0; 
    AD2CH19CNT = 0x0UL;
    //CMPLO 0x0; 
    AD2CH0CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH1CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH2CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH3CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH4CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH5CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH6CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH7CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH8CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH9CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH10CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH11CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH12CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH13CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH14CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH15CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH16CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH17CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH18CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD2CH19CMPLO = 0x0UL;
    //CMPHI 0x0; 
    AD2CH0CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH1CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH2CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH3CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH4CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH5CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH6CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH7CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH8CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH9CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH10CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH11CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH12CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH13CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH14CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH15CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH16CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH17CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH18CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD2CH19CMPHI = 0x0UL;

    ADC2_ChannelCallbackRegister(&ADC2_ChannelCallback);
    ADC2_Result32BitChannelCallbackRegister(&ADC2_Result32BitChannelCallback);
    ADC2_ComparatorCallbackRegister(&ADC2_ComparatorCallback);
    
    // Clearing ADC2_Channel6 interrupt flag.
    IFS6bits.AD2CH6IF = 0U;
    // Enabling ADC2_Channel6 interrupt.
    IEC6bits.AD2CH6IE = 1U;
    // Clearing ADC2_Channel8 interrupt flag.
    IFS6bits.AD2CH8IF = 0U;
    // Enabling ADC2_Channel8 interrupt.
    IEC6bits.AD2CH8IE = 1U;
    
    // ADC Mode change to run mode
    ADC2_SharedCorePowerEnable();
}

void ADC2_Deinitialize (void)
{
    uint32_t  __attribute__ ((unused)) dummy; //buffers has to be read before clearing interrupt flags
    AD2CONbits.ON = 0U;
    
    dummy = AD2CH6DATA;
    IFS6bits.AD2CH6IF = 0U;
    IEC6bits.AD2CH6IE = 0U;
    
    dummy = AD2CH8DATA;
    IFS6bits.AD2CH8IF = 0U;
    IEC6bits.AD2CH8IE = 0U;
    
    AD2CON = 0x4A0000UL;
    AD2DATAOVR = 0x0UL;
    AD2STAT = 0x0UL;
    AD2CMPSTAT = 0x0UL;
    AD2SWTRG = 0x0UL;
    AD2CH0CON = 0x0UL;
    AD2CH1CON = 0x0UL;
    AD2CH2CON = 0x0UL;
    AD2CH3CON = 0x0UL;
    AD2CH4CON = 0x0UL;
    AD2CH5CON = 0x0UL;
    AD2CH6CON = 0x0UL;
    AD2CH7CON = 0x0UL;
    AD2CH8CON = 0x0UL;
    AD2CH9CON = 0x0UL;
    AD2CH10CON = 0x0UL;
    AD2CH11CON = 0x0UL;
    AD2CH12CON = 0x0UL;
    AD2CH13CON = 0x0UL;
    AD2CH14CON = 0x0UL;
    AD2CH15CON = 0x0UL;
    AD2CH16CON = 0x0UL;
    AD2CH17CON = 0x0UL;
    AD2CH18CON = 0x0UL;
    AD2CH19CON = 0x0UL;
    AD2CH0CNT = 0x0UL;
    AD2CH1CNT = 0x0UL;
    AD2CH2CNT = 0x0UL;
    AD2CH3CNT = 0x0UL;
    AD2CH4CNT = 0x0UL;
    AD2CH5CNT = 0x0UL;
    AD2CH6CNT = 0x0UL;
    AD2CH7CNT = 0x0UL;
    AD2CH8CNT = 0x0UL;
    AD2CH9CNT = 0x0UL;
    AD2CH10CNT = 0x0UL;
    AD2CH11CNT = 0x0UL;
    AD2CH12CNT = 0x0UL;
    AD2CH13CNT = 0x0UL;
    AD2CH14CNT = 0x0UL;
    AD2CH15CNT = 0x0UL;
    AD2CH16CNT = 0x0UL;
    AD2CH17CNT = 0x0UL;
    AD2CH18CNT = 0x0UL;
    AD2CH19CNT = 0x0UL;
    AD2CH0CMPLO = 0x0UL;
    AD2CH1CMPLO = 0x0UL;
    AD2CH2CMPLO = 0x0UL;
    AD2CH3CMPLO = 0x0UL;
    AD2CH4CMPLO = 0x0UL;
    AD2CH5CMPLO = 0x0UL;
    AD2CH6CMPLO = 0x0UL;
    AD2CH7CMPLO = 0x0UL;
    AD2CH8CMPLO = 0x0UL;
    AD2CH9CMPLO = 0x0UL;
    AD2CH10CMPLO = 0x0UL;
    AD2CH11CMPLO = 0x0UL;
    AD2CH12CMPLO = 0x0UL;
    AD2CH13CMPLO = 0x0UL;
    AD2CH14CMPLO = 0x0UL;
    AD2CH15CMPLO = 0x0UL;
    AD2CH16CMPLO = 0x0UL;
    AD2CH17CMPLO = 0x0UL;
    AD2CH18CMPLO = 0x0UL;
    AD2CH19CMPLO = 0x0UL;
    AD2CH0CMPHI = 0x0UL;
    AD2CH1CMPHI = 0x0UL;
    AD2CH2CMPHI = 0x0UL;
    AD2CH3CMPHI = 0x0UL;
    AD2CH4CMPHI = 0x0UL;
    AD2CH5CMPHI = 0x0UL;
    AD2CH6CMPHI = 0x0UL;
    AD2CH7CMPHI = 0x0UL;
    AD2CH8CMPHI = 0x0UL;
    AD2CH9CMPHI = 0x0UL;
    AD2CH10CMPHI = 0x0UL;
    AD2CH11CMPHI = 0x0UL;
    AD2CH12CMPHI = 0x0UL;
    AD2CH13CMPHI = 0x0UL;
    AD2CH14CMPHI = 0x0UL;
    AD2CH15CMPHI = 0x0UL;
    AD2CH16CMPHI = 0x0UL;
    AD2CH17CMPHI = 0x0UL;
    AD2CH18CMPHI = 0x0UL;
    AD2CH19CMPHI = 0x0UL;
}

void ADC2_SharedCorePowerEnable (void) 
{
    AD2CONbits.ON = 1U;   
    while(AD2CONbits.ADRDY == 0U)
    {
    }
}

void ADC2_SharedCoreCalibration (void) 
{
    AD2CONbits.CALREQ = 1U;    
    while(AD2CONbits.CALRDY == 0U)
    {
    }  
}

static uint16_t ADC2_TriggerSourceValueGet(enum ADC_PWM_INSTANCE pwmInstance, enum ADC_PWM_TRIGGERS triggerNumber)
{
    uint16_t adcTriggerSourceValue = 0x0U;
    switch(pwmInstance)
    {
        case ADC_PWM_GENERATOR_4:
                if(triggerNumber == ADC_PWM_TRIGGER_1)
                {
                    adcTriggerSourceValue = PWM4_TRIGGER1;
                }
                else if(triggerNumber == ADC_PWM_TRIGGER_2)
                {
                    adcTriggerSourceValue = PWM4_TRIGGER2;
                }
                else
                {
                }
                break;
        case ADC_PWM_GENERATOR_3:
                if(triggerNumber == ADC_PWM_TRIGGER_2)
                {
                    adcTriggerSourceValue = PWM3_TRIGGER2;
                }
                break;
         default:
                break;
    }
    return adcTriggerSourceValue;
}

void ADC2_PWMTriggerSourceSet(enum ADC2_CHANNEL channel, enum ADC_PWM_INSTANCE pwmInstance, enum ADC_PWM_TRIGGERS triggerNumber)
{
    uint16_t adcTriggerValue;
    adcTriggerValue= ADC2_TriggerSourceValueGet(pwmInstance, triggerNumber);
    switch(channel)
    {
        case ADC2_Channel6:
                AD2SWTRGbits.CH6TRG = adcTriggerValue;
                break;
        case ADC2_Channel8:
                AD2SWTRGbits.CH8TRG = adcTriggerValue;
                break;
        default:
                break;
    }
}

void ADC2_ChannelCallbackRegister(void(*callback)(enum ADC2_CHANNEL channel, uint16_t adcVal))
{
    if(NULL != callback)
    {
        ADC2_ChannelHandler = callback;
    }
}

void __attribute__ ((weak)) ADC2_ChannelCallback (enum ADC2_CHANNEL channel, uint16_t adcVal)
{ 
    (void)channel;
    (void)adcVal;
} 

void ADC2_Result32BitChannelCallbackRegister(void(*callback)(enum ADC2_CHANNEL channel, uint32_t adcVal))
{
    if(NULL != callback)
    {
        ADC2_Result32BitChannelHandler = callback;
    }
}

void __attribute__ ((weak)) ADC2_Result32BitChannelCallback (enum ADC2_CHANNEL channel, uint32_t adcVal)
{ 
    (void)channel;
    (void)adcVal;
} 


void __attribute__ ( ( __interrupt__ , auto_psv, weak ) ) _AD2CH6Interrupt ( void )
{
    uint32_t valADC2_Channel6;
    //Read the ADC value from the ADCBUF
    valADC2_Channel6 = AD2CH6DATA;

    if(NULL != ADC2_ChannelHandler)
    {
        (*ADC2_ChannelHandler)(ADC2_Channel6, valADC2_Channel6);
    }
    if(NULL != ADC2_Result32BitChannelHandler)
    {
        (*ADC2_Result32BitChannelHandler)(ADC2_Channel6, valADC2_Channel6);
    }

    //clear the ADC2_Channel6 interrupt flag
    IFS6bits.AD2CH6IF = 0U;
}

void __attribute__ ( ( __interrupt__ , auto_psv, weak ) ) _AD2CH8Interrupt ( void )
{
    uint32_t valADC2_Channel8;
    //Read the ADC value from the ADCBUF
    valADC2_Channel8 = AD2CH8DATA;

    if(NULL != ADC2_ChannelHandler)
    {
        (*ADC2_ChannelHandler)(ADC2_Channel8, valADC2_Channel8);
    }
    if(NULL != ADC2_Result32BitChannelHandler)
    {
        (*ADC2_Result32BitChannelHandler)(ADC2_Channel8, valADC2_Channel8);
    }

    //clear the ADC2_Channel8 interrupt flag
    IFS6bits.AD2CH8IF = 0U;
}


void __attribute__ ((weak)) ADC2_ChannelTasks (enum ADC2_CHANNEL channel)
{
    uint32_t adcVal;
    
    switch(channel)
    {   
        case ADC2_Channel6:
            if((bool)AD2STATbits.CH6RDY == 1U)
            {
                //Read the ADC value from the ADCBUF
                adcVal = AD2CH6DATA;

                if(NULL != ADC2_ChannelHandler)
                {
                    (*ADC2_ChannelHandler)(channel, adcVal);
                }
                if(NULL != ADC2_Result32BitChannelHandler)
                {
                    (*ADC2_Result32BitChannelHandler)(channel, adcVal);
                }
            }
            break;
        case ADC2_Channel8:
            if((bool)AD2STATbits.CH8RDY == 1U)
            {
                //Read the ADC value from the ADCBUF
                adcVal = AD2CH8DATA;

                if(NULL != ADC2_ChannelHandler)
                {
                    (*ADC2_ChannelHandler)(channel, adcVal);
                }
                if(NULL != ADC2_Result32BitChannelHandler)
                {
                    (*ADC2_Result32BitChannelHandler)(channel, adcVal);
                }
            }
            break;
        default:
            break;
    }            
}

void ADC2_ComparatorCallbackRegister(void(*callback)(enum ADC2_CMP comparator))
{
    if(NULL != callback)
    {
        ADC2_ComparatorHandler = callback;
    }
}

void __attribute__ ((weak)) ADC2_ComparatorCallback (enum ADC2_CMP comparator)
{ 
    (void)comparator;
} 




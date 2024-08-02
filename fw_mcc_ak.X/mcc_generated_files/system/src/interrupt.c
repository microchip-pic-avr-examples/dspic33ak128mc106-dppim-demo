/**
 * INTERRUPT Generated Driver Source File 
 * 
 * @file      interrupt.c
 *            
 * @ingroup   interruptdriver
 *            
 * @brief     This is the generated driver source file for INTERRUPT driver          
 *
 * @skipline @version   PLIB Version 1.0.1
 *            
 * @skipline  Device : dsPIC33AK128MC106
*/

/*
� [2024] Microchip Technology Inc. and its subsidiaries.

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

// Section: Includes
#include "../interrupt.h"

// Section: Driver Interface Function Definitions

void INTERRUPT_Initialize(void)
{
    // AD1CH11: ADC 1 data channel 11 done.
    // Priority: 1
    IPC21bits.AD1CH11IP = 1;
    
    // AD1CH9: ADC 1 data channel 9 done.
    // Priority: 1
    IPC20bits.AD1CH9IP = 1;
    
    // AD2CH6: ADC 2 data channel 6 done.
    // Priority: 1
    IPC25bits.AD2CH6IP = 1;
    
    // AD2CH8: ADC 2 data channel 8 done.
    // Priority: 1
    IPC25bits.AD2CH8IP = 1;
    
    // T1: Timer 1 Interrupt.
    // Priority: 1
    IPC6bits.T1IP = 1;
    
    // U1EVT: UART 1 event.
    // Priority: 1
    IPC11bits.U1EVTIP = 1;
    
    // U1E: UART 1 error.
    // Priority: 1
    IPC11bits.U1EIP = 1;
    
    // U1TX: UART 1 TX.
    // Priority: 1
    IPC11bits.U1TXIP = 1;
    
    // U1RX: UART 1 RX.
    // Priority: 1
    IPC11bits.U1RXIP = 1;
    
}

void INTERRUPT_Deinitialize(void)
{
    //POR default value of priority
    IPC21bits.AD1CH11IP = 4;
    IPC20bits.AD1CH9IP = 4;
    IPC25bits.AD2CH6IP = 4;
    IPC25bits.AD2CH8IP = 4;
    IPC6bits.T1IP = 4;
    IPC11bits.U1EVTIP = 4;
    IPC11bits.U1EIP = 4;
    IPC11bits.U1TXIP = 4;
    IPC11bits.U1RXIP = 4;
}

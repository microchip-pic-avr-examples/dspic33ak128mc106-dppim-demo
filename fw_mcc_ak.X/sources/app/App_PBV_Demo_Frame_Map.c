/*
    (c) 2022 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

// MCC header files

// other header files
#include "App_PBV_Demo_Frame_Map.h"
#include "../../mcc_generated_files/system/pins.h"
#include "../device/dev_led.h"
#include "../driver/drv_adc.h"

/*********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @def     FIRMWARE_PROTOCOL_ID
 * @brief   Protocol ID on which firmware ID is sent
 **********************************************************************************/
#define FIRMWARE_PROTOCOL_ID            0x1000          ///< Firmware ID

/*********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @def     PBV_GUI_TO_SYSTEM_ID
 * @brief   ID on which data is received
 **********************************************************************************/
#define PBV_GUI_TO_SYSTEM_ID            0x202           ///< ID on which data is received.  

/*********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @def     PBV_SYSTEM_TO_GUI_ID
 * @brief   ID on which data is sent
 **********************************************************************************/
#define PBV_SYSTEM_TO_GUI_ID            0x205           ///< ID on which data is sent. 

/*********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @def     PBV_SYSTEM_TO_GUI_ID
 * @brief   ID on which log data is sent
 **********************************************************************************/
#define PBV_SYSTEM_TO_GUI_ASCII_ID      0x206           ///< ID on which log data is sent. 

/***********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @struct  App_PBV_Demo_TX
 * @brief   Application TX object
 **********************************************************************************/
static PBV_Datatype_TX_t App_PBV_Demo_TX;          ///< Application TX object

/***********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @struct  App_PBV_Demo_RX
 * @brief   Application RX object
 **********************************************************************************/
static PBV_Datatype_RX_t App_PBV_Demo_RX;          ///< Application RX object

/***********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @struct  App_PBV_Demo_ASCII
 * @brief   Application TX object for ascii
 **********************************************************************************/
static PBV_Datatype_TX_t App_PBV_Demo_ASCII;       ///< Application TX object for ascii

/***********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @def  App_PBV_Demo_TX_ptr
 * @brief   pointer to the object. this is if you want to extend the interface, and 
 * have a get function to get the pointer and transmit data from other files.
 **********************************************************************************/
static PBV_Datatype_TX_t * App_PBV_Demo_TX_Ptr = &App_PBV_Demo_TX;        ///< Application TX object pointer

/***********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @def  App_PBV_Demo_RX_Ptr
 * @brief   pointer to the RX object. for uniform look and feel
 **********************************************************************************/
static PBV_Datatype_RX_t * App_PBV_Demo_RX_Ptr = &App_PBV_Demo_RX;        ///< Application RX object pointer

/***********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @def  App_PBV_Demo_ASCII_Ptr
 * @brief   pointer to the Ascii object. This can be used to send log data from other 
 * files by getting this pointer
 **********************************************************************************/
static PBV_Datatype_TX_t * App_PBV_Demo_ASCII_Ptr = &App_PBV_Demo_ASCII;  ///< Application TX object ascii pointer


/***********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @var     buffer_sixteen_bit 
 * @brief   buffer for 16 byte data for TX
 **********************************************************************************/
uint16_t buffer_sixteen_bit[32];

/***********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @var     buffer_eight_bit 
 * @brief   buffer for 8 bit data for TX
 **********************************************************************************/
uint8_t buffer_eight_bit[64];

/***********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @var     buffer_eight_bit_rx 
 * @brief   buffer for 8 bit data for RX
 **********************************************************************************/
uint16_t buffer_eight_bit_rx[32];

/***********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @var     counter 
 * @brief   a variable to increase cycle count for the TX message
 **********************************************************************************/
static uint32_t counter = 0;

/***********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @var     flag
 * @brief   flag to switch between firmware version TX on ID 1000, and log messages on ID 206
 **********************************************************************************/
static uint8_t flag = 0;
/***********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @var     slider_value
 * @brief   where the slider value from GUI is stored for further processing
 **********************************************************************************/
static uint16_t slider_value = 0;

/***********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @var     up_count
 * @brief   up counter
 **********************************************************************************/
static uint16_t up_count    =   0;

/***********************************************************************************
 * @ingroup PBV_DEMO_FRAME_MAP
 * @var     down_count
 * @brief   down counter 
 **********************************************************************************/
static uint16_t down_count  = 65535;


/***********************************************************************************
 * Private Function Call Prototypes
 **********************************************************************************/
uint16_t app_Concatenate_Bank1(void);
uint16_t app_Concatenate_Bank2(void);
void app_Generate_data(void);
void app_Develop_callback(uint16_t length, uint8_t * data);


/***********************************************************************************
 * Public Functions Definitions
 **********************************************************************************/

/***********************************************************************************
 * @ingroup app_pbv_demo_public_function
 * @fn     app_PBV_Demo_init
 * @param  void
 * @return nothing
 * @brief this function initializes the app_pbv rx and tx objects and 
 * calls the app_pbv_init which links the CAN/RX objects
 **********************************************************************************/
void app_PBV_Demo_init(void)
{
    App_PBV_Demo_TX_Ptr->PBV_Protcol_ID        = PBV_SYSTEM_TO_GUI_ID;
    App_PBV_Demo_TX_Ptr->PBV_Signal_Ascii      = PBV_SIGNAL_MODE;
    App_PBV_Demo_TX_Ptr->PBV_Message_State     = PBV_MESSAGE_INIT;
    App_PBV_Demo_TX_Ptr->Length                = 64;

    App_PBV_Demo_RX_Ptr->PBV_Message_State     = PBV_MESSAGE_READY_TO_RECEIVE;
    App_PBV_Demo_RX_Ptr->Callback_Function     = &app_Develop_callback;

    App_PBV_Demo_ASCII_Ptr->PBV_Protcol_ID     = FIRMWARE_PROTOCOL_ID;
    App_PBV_Demo_ASCII_Ptr->PBV_Signal_Ascii   = PBV_ASCII_MODE;
    App_PBV_Demo_ASCII_Ptr->PBV_Message_State  = PBV_MESSAGE_INIT;
    App_PBV_Demo_ASCII_Ptr->Length             = 64;

    app_PBV_Init(App_PBV_Demo_TX_Ptr, App_PBV_Demo_ASCII_Ptr, App_PBV_Demo_RX_Ptr);
}


/***********************************************************************************
 * @ingroup app_pbv_demo_public_function
 * @fn     app_PBV_Demo_Task_10ms
 * @param  void
 * @return nothing
 * @brief this task checks periodically at 10 ms if any message has been received, and 
 * builds frame and transmits data
 * @details 
 *         this task is added to the main tasks file. this can be called at higher 
 * frequencies. but the user must be vary of the hardware capabilities. 
 **********************************************************************************/
void app_PBV_Demo_Task_10ms(void)
{
    // Reading received message
    if (App_PBV_Demo_RX_Ptr->PBV_Message_State == PBV_MESSAGE_RECEIVED)
    {        
        app_Read_Received_From_PBV(App_PBV_Demo_RX_Ptr);
        App_PBV_Demo_RX_Ptr->Callback_Function(App_PBV_Demo_RX_Ptr->Length, App_PBV_Demo_RX_Ptr->Data_Buffer);
        //App_PBV_Demo_RX_Ptr->PBV_Message_State = PBV_MESSAGE_READY_TO_RECEIVE;
        // data exchange
        App_PBV_Demo_TX_Ptr->Data_Buffer = App_PBV_Demo_RX_Ptr->Data_Buffer;
        // msg read. Read another
        app_Receive_From_PBV(App_PBV_Demo_RX_Ptr); 
    } 
    ///< 500ms sending 
    if (++counter > 2)
    {
        app_Generate_data();
        app_Send_To_PBV(App_PBV_Demo_TX_Ptr);
        counter = 0;
    }
}
/***********************************************************************************
 * @ingroup app_pbv_demo_public_function
 * @fn     app_PBV_Demo_Task_1s
 * @param  void
 * @return nothing
 * @brief this task periodically at 1s tranmsmits a sample log message
 * @details 
 *         this task is added to the main tasks file. this is a sample function,
 * logging from other files can be done by
 * 1. get the app_pbv_demo_ascii_ptr address
 * 2. append data to the buffer (ideally 64 bytes, or padded with spaces, else new line characters 
 *      might show undesirable visual effects)
 * 3. optionally reinit to new id.
 * 4. call app_Send_To_PBV.
 **********************************************************************************/
void app_PBV_Demo_Task_1s(void)
{
    if (App_PBV_Demo_ASCII_Ptr->PBV_Protcol_ID == FIRMWARE_PROTOCOL_ID)
    {
        App_PBV_Demo_ASCII_Ptr->Data_Buffer = "Firmware Version 1.0.0.0.......................................!";
        app_Send_To_PBV(App_PBV_Demo_ASCII_Ptr);
        App_PBV_Demo_ASCII_Ptr->PBV_Protcol_ID = PBV_SYSTEM_TO_GUI_ASCII_ID;
        flag = 1;
        return;
    }
    if (App_PBV_Demo_ASCII_Ptr->PBV_Protcol_ID == PBV_SYSTEM_TO_GUI_ASCII_ID)
    {
        if (flag) app_PBV_Re_Init(App_PBV_Demo_ASCII_Ptr);     ///< reinit to new id
        flag = 0; 
    }
    App_PBV_Demo_ASCII_Ptr->Data_Buffer = "Log Message From Protocol ID 0x206.............................\r";
    app_Send_To_PBV(App_PBV_Demo_ASCII_Ptr);
}

/***********************************************************************************
 * @ingroup app_pbv_demo_private_function
 * @fn      app_Generate_data
 * @param   void
 * @return  nothing
 * @brief   this generates a frame for transmission
 **********************************************************************************/
void app_Generate_data(void)
{
    buffer_sixteen_bit[0] = adc_val_pt->pwm_dc_val;
    buffer_sixteen_bit[1] = adc_val_pt->TP5;
    buffer_sixteen_bit[2] = adc_val_pt->TP12; 
    buffer_sixteen_bit[3] = adc_val_pt->TP13;
    buffer_sixteen_bit[4] = adc_val_pt->TP14;
    buffer_sixteen_bit[5] = app_Concatenate_Bank2();

    PBV_Change_from_Sixteen_to_Eight(buffer_sixteen_bit, buffer_eight_bit, 6);
    App_PBV_Demo_TX_Ptr->Data_Buffer = buffer_eight_bit;
}
/***********************************************************************************
 * @ingroup app_pbv_demo_private_function
 * @fn      app_Develop_callback
 * @param   void
 * @return  nothing
 * @brief   this is a simplified sample callback. this checks for the first bytes to switch 
 *  between different actions.
 **********************************************************************************/
void app_Develop_callback(uint16_t length, uint8_t * data)
{
    PBV_Change_from_Eight_to_Sixteen(data, buffer_eight_bit_rx, length);
    uint16_t switchcase = buffer_eight_bit_rx[0];
    switch (switchcase) {
        case 0x0000:
            if (buffer_eight_bit_rx[1] == 1)    
                Dev_LED_On(LED_BOARD_RED);
            if (buffer_eight_bit_rx[1] == 0)
                Dev_LED_Off(LED_BOARD_RED);
            break;
        case 0x0001:
            if (buffer_eight_bit_rx[1] == 1)
                Dev_LED_On(LED_BOARD_GREEN);
            if (buffer_eight_bit_rx[1] == 0)
                Dev_LED_Off(LED_BOARD_GREEN);
            break;
        case 0x0002:
            if (buffer_eight_bit_rx[1] == 1)
            {
                Dev_LED_On(LED_BOARD_GREEN);
                Dev_LED_On(LED_BOARD_RED);
                Dev_LED_On(LED_PIM_RED);
            }
            if (buffer_eight_bit_rx[1] == 0)
            {
                Dev_LED_Off(LED_BOARD_GREEN);
                Dev_LED_Off(LED_BOARD_RED);
                Dev_LED_Off(LED_PIM_RED);
            }
            break;
        case 0xFF00:
            switch(buffer_eight_bit_rx[1])
            {
                case 1:
                {
                    Dev_LED_Blink_Slow(LED_BOARD_GREEN);
                    Dev_LED_Blink_Slow(LED_BOARD_RED);
                    Dev_LED_Blink_Slow(LED_PIM_RED);
                    break;
                }
                case 2:
                {
                    Dev_LED_Blink(LED_BOARD_GREEN);
                    Dev_LED_Blink(LED_BOARD_RED);
                    Dev_LED_Blink(LED_PIM_RED);
                    break;
                }       
                case 3:
                {
                    Dev_LED_Blink_Fast(LED_BOARD_GREEN);
                    Dev_LED_Blink_Fast(LED_BOARD_RED);
                    Dev_LED_Blink_Fast(LED_PIM_RED);
                    break;
                } 
            }
            break;
        case 0xFFFF:
            slider_value = buffer_eight_bit_rx[1];
            break;
        default:
            break; 
    }
}

/***********************************************************************************
 * @ingroup app_pbv_demo_private_function
 * @fn      app_Concatenate_Bank1
 * @param   void
 * @return  uint16_t
 * @brief   this gets the current values of all the available digital IOs 
 *          on the digital power plug in module as they are mapped on to 
 *          digital power development board.
 **********************************************************************************/
uint16_t app_Concatenate_Bank1(void){
    return 0;
    }

/***********************************************************************************
 * @ingroup app_pbv_demo_private_function
 * @fn      app_Concatenate_Bank2
 * @param   void
 * @return  uint16_t
 * @brief   this gets the current values of all the available digital IOs 
 *          on the digital power plug in module as they are mapped on to 
 *          digital power development board.
 **********************************************************************************/
uint16_t app_Concatenate_Bank2(void) {
    return (
            ((LED_RED_GetValue() << 2) & 0x0004 )|
            ((LED_GREEN_GetValue() << 1) & 0x0002 ) |
            ((LED_DP_PIM_GetValue() << 0) & 0x0001 )
            );
    }

/*******************************************************************************
 * end of file
 *******************************************************************************/
/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC24 / dsPIC33 / PIC32MM MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - pic24-dspic-pic32mm : 1.55
        Device            :  PIC24FJ1024GB610
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.34
        MPLAB             :  MPLAB X v4.15
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buttons.h"
#include "lcd.h"
#include "leds.h"
//#include "PmodGPS.h"
#include "debugMessages.h"
#include "mcc_generated_files/uart3.h"
#include "mcc_generated_files/mcc.h"

uint8_t counter = 0;
//GPS gps = new gps();

/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    LCD_Initialize();
    
    LCD_PutString("Welcome... Rick", 15);
    LED_Enable(LED_D4);
    LED_Enable(LED_D5);
    LED_On(LED_D5);
    uint8_t line[] = "Text to send";
    uint8_t hxLine[10] = {0x01, 0x02, 0x03, 0x04, 0x05};
    uint8_t var = 22;
    
//    printf("Send this via Uart3 \n\r");
    
    uint8_t writeBuffer[35] = "1234567890ABCDEFGHIJKLMNOP\n\r" ;
    unsigned int numBytes = 0;
    int  writebufferLen = strlen((char *)writeBuffer);
//    UART3_Initialize();
//    while(numBytes < writebufferLen)
//    {    
//        int bytesToWrite = UART3_is_tx_ready();
//        numBytes += UART3_WriteBuffer ( writeBuffer+numBytes, bytesToWrite)  ;
//
//    }
        
    while (1)
    {
        if(LED_Get(LED_D5))
        {
            counter++;
//            numBytes = 0;
//            while(numBytes < writebufferLen)
//            {    
//                int bytesToWrite = UART3_is_tx_ready();
//                numBytes += UART3_WriteBuffer ( writeBuffer+numBytes, bytesToWrite)  ;
//
//            }
//            sendText(hxLine, HEX, 5);
            if(counter > 100)
            {
//                sendText(line, 1, 0);
                printf("This is the text to send\n\r");
                printf("Var = %d\n\r", var);
                
                counter = 0;
            }
//            sendText("\n\r", TEXT, 0);
            
        }
        // Add your application code
        
    }

    return -1;
}
/**
 End of File
*/
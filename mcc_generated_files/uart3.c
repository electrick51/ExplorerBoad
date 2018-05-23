/**
  UART3 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    uart3.c

  @Summary
    This is the generated driver implementation file for the UART3 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides implementations for driver APIs for UART3.
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

/**
  Section: Included Files
*/
#include "uart3.h"

/**
  Section: UART3 APIs
*/

void UART3_Initialize(void)
{
/**    
     Set the UART3 module to the options selected in the user interface.
     Make sure to set LAT bit corresponding to TxPin as high before UART initialization
*/
    // STSEL 1; IREN disabled; PDSEL 8N; UARTEN enabled; RTSMD disabled; USIDL disabled; WAKE disabled; ABAUD disabled; LPBACK disabled; BRGH enabled; URXINV disabled; UEN TX_RX; 
    U3MODE = (0x8008 & ~(1<<15));  // disabling UARTEN bit   
    // UTXISEL0 TX_ONE_CHAR; UTXINV disabled; URXEN disabled; OERR NO_ERROR_cleared; URXISEL RX_ONE_CHAR; UTXBRK COMPLETED; UTXEN disabled; ADDEN disabled; 
    U3STA = 0x0000;
    // BaudRate = 57600; Frequency = 4000000 Hz; U3BRG 16; 
    U3BRG = 0x0010;
    // ADMADDR 0; ADMMASK 0; 
    U3ADMD = 0x0000;
    
    U3MODEbits.UARTEN = 1;  // enabling UARTEN bit
    U3STAbits.UTXEN = 1; 
   
}


uint8_t UART3_Read(void)
{
    while(!(U3STAbits.URXDA == 1))
    {
        
    }

    if ((U3STAbits.OERR == 1))
    {
        U3STAbits.OERR = 0;
    }

    

    return U3RXREG;
}

void UART3_Write(uint8_t txData)
{
    while(U3STAbits.UTXBF == 1)
    {
        
    }

    U3TXREG = txData;    // Write the data byte to the USART.
}

UART3_STATUS UART3_StatusGet (void)
{
    return U3STA;
}

int __attribute__((__section__(".libc.write"))) write(int handle, void *buffer, unsigned int len) {
    int i;
    while(U3STAbits.TRMT == 0);  
    for (i = len; i; --i)
    {
        while(U3STAbits.TRMT == 0);
        U3TXREG = *(char*)buffer++;        
    }
    return(len);
}

/**
  End of File
*/

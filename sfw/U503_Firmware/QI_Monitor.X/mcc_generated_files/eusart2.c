/**
  EUSART2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    eusart2.c

  @Summary
    This is the generated driver implementation file for the EUSART2 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for EUSART2.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F27K40
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/
#include "eusart2.h"
#include "../error_handling.h"

/**
  Section: Macro Declarations
*/

#define EUSART2_TX_BUFFER_SIZE 1024
#define EUSART2_RX_BUFFER_SIZE 64

/**
  Section: Global Variables
*/
volatile uint16_t eusart2TxHead = 0;
volatile uint16_t eusart2TxTail = 0;
volatile uint8_t eusart2TxBuffer[EUSART2_TX_BUFFER_SIZE];
volatile uint16_t eusart2TxBufferRemaining;

volatile uint8_t eusart2RxHead = 0;
volatile uint8_t eusart2RxTail = 0;
volatile uint8_t eusart2RxBuffer[EUSART2_RX_BUFFER_SIZE];
volatile uint8_t eusart2RxCount;

volatile bit eusart2RxStringReady = 0;


/**
  Section: EUSART2 APIs
*/
void EUSART2_Initialize(void)
{
    // disable interrupts before changing states
    PIE3bits.RC2IE = 0;
    EUSART2_SetRxInterruptHandler(EUSART2_Receive_ISR);
    PIE3bits.TX2IE = 0;
    EUSART2_SetTxInterruptHandler(EUSART2_Transmit_ISR);
    // Set the EUSART2 module to the options selected in the user interface.

    // ABDOVF no_overflow; SCKP Non-Inverted; BRG16 16bit_generator; WUE disabled; ABDEN disabled; 
    BAUD2CON = 0x08;

    // SPEN enabled; RX9 8-bit; CREN enabled; ADDEN disabled; SREN disabled; 
    RC2STA = 0x90;

    // TX9 8-bit; TX9D 0; SENDB sync_break_complete; TXEN enabled; SYNC asynchronous; BRGH hi_speed; CSRC slave; 
    TX2STA = 0x24;

    // SP2BRGL 138; 
    SP2BRGL = 0x8A;

    // SP2BRGH 0; 
    SP2BRGH = 0x00;


    // initializing the driver state
    eusart2TxHead = 0;
    eusart2TxTail = 0;
    eusart2TxBufferRemaining = sizeof(eusart2TxBuffer);

    eusart2RxHead = 0;
    eusart2RxTail = 0;
    eusart2RxCount = 0;

    // enable receive interrupt
    PIE3bits.RC2IE = 1;
}

uint8_t EUSART2_is_tx_ready(void)
{
    return eusart2TxBufferRemaining;
}

uint8_t EUSART2_is_rx_ready(void)
{
    return eusart2RxCount;
}

bool EUSART2_is_tx_done(void)
{
    return TX2STAbits.TRMT;
}

uint8_t EUSART2_Read(void)
{
    uint8_t readValue  = 0;
    
    while(0 == eusart2RxCount)
    {
        CLRWDT();
    }

    readValue = eusart2RxBuffer[eusart2RxTail++];
    if(sizeof(eusart2RxBuffer) <= eusart2RxTail)
    {
        eusart2RxTail = 0;
    }
    PIE3bits.RC2IE = 0;
    eusart2RxCount--;
    PIE3bits.RC2IE = 1;

    return readValue;
}

void EUSART2_Write(uint8_t txData)
{
    while(0 == eusart2TxBufferRemaining)
    {
        CLRWDT();
    }

    if(0 == PIE3bits.TX2IE)
    {
        TX2REG = txData;
    }
    else
    {
        PIE3bits.TX2IE = 0;
        eusart2TxBuffer[eusart2TxHead++] = txData;
        if(sizeof(eusart2TxBuffer) <= eusart2TxHead)
        {
            eusart2TxHead = 0;
        }
        eusart2TxBufferRemaining--;
    }
    PIE3bits.TX2IE = 1;
}

char getch(void)
{
    return EUSART2_Read();
}

void putch(char txData)
{
    EUSART2_Write(txData);
}

void EUSART2_Transmit_ISR(void)
{

    // add your EUSART2 interrupt custom code
    if(sizeof(eusart2TxBuffer) > eusart2TxBufferRemaining)
    {
        TX2REG = eusart2TxBuffer[eusart2TxTail++];
        if(sizeof(eusart2TxBuffer) <= eusart2TxTail)
        {
            eusart2TxTail = 0;
        }
        eusart2TxBufferRemaining++;
    }
    else
    {
        PIE3bits.TX2IE = 0;
    }
}

void EUSART2_Receive_ISR(void)
{
    
    if(1 == RC2STAbits.OERR)
    {
        // EUSART2 error - restart

        RC2STAbits.CREN = 0;
        RC2STAbits.CREN = 1;
        error_handler.USB_UART_COMM_error_flag = true;
    }

    // buffer overruns are ignored
    eusart2RxBuffer[eusart2RxHead++] = RC2REG;
    if(sizeof(eusart2RxBuffer) <= eusart2RxHead)
    {
        eusart2RxHead = 0;
    }
    eusart2RxCount++;
    
        if((RC2REG == (int) '\n') || (RC2REG == (int) '\r')) {
        
        eusart2RxStringReady = 1;
        
        // Clear the stuff leftover in receive register, probably not needed
        RC2REG = 0;
        
    }
    
    else {
        
        eusart2RxStringReady = 0;
        
    }
   
    // If we've received a backspace
    if((RC2REG == (int) '\b')) {
     
        eusart2RxBuffer[eusart2RxHead] = '\0';
        eusart2RxHead--;
 
        // Erase the "backspaced" character
        printf("\033[K");
        
        if(eusart2RxHead != eusart2RxTail) {
        
            eusart2RxBuffer[eusart2RxHead] = '\0';
            eusart2RxHead--;

        }
        
        RC2REG = 0;
        
    }

    
}

void EUSART2_SetTxInterruptHandler(void (* interruptHandler)(void)){
    EUSART2_TxDefaultInterruptHandler = interruptHandler;
}

void EUSART2_SetRxInterruptHandler(void (* interruptHandler)(void)){
    EUSART2_RxDefaultInterruptHandler = interruptHandler;
}
/**
  End of File
*/

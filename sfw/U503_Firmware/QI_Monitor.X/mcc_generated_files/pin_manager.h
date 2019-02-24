/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F27K40
        Driver Version    :  2.11
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set POS12_ADC aliases
#define POS12_ADC_TRIS                 TRISAbits.TRISA0
#define POS12_ADC_LAT                  LATAbits.LATA0
#define POS12_ADC_PORT                 PORTAbits.RA0
#define POS12_ADC_WPU                  WPUAbits.WPUA0
#define POS12_ADC_OD                   ODCONAbits.ODCA0
#define POS12_ADC_ANS                  ANSELAbits.ANSELA0
#define POS12_ADC_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define POS12_ADC_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define POS12_ADC_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define POS12_ADC_GetValue()           PORTAbits.RA0
#define POS12_ADC_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define POS12_ADC_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define POS12_ADC_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define POS12_ADC_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define POS12_ADC_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define POS12_ADC_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define POS12_ADC_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define POS12_ADC_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set POS12_ISNS_ADC aliases
#define POS12_ISNS_ADC_TRIS                 TRISAbits.TRISA1
#define POS12_ISNS_ADC_LAT                  LATAbits.LATA1
#define POS12_ISNS_ADC_PORT                 PORTAbits.RA1
#define POS12_ISNS_ADC_WPU                  WPUAbits.WPUA1
#define POS12_ISNS_ADC_OD                   ODCONAbits.ODCA1
#define POS12_ISNS_ADC_ANS                  ANSELAbits.ANSELA1
#define POS12_ISNS_ADC_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define POS12_ISNS_ADC_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define POS12_ISNS_ADC_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define POS12_ISNS_ADC_GetValue()           PORTAbits.RA1
#define POS12_ISNS_ADC_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define POS12_ISNS_ADC_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define POS12_ISNS_ADC_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define POS12_ISNS_ADC_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define POS12_ISNS_ADC_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define POS12_ISNS_ADC_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define POS12_ISNS_ADC_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define POS12_ISNS_ADC_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSELA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA3 procedures
#define RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RA3_GetValue()              PORTAbits.RA3
#define RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define RA3_SetPullup()             do { WPUAbits.WPUA3 = 1; } while(0)
#define RA3_ResetPullup()           do { WPUAbits.WPUA3 = 0; } while(0)
#define RA3_SetAnalogMode()         do { ANSELAbits.ANSELA3 = 1; } while(0)
#define RA3_SetDigitalMode()        do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set POS5_ADC aliases
#define POS5_ADC_TRIS                 TRISAbits.TRISA4
#define POS5_ADC_LAT                  LATAbits.LATA4
#define POS5_ADC_PORT                 PORTAbits.RA4
#define POS5_ADC_WPU                  WPUAbits.WPUA4
#define POS5_ADC_OD                   ODCONAbits.ODCA4
#define POS5_ADC_ANS                  ANSELAbits.ANSELA4
#define POS5_ADC_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define POS5_ADC_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define POS5_ADC_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define POS5_ADC_GetValue()           PORTAbits.RA4
#define POS5_ADC_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define POS5_ADC_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define POS5_ADC_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define POS5_ADC_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define POS5_ADC_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define POS5_ADC_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define POS5_ADC_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define POS5_ADC_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set QI_ISNS_ADC aliases
#define QI_ISNS_ADC_TRIS                 TRISAbits.TRISA5
#define QI_ISNS_ADC_LAT                  LATAbits.LATA5
#define QI_ISNS_ADC_PORT                 PORTAbits.RA5
#define QI_ISNS_ADC_WPU                  WPUAbits.WPUA5
#define QI_ISNS_ADC_OD                   ODCONAbits.ODCA5
#define QI_ISNS_ADC_ANS                  ANSELAbits.ANSELA5
#define QI_ISNS_ADC_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define QI_ISNS_ADC_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define QI_ISNS_ADC_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define QI_ISNS_ADC_GetValue()           PORTAbits.RA5
#define QI_ISNS_ADC_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define QI_ISNS_ADC_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define QI_ISNS_ADC_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define QI_ISNS_ADC_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define QI_ISNS_ADC_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define QI_ISNS_ADC_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define QI_ISNS_ADC_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define QI_ISNS_ADC_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RA6 procedures
#define RA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define RA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define RA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define RA6_GetValue()              PORTAbits.RA6
#define RA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define RA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define RA6_SetPullup()             do { WPUAbits.WPUA6 = 1; } while(0)
#define RA6_ResetPullup()           do { WPUAbits.WPUA6 = 0; } while(0)
#define RA6_SetAnalogMode()         do { ANSELAbits.ANSELA6 = 1; } while(0)
#define RA6_SetDigitalMode()        do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set RA7 procedures
#define RA7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define RA7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define RA7_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define RA7_GetValue()              PORTAbits.RA7
#define RA7_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define RA7_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define RA7_SetPullup()             do { WPUAbits.WPUA7 = 1; } while(0)
#define RA7_ResetPullup()           do { WPUAbits.WPUA7 = 0; } while(0)
#define RA7_SetAnalogMode()         do { ANSELAbits.ANSELA7 = 1; } while(0)
#define RA7_SetDigitalMode()        do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set SDA2 aliases
#define SDA2_TRIS                 TRISBbits.TRISB4
#define SDA2_LAT                  LATBbits.LATB4
#define SDA2_PORT                 PORTBbits.RB4
#define SDA2_WPU                  WPUBbits.WPUB4
#define SDA2_OD                   ODCONBbits.ODCB4
#define SDA2_ANS                  ANSELBbits.ANSELB4
#define SDA2_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SDA2_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SDA2_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SDA2_GetValue()           PORTBbits.RB4
#define SDA2_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SDA2_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SDA2_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SDA2_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SDA2_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SDA2_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SDA2_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define SDA2_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set SCL2 aliases
#define SCL2_TRIS                 TRISBbits.TRISB5
#define SCL2_LAT                  LATBbits.LATB5
#define SCL2_PORT                 PORTBbits.RB5
#define SCL2_WPU                  WPUBbits.WPUB5
#define SCL2_OD                   ODCONBbits.ODCB5
#define SCL2_ANS                  ANSELBbits.ANSELB5
#define SCL2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define SCL2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define SCL2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define SCL2_GetValue()           PORTBbits.RB5
#define SCL2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define SCL2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define SCL2_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define SCL2_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define SCL2_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define SCL2_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define SCL2_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define SCL2_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set IO_RB6 aliases
#define IO_RB6_TRIS                 TRISBbits.TRISB6
#define IO_RB6_LAT                  LATBbits.LATB6
#define IO_RB6_PORT                 PORTBbits.RB6
#define IO_RB6_WPU                  WPUBbits.WPUB6
#define IO_RB6_OD                   ODCONBbits.ODCB6
#define IO_RB6_ANS                  ANSELBbits.ANSELB6
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define IO_RB6_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define IO_RB6_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define IO_RB6_SetAnalogMode()      do { ANSELBbits.ANSELB6 = 1; } while(0)
#define IO_RB6_SetDigitalMode()     do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set IO_RB7 aliases
#define IO_RB7_TRIS                 TRISBbits.TRISB7
#define IO_RB7_LAT                  LATBbits.LATB7
#define IO_RB7_PORT                 PORTBbits.RB7
#define IO_RB7_WPU                  WPUBbits.WPUB7
#define IO_RB7_OD                   ODCONBbits.ODCB7
#define IO_RB7_ANS                  ANSELBbits.ANSELB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define IO_RB7_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define IO_RB7_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define IO_RB7_SetAnalogMode()      do { ANSELBbits.ANSELB7 = 1; } while(0)
#define IO_RB7_SetDigitalMode()     do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set IO_RC0 aliases
#define IO_RC0_TRIS                 TRISCbits.TRISC0
#define IO_RC0_LAT                  LATCbits.LATC0
#define IO_RC0_PORT                 PORTCbits.RC0
#define IO_RC0_WPU                  WPUCbits.WPUC0
#define IO_RC0_OD                   ODCONCbits.ODCC0
#define IO_RC0_ANS                  ANSELCbits.ANSELC0
#define IO_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_RC0_GetValue()           PORTCbits.RC0
#define IO_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define IO_RC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define IO_RC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define IO_RC0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define IO_RC0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define IO_RC0_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define IO_RC0_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set IO_RC1 aliases
#define IO_RC1_TRIS                 TRISCbits.TRISC1
#define IO_RC1_LAT                  LATCbits.LATC1
#define IO_RC1_PORT                 PORTCbits.RC1
#define IO_RC1_WPU                  WPUCbits.WPUC1
#define IO_RC1_OD                   ODCONCbits.ODCC1
#define IO_RC1_ANS                  ANSELCbits.ANSELC1
#define IO_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_RC1_GetValue()           PORTCbits.RC1
#define IO_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define IO_RC1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define IO_RC1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define IO_RC1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define IO_RC1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define IO_RC1_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define IO_RC1_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set IO_RC2 aliases
#define IO_RC2_TRIS                 TRISCbits.TRISC2
#define IO_RC2_LAT                  LATCbits.LATC2
#define IO_RC2_PORT                 PORTCbits.RC2
#define IO_RC2_WPU                  WPUCbits.WPUC2
#define IO_RC2_OD                   ODCONCbits.ODCC2
#define IO_RC2_ANS                  ANSELCbits.ANSELC2
#define IO_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_GetValue()           PORTCbits.RC2
#define IO_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_RC2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define IO_RC2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define IO_RC2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define IO_RC2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define IO_RC2_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define IO_RC2_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set IO_RC5 aliases
#define IO_RC5_TRIS                 TRISCbits.TRISC5
#define IO_RC5_LAT                  LATCbits.LATC5
#define IO_RC5_PORT                 PORTCbits.RC5
#define IO_RC5_WPU                  WPUCbits.WPUC5
#define IO_RC5_OD                   ODCONCbits.ODCC5
#define IO_RC5_ANS                  ANSELCbits.ANSELC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_RC5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define IO_RC5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set IO_RC6 aliases
#define IO_RC6_TRIS                 TRISCbits.TRISC6
#define IO_RC6_LAT                  LATCbits.LATC6
#define IO_RC6_PORT                 PORTCbits.RC6
#define IO_RC6_WPU                  WPUCbits.WPUC6
#define IO_RC6_OD                   ODCONCbits.ODCC6
#define IO_RC6_ANS                  ANSELCbits.ANSELC6
#define IO_RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IO_RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IO_RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IO_RC6_GetValue()           PORTCbits.RC6
#define IO_RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IO_RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define IO_RC6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define IO_RC6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define IO_RC6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define IO_RC6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define IO_RC6_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define IO_RC6_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set IO_RC7 aliases
#define IO_RC7_TRIS                 TRISCbits.TRISC7
#define IO_RC7_LAT                  LATCbits.LATC7
#define IO_RC7_PORT                 PORTCbits.RC7
#define IO_RC7_WPU                  WPUCbits.WPUC7
#define IO_RC7_OD                   ODCONCbits.ODCC7
#define IO_RC7_ANS                  ANSELCbits.ANSELC7
#define IO_RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define IO_RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define IO_RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define IO_RC7_GetValue()           PORTCbits.RC7
#define IO_RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define IO_RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define IO_RC7_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define IO_RC7_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define IO_RC7_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define IO_RC7_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define IO_RC7_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define IO_RC7_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/
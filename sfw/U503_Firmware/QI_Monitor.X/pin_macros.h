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

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _PIN_MACROS_H
#define	_PIN_MACROS_H

#include <xc.h> // include processor files - each processor file is guarded.  

// These are pin macro definitions so that microcontroller I/O can be easily
// accessed instead of reading from/writing to bitfields in registers

// Port A
#define POS12_ADC_PIN           PORTAbits.RA0
#define POS12_ISNS_ADC_PIN      PORTAbits.RA1
#define POS5_ADC_PIN            PORTAbits.RA4
#define QI_ISNS_ADC_PIN         PORTAbits.RA5
#define CAP_TOUCH_RIGHT_PIN     PORTAbits.RA6
#define CAP_TOUCH_LECT_PIN      PORTAbits.RA7

// Port B
#define POS5_SW_SNS_PIN         PORTBbits.RB0
#define QI_SW_SNS_PIN           PORTBbits.RB1
#define QI_IDLE_PIN             PORTBbits.RB2
#define QI_IDLE_PIN_RISE        IOCBPbits.IOCBP2
#define QI_IDLE_PIN_FALL        IOCBNbits.IOCBN2
#define QI_CHARGE_PIN           PORTBbits.RB3
#define QI_CHARGE_PIN_RISE      IOCBPbits.IOCBP3
#define QI_CHARGE_PIN_FALL      IOCBNbits.IOCBN3
#define HEARTBEAT_LED_PIN       LATBbits.LATB6
#define OTHER_ERROR_LED_PIN     LATBbits.LATB7

// Port C
#define QI_STANDBY_PIN          LATCbits.LATC2
#define I2C_ERROR_LED_PIN       LATCbits.LATC5
#define USB_ERROR_LED_PIN       LATCbits.LATC6
#define nACTIVE_LED_PIN         LATCbits.LATC7


#endif	/* _PIN_MACROS_H */


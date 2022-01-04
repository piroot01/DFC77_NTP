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
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

typedef enum {
    APP_LED_POWER_STATUS_STATE_INIT = 0,
            APP_LED_POWER_STATUS_STATE_ON = 1
} APP_LED_POWER_STATUS_STATES;

typedef struct {
    APP_LED_POWER_STATUS_STATES state;   
} AppLEDPowerStatusVar;

AppLEDPowerStatusVar appledpowerstatusData;

typedef enum {
    APP_LED_SIGNAL_STATUS_INIT = 0,
            APP_LED_SIGNAL_STATUS_WAIT = 1,
            APP_LED_SIGNAL_STATUS_OFF = 2,
            APP_LED_SIGNAL_STATUS_ON = 3,
            APP_LED_SIGNAL_STATUS_BLINK = 4,
} APP_LED_SIGNAL_STATUS_STATES;

typedef struct {
    APP_LED_SIGNAL_STATUS_STATES state;
    
    int led_toggle_period;
    
    int shortest_interval;
} AppLEDSignalStatusVar;

AppLEDSignalStatusVar appledsignalstatusData;

int interval = 1600;

typedef enum {
    APP_LED_SIGNAL_STATUS_BLINK_INIT = 0,
            APP_LED_SIGNAL_STATUS_BLINK_WAIT = 1,
            APP_LED_SIGNAL_STATUS_BLINK_TOGGLE = 2
} APP_LED_SIGNAL_STATUS_BLINK_STATES;

typedef struct {
    APP_LED_SIGNAL_STATUS_BLINK_STATES state;
    
    int TimerCount;
} AppLEDSignalStatusBlinkVar;

AppLEDSignalStatusBlinkVar appledsignalstatusblinkData;

typedef struct {
    volatile unsigned int signal_state;
    unsigned int signal_prev_state;
    
    int PulseTimerCount;
    int PeriodTimerCount;
    
    int error_count;
    int result;
    
    int status_list[20];
    
    int status_list_sum;
} AppSignalStatusVar;

AppSignalStatusVar appsignalstatusData;

int statusListLen = 20;

void APP_LED_POWER_STATUS_Initialize(void);
void APP_LED_POWER_STATUS_Tasks(void);

void APP_SIGNAL_STATUS_Tasks(void);
void signalEvaluate(void);
void statusListWrite(void);
int statusListSum();

void APP_LED_SIGNAL_STATUS_Initialize(void);
void APP_LED_SIGNAL_STATUS_Tasks(void);
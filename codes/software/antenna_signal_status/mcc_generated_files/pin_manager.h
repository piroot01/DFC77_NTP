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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC12F1572
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SIGNAL aliases
#define SIGNAL_TRIS                 TRISAbits.TRISA0
#define SIGNAL_LAT                  LATAbits.LATA0
#define SIGNAL_PORT                 PORTAbits.RA0
#define SIGNAL_WPU                  WPUAbits.WPUA0
#define SIGNAL_OD                   ODCONAbits.ODA0
#define SIGNAL_ANS                  ANSELAbits.ANSA0
#define SIGNAL_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SIGNAL_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SIGNAL_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SIGNAL_GetValue()           PORTAbits.RA0
#define SIGNAL_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SIGNAL_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SIGNAL_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define SIGNAL_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define SIGNAL_SetPushPull()        do { ODCONAbits.ODA0 = 0; } while(0)
#define SIGNAL_SetOpenDrain()       do { ODCONAbits.ODA0 = 1; } while(0)
#define SIGNAL_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define SIGNAL_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set POWER_STATUS aliases
#define POWER_STATUS_TRIS                 TRISAbits.TRISA1
#define POWER_STATUS_LAT                  LATAbits.LATA1
#define POWER_STATUS_PORT                 PORTAbits.RA1
#define POWER_STATUS_WPU                  WPUAbits.WPUA1
#define POWER_STATUS_OD                   ODCONAbits.ODA1
#define POWER_STATUS_ANS                  ANSELAbits.ANSA1
#define POWER_STATUS_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define POWER_STATUS_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define POWER_STATUS_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define POWER_STATUS_GetValue()           PORTAbits.RA1
#define POWER_STATUS_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define POWER_STATUS_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define POWER_STATUS_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define POWER_STATUS_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define POWER_STATUS_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define POWER_STATUS_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define POWER_STATUS_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define POWER_STATUS_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set SIGNAL_STATUS aliases
#define SIGNAL_STATUS_TRIS                 TRISAbits.TRISA2
#define SIGNAL_STATUS_LAT                  LATAbits.LATA2
#define SIGNAL_STATUS_PORT                 PORTAbits.RA2
#define SIGNAL_STATUS_WPU                  WPUAbits.WPUA2
#define SIGNAL_STATUS_OD                   ODCONAbits.ODA2
#define SIGNAL_STATUS_ANS                  ANSELAbits.ANSA2
#define SIGNAL_STATUS_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define SIGNAL_STATUS_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define SIGNAL_STATUS_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define SIGNAL_STATUS_GetValue()           PORTAbits.RA2
#define SIGNAL_STATUS_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define SIGNAL_STATUS_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define SIGNAL_STATUS_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define SIGNAL_STATUS_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define SIGNAL_STATUS_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define SIGNAL_STATUS_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define SIGNAL_STATUS_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define SIGNAL_STATUS_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

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


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF0 pin functionality
 * @Example
    IOCAF0_ISR();
 */
void IOCAF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF0_SetInterruptHandler() method.
    This handler is called every time the IOCAF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF0_SetInterruptHandler(IOCAF0_InterruptHandler);

*/
extern void (*IOCAF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF0_SetInterruptHandler() method.
    This handler is called every time the IOCAF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF0_SetInterruptHandler(IOCAF0_DefaultInterruptHandler);

*/
void IOCAF0_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/
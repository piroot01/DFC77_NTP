/*
 * File:   app.c
 * Author: tomas
 *
 * Created on November 15, 2021, 11:37 AM
 */


#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "app.h"

void APP_LED_POWER_STATUS_Initialize()
{
    appledpowerstatusData.state = APP_LED_POWER_STATUS_STATE_INIT;
}

void APP_LED_POWER_STATUS_Tasks()
{
    switch (appledpowerstatusData.state)
    {
        case APP_LED_POWER_STATUS_STATE_INIT:
            appledpowerstatusData.state = APP_LED_POWER_STATUS_STATE_ON;
            
            break;
        case APP_LED_POWER_STATUS_STATE_ON:
            POWER_STATUS_SetHigh();
            
            break;
        default:
            
            break;
    } 
}

void APP_SIGNAL_STATUS_Tasks()
{
    signalEvaluate();
    
    if (appsignalstatusData.signal_state == 0)
    {
        statusListWrite();
    
        appsignalstatusData.status_list_sum = statusListSum(appsignalstatusData.status_list);
    }
}

void APP_LED_SIGNAL_STATUS_Initialize()
{
    appledsignalstatusData.state = APP_LED_SIGNAL_STATUS_INIT;
    appledsignalstatusblinkData.state = APP_LED_SIGNAL_STATUS_BLINK_INIT;
    
    appledsignalstatusblinkData.TimerCount = 0;
    
    appledsignalstatusData.shortest_interval = interval / statusListLen;
}

void APP_LED_SIGNAL_STATUS_Tasks()
{
    if (appsignalstatusData.status_list_sum == 0)
    {
        appledsignalstatusData.led_toggle_period = interval;
    }
    else
    {
        appledsignalstatusData.led_toggle_period = interval / appsignalstatusData.status_list_sum;
    }
    
    switch (appledsignalstatusData.state)
    {
        case APP_LED_SIGNAL_STATUS_INIT:
            appledsignalstatusData.state = APP_LED_SIGNAL_STATUS_WAIT;
            
            break;
        case APP_LED_SIGNAL_STATUS_WAIT:
            if (appledsignalstatusData.led_toggle_period == interval)
            {
                appledsignalstatusData.state = APP_LED_SIGNAL_STATUS_OFF;
            }
            else if (appledsignalstatusData.led_toggle_period == appledsignalstatusData.shortest_interval)
            {
                appledsignalstatusData.state = APP_LED_SIGNAL_STATUS_ON;
            }
            else
            {
                appledsignalstatusData.state = APP_LED_SIGNAL_STATUS_BLINK;
            }
            
            break;
        case APP_LED_SIGNAL_STATUS_OFF:
            appledsignalstatusData.state = APP_LED_SIGNAL_STATUS_WAIT;
            
             SIGNAL_STATUS_SetLow();
            
            break;
        case APP_LED_SIGNAL_STATUS_ON:
            appledsignalstatusData.state = APP_LED_SIGNAL_STATUS_WAIT;
            
            SIGNAL_STATUS_SetHigh();
            
            break;
        case APP_LED_SIGNAL_STATUS_BLINK:
            appledsignalstatusData.state = APP_LED_SIGNAL_STATUS_WAIT;
            
            switch (appledsignalstatusblinkData.state)
            {
                case APP_LED_SIGNAL_STATUS_BLINK_INIT:
                    appledsignalstatusblinkData.state = APP_LED_SIGNAL_STATUS_BLINK_WAIT;
                    
                    break;
                case APP_LED_SIGNAL_STATUS_BLINK_WAIT:
                    if (appledsignalstatusblinkData.TimerCount >= appledsignalstatusData.led_toggle_period)
                    {
                        appledsignalstatusblinkData.state = APP_LED_SIGNAL_STATUS_BLINK_TOGGLE;
                        
                        appledsignalstatusblinkData.TimerCount = 0;
                    }
                    
                    break;
                case APP_LED_SIGNAL_STATUS_BLINK_TOGGLE:
                    appledsignalstatusblinkData.state = APP_LED_SIGNAL_STATUS_BLINK_WAIT;
                    
                    SIGNAL_STATUS_Toggle();
                    
                    break;
                default:
                    
                    break;
            }
            
            break;
        default:
            
            break;
    }
    
    appledsignalstatusData.led_toggle_period = 0;
}

int statusListSum(int list[20])
{
    int sum = 0;
    
    for (int i = 0; i < statusListLen; i++)
    {
        sum += list[i];
    }
    
    return sum;
}

void statusListWrite()
{
    for (int i = 0; i < (statusListLen - 1); i++)
    {
        appsignalstatusData.status_list[i] = appsignalstatusData.status_list[i + 1];
    }
    
    appsignalstatusData.status_list[statusListLen - 1] = appsignalstatusData.result;
}

void signalEvaluate()
{
    if (appsignalstatusData.signal_state == 1)
    {
        appsignalstatusData.PulseTimerCount = 0;
        
        if (appsignalstatusData.PeriodTimerCount < 900)
        {
            appsignalstatusData.error_count++;
        }
        else if (appsignalstatusData.PeriodTimerCount > 1100 
              && appsignalstatusData.PeriodTimerCount < 1900)
        {
            appsignalstatusData.error_count++;
        }
        else if (appsignalstatusData.PeriodTimerCount > 2100)
        {
            appsignalstatusData.error_count++;
        }
        
        appsignalstatusData.PeriodTimerCount = 0;
        
        return;
    }
    
    if (appsignalstatusData.signal_state == 0)
    {
        if (appsignalstatusData.PulseTimerCount < 70)
        {
            appsignalstatusData.error_count++;
        }
        else if (appsignalstatusData.PulseTimerCount > 230)
        {
            appsignalstatusData.error_count++;  
        }
        
        if (appsignalstatusData.error_count == 0)
        {
        appsignalstatusData.result = 1;
        }
        else
        {
        appsignalstatusData.result = 0;
        }
    
        appsignalstatusData.error_count = 0;
        
        return;
    }
}
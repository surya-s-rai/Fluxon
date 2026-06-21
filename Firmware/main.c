#include <msp430.h>
#include "impact_detector.h"
#include "adc_monitor.h"
#include "logger.h"
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
    Impact_Init();
    ADC_Init();
    Flash_Init();
    _enable_interrupt();
    while(1){
        if(impactFlag){
            impactFlag=0;
            Logger_SaveEvent();
        }
        __bis_SR_register(LPM3_bits + GIE);
    }
}
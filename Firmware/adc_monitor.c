#include <msp430.h>
void ADC_Init(void){
    ADC12CTL0 &= ~ADC12ENC;
    ADC12CTL0=
      ADC12SHT0_2 |
      ADC12ON;
    ADC12CTL1=
      ADC12SHP;
    ADC12MCTL0=
      ADC12VRSEL_0 |
      ADC12INCH_5;
    ADC12CTL0 |= ADC12ENC;
}
unsigned int ADC_RadPeak(void){
    unsigned int peak= 0;
    unsigned int sample;
    int i;
    for(int i=0;i<32;i++){
        ADC12CTL0 |=ADC12SC;
        while(!(ADC12IFGR0 & BIT0));
        sample=DC12MEM0;
        if(sample >peak){
            peak=sample;
        }
        return peak; 
    }
}
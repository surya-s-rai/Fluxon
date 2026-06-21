#include <msp430.h>
volatile unsigned char impactFlag=0;
void Impact_Init(void){
    P1DIR &= ~BIT7;
    P1IER &= ~BIT7;
    P1IFG &= ~BIT7;
    P1IE |= BIT7;
}
#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISP(void){
    if(P1IFG & BIT7){
        impactFlag=1;
        P1IFG &= ~BIT7;
    }
}
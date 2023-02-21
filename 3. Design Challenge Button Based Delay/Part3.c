/*
 * Part3.c
 *
 *  Created on: Feb 12, 2023
 *      Author: Nik Dimitrovski
 *
 */
#include <msp430.h>

void main(){

    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    P1OUT &= ~BIT0;  //p1.0 red led
    P6OUT &= ~BIT6; //p6.6 greenled
    P1DIR |= BIT0;
    P6DIR |= BIT6;
    P4DIR &= ~BIT1;//clear P4.1(s1)
    P4REN |= BIT1;//Enable pull up/down resistor
    P4OUT |= BIT1;//Make resistor a pull up


    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode

    if((P4IN & BUTTON) == 0x00){
                count++;
                if(count == 4){
                P1OUT |= RED_LED;
                }

}






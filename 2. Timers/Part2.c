/*
 * Part2.c
 *
 *  Created on: Feb 11, 2023
 *      Author: Modified By Nik Dimitrovski
 *
 *      This code will need to change the speed of an LED between 3 different speeds by pressing a button.
 */

#include <msp430.h>

void gpioInit();
void timerInit();

void main(){

    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    gpioInit();
    timerInit();

    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;

    __bis_SR_register(LPM3_bits | GIE);

}


void gpioInit(){
    // Configure RED LED on P1.0 as Output
          P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
          P1DIR |= BIT0;                          // Set P1.0 to output direction

          // Configure Green LED on P6.6 as Output
          P6OUT &= ~BIT6;                         // Clear P6.6 output latch for a defined power-on state
          P6DIR |= BIT6;                          // Set P6.6 to output direction

    // @TODO Initialize Button 2.3
            P2OUT &= ~BIT3;
            P2OUT |= BIT3;                          // Configure P2.3 as pulled-up
            P2REN |= BIT3;                          // P2.3 pull-up register enable
            P2IES &= ~BIT3;                         // P2.3 Low --> High edge
            P2IE |= BIT3;                           // P2.3 interrupt enabled


}

void timerInit(){
    P1OUT=0X01;   //make bit0 HIGH
           for(i=0;i<20000;i++){   //    delay till you make LED HIGH
       }
           P1OUT=0X00;   //make bit0 LOW

           for(i=0;i<20000;i++){   // delay till you make LED LOW
                  }

}

// Port 2 interrupt service routine
#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void)
{
    P1DIR |= 0x41; // Set P1.0 and P1.6 to outputs

    P1REN = 0x08; // Turn on pull up resistor to push button

    P1OUT = 0x49;

}


// Timer B1 interrupt service routine
#pragma vector = TIMER1_B0_VECTOR
__interrupt void Timer1_B0_ISR(void)
{
    P1IE |= BUTTON; // P1.3 interrupt enabled

    P1IFG &= ~BUTTON;

}



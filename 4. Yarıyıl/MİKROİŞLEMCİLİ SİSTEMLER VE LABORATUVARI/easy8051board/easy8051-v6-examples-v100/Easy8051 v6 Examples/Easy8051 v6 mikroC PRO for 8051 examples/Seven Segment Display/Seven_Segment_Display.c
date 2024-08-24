/*
 * Project name:
     Seven_Segment_Display (Advanced 7 segment display example)
 * Copyright:
     (c) Mikroelektronika, 2009.
 * Revision History:
     20090601:
       - initial release;
 * Description:
     This program demonstrates  displaying number on four 7-segment display (common
     cathode) in multiplex mode. All 7-segment displays are connected to PORT0
     (P0.0..P0.7, segment A to P0.0, segment B to P0.1, etc) with refresh via pins
     P1.0..P1.3 on PORT1. Number is on for 1 second.
 * Test configuration:
     MCU:             AT89S8253
                      http://www.atmel.com/dyn/resources/prod_documents/doc3286.pdf
     Dev.Board:       Easy8051 v6
                      http://www.mikroe.com/en/tools/easy8051-v6/
     Oscillator:      External Clock 10.0000 MHz
     Ext. Modules:    -
     SW:              mikroC PRO for 8051
                      http://www.mikroe.com/en/compilers/mikroc/8051/
 * NOTES:
     - Turn on switches SW8.1, SW8.2, SW8.3, SW8.4 and SW10.
*/

#include "Display_utils.h"

const char TH1_INIT = 0xF0; // Initial/Reset value, controls Timer1 period
const char TL1_INIT = 0x00;

unsigned short shifter, digits_array_index;
unsigned int   digit, number;
unsigned short digits_array[4];

//-------------- Interrupt handler routine
void Timer1InterruptHandler() org IVT_ADDR_ET1 {

  EA_bit  = 0;                           // Clear global interrupt enable flag

  TR1_bit = 0;                           // Stop Timer1
  TH1 = TH1_INIT;                        // Reset Timer1 high byte
  TL1 = TL1_INIT;                        // Reset Timer1 low byte
  
  P1 = 0;                                // Turn off all 7seg displays
  P0 = digits_array[digits_array_index]; // bring appropriate value to PORT0
  P1 = shifter;                          // turn on appropriate 7seg. display

  // move shifter to next digit
  shifter <<= 1;
  if (shifter > 8u)
    shifter = 1;

  // increment digits_array_index
  digits_array_index++ ;
  if (digits_array_index > 3u)
    digits_array_index = 0;              // turn on 1st, turn off 2nd 7seg.
      
  EA_bit  = 1;                           // Set global interrupt enable flag
  TR1_bit = 1;                           // Run Timer1
}

void main() {
  digit              = 0;                // initialize variables
  digits_array_index = 0;
  shifter            = 1;

  P0  = 0;          // Initialize PORT0

  TF1_bit = 0;      // Ensure that Timer1 interrupt flag is cleared
  ET1_bit = 1;      // Enable Timer1 interrupt
  EA_bit  = 1;      // Set global interrupt enable

  GATE1_bit = 0;    // Clear this flag to enable Timer1 whenever TR1 bit is set.
  C_T1_bit  = 0;    // Set Timer operation: Timer1 counts the divided-down systam clock.
  M11_bit   = 0;    // M11_M01 = 01    =>   Mode 1(16-bit Timer/Counter)
  M01_bit   = 1;

  TR1_bit = 0;      // Turn off Timer1
  TH1 = TH1_INIT;   // Set Timer1 high byte
  TL1 = TL1_INIT;   // Set Timer1 low byte
  TR1_bit = 1;      // Run Timer1
  
  number = 6789;                    // some initial value
  do {
    digit = number / 1000u ;        // extract thousands digit
    digits_array[3] = mask(digit);  // and store it to digits array
    digit = (number / 100u) % 10u;  // extract hundreds digit
    digits_array[2] = mask(digit);  // and store it to digits array
    digit = (number / 10u) % 10u;   // extract tens digit
    digits_array[1] = mask(digit);  // and store it to digits array
    digit = number % 10u;           // extract ones digit
    digits_array[0] = mask(digit);  // and store it to digits array

    Delay_ms(100);                 // one second delay

    number++ ;                      // increment number
    if (number > 9999u)
      number = 0;

  } while(1);                       // endless loop
}

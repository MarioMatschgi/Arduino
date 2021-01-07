/*
 * Module for using the uC as a light controller
 * 
 * @author Mario Elsnig
 * @date LITEC 2020-11-10
 * @version 1.0
*/

#include <Arduino.h>

void setup()
{
  DDRA = 0x00;  // Port A input
  PORTA = 0x11; // Pullup resistors
  DDRB = 0xFF;  // Port B output
}

void loop()
{
  // Should work and be able to use other number of buttons
  PORTB = 0xff - PINA;

  // PROBLEM: Only one button at a time possible
  // if (PINA & 0x10)
  //   PORTB = 0x00;
  // else
  //   PORTB = 0x10;
  // if (PINA & 0x01)
  //   PORTB = 0x00;
  // else
  //   PORTB = 0x01;

  // PROBLEM: Complex and not future-proof
  // if (PINA & 0x10)
  // {
  //   if (PINA & 0x01)
  //     PORTB = 0x00;
  //   else
  //     PORTB = 0x01;
  // }
  // else
  // {
  //   if (PINA & 0x01)
  //     PORTB = 0x01;
  //   else
  //     PORTB = 0x11;
  // }
}
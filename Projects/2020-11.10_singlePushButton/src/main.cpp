/*
 * Module for using the uC as a traffic controlling device
 * 
 * @author Mario Elsnig
 * @date LITEC 2020-11-10
 * @version 1.0
*/

#include <Arduino.h>

uint8_t btn = 0;

void setup()
{
  DDRA = 0x00; // Port A input
  DDRB = 0xFF; // Port B output
}

void loop()
{
  btn = PINA; // Get Button value on port A

  if (btn & 0x01) // Check if Button pressed
    PORTB = 0x00;
  else
    PORTB = 0xff;
}
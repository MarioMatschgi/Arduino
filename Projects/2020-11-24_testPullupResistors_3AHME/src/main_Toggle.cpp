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

  DDRB |= (1 << PB3);
}

uint8_t pressed = 0;
uint8_t firstPressed;
uint8_t secondPressed;
uint8_t firstChanging;
uint8_t secondChanging;
void loop()
{
  // TOGGLE
  if (pressed & PINA)
    pressed -= PINA;
  else
    pressed += PINA;

  PORTB = pressed;

  // PROBLEM: Complex and not future-proof
  // if (PINA & 0x10)
  // {
  //   secondChanging = 0x00;
  // }
  // else if (secondChanging == 0x00)
  // {
  //   secondPressed = 0xff;
  //   secondPressed = 0xff ? 0x00 : 0xff;
  // }
  // if (PINA & 0x01)
  // {
  //   secondChanging = 0x00;
  // }
  // else if (firstChanging == 0x00)
  // {
  //   firstPressed = 0xff;
  //   firstPressed = 0xff ? 0x00 : 0xff;
  // }

  // PROBLEM: Only one button at a time possible
  // if (secondPressed == 0xff)
  //   PORTB = 0x00;
  // else
  //   PORTB = 0x10;
  // if (firstPressed == 0xff)
  //   PORTB = 0x00;
  // else
  //   PORTB = 0x01;
  // Would work but complex
  // if (secondPressed == 0xff)
  // {
  //   if (firstPressed == 0xff)
  //     PORTB = 0x00;
  //   else
  //     PORTB = 0x01;
  // }
  // else
  // {
  //   if (firstPressed == 0xff)
  //     PORTB = 0x01;
  //   else
  //     PORTB = 0x11;
  // }
}
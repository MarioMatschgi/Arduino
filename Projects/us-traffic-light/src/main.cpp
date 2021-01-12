/*
 * Module for using the uC for controlling an US traffic light
 * 
 * @author Mario Elsnig
 * @date LITEC 2020-12-1
 * @version 1.0
*/

#include <Arduino.h>

#pragma region VARIABLES

#define SHORT_DELAY 1000
#define MEDIUM_DELAY 2000
#define LARGE_DELAY 5000

#pragma region CALLBACKS

#pragma endregion

// Setup
void setup()
{
}

// Loop
void loop()
{
  PORTB = 0x80; // RED B
  _delay_ms(SHORT_DELAY);
  PORTA = 0x01; // RED A
  _delay_ms(SHORT_DELAY);
  PORTA = 0x03; // RED YELLOW A
  _delay_ms(MEDIUM_DELAY);
  PORTA = 0x04; // GREEN A
  _delay_ms(LARGE_DELAY);
  PORTA = 0x02; // YELLOW A
  _delay_ms(LARGE_DELAY);
  PORTA = 0x01; // RED A
  _delay_ms(SHORT_DELAY);

  PORTB = 0xC0; // RED YELLOW B
  _delay_ms(MEDIUM_DELAY);
  PORTB = 0x20; // GREEN B
  _delay_ms(LARGE_DELAY);
  PORTB = 0x40; // YELLOW B
  _delay_ms(LARGE_DELAY);
}

#pragma endregion


/*
* Module for using the uC to controll a 7-segment-display
*
* @author Mario Elsnig
* @date LITEC 2021-07-01
* @version 1.0
*/

#include <Arduino.h>

#pragma region VARIABLES

// Delay for changing in ms
#define DELAY 1000

// List of numbers 0-9 USAGE: list[NUMBER]
uint8_t list[10] = {
    0x3F,
    0x06,
    0x5B,
    0x4F,
    0x66,
    0x6D,
    0xFD,
    0x07,
    0x7F,
    0xEF,
};

#pragma endregion

#pragma region CALLBACKS

// Setup
void setup()
{
  DDRB = 0x00;
  DDRA = 0xFF; // 7 segment display connected
}

// Loop
void loop()
{
  // Iterate trough list to go from 0 to 9
  for (int i = 0; i < sizeof(list); i++)
  {
    PORTA = list[i];  // Set PORTA to number 0-9
    _delay_ms(DELAY); // Wait for DELAY
  }
}

#pragma endregion
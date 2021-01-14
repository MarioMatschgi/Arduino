/*
* Module for using the uC to controll a 7-segment-display with a pushbutton
*
* @author Mario Elsnig
* @date LITEC 2021-14-01
* @version 1.0
*/

#include <Arduino.h>

#pragma region VARIABLES

// Delay for changing in ms
#define DELAY 200

// List of numbers 0-9 USAGE: list[NUMBER]
uint8_t list[10] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0xFD, // 6
    0x07, // 7
    0x7F, // 8
    0xEF, // 9
};
uint8_t curIdx = 0;

#pragma endregion

#pragma region CALLBACKS

// Setup
void setup()
{
  DDRA = 0xFF; // 7 segment display connected
}

// Loop
void loop()
{
  // Manage Buttons
  if (PINB & 0x40) // Up btn
  {
    if (curIdx >= sizeof(list) - 1)
      curIdx = (curIdx + 1) % sizeof(list);
    else
      curIdx++;

    _delay_ms(DELAY);
  }
  else if (PINB & 0x80) // Down btn PB
  {
    if (curIdx == 0)
      curIdx = sizeof(list) - 1;
    else
      curIdx--;

    _delay_ms(DELAY);
  }

  // Set PORTA to number 0-9
  PORTA = list[curIdx];
}

#pragma endregion
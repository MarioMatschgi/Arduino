/*
 Name:        _2020_11_05_AudiTurnlight.ino
 Author:    Mario Elsnig
*/
#include <Arduino.h>

#define OFF_TIME 500
#define ON_TIME 100

uint8_t arr[]{
    0x00,
    0x10,
    0x30,
    0x70,
    0xF0,
};

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting Program!");

  PORTB = 0x00; // Turn the lights off
}

void loop()
{
  // put your main code here, to run repeatedly:
  for (int i = 0; i < sizeof(arr); i++) // Go through array
  {
    PORTB = arr[i];     // Set PORTB to element of array
    _delay_ms(ON_TIME); // Wait for ON_TIME
  }
  PORTB = 0x00;        // Turn the lights off
  _delay_ms(OFF_TIME); // Wait for OFF_TIME
}
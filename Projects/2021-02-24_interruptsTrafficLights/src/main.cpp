/**
* Module for using the uC with interrupts for traffic lights
*
* @author Mario Elsnig
* @date LITEC 2021-02-24
* @version 1.0
*/

#include <Arduino.h>

void setup()
{
  DDRB = 0xff; // PORTB all pins are outputs

  // PORTB test leds
  PORTB = 0xff;
  _delay_ms(1000);
  PORTB = 0x00;

  DDRH = 0x60; // Pin 8 & 9 are outputs

  // PORTH test leds
  PORTH = 0xff;
  _delay_ms(1000);
  PORTH = 0x00;

  DDRD &= ~(1 << PD3); // PD3 is input
  PORTD |= (1 << PD3); // Pull up R activated

  // Set interrupts
  EICRA |= (1 << ISC31); // Falling edge on PD3
  EIFR |= (1 << INTF3);  // Interrupt flag for PD3 INT3
  EIMSK |= (1 << INT3);  // Interrupt 3 for PD3 INT3
  sei();                 // Enable all interrupts
}

void loop()
{
  PORTB = 0x20; // Car green
  _delay_ms(500);

  PORTH = 0x40; // People red
  _delay_ms(500);
}

// Interrupt service routine for INT3 PD3
ISR(INT3_vect)
{
  PORTB = 0x20; // Car green
  _delay_ms(500);

  // Car green flash
  for (int i = 0; i < 5; i++)
  {
    PORTB = 0x20;
    _delay_ms(300);

    PORTB = 0x00;
    _delay_ms(300);
  }

  PORTB = 0x40; // Car yellow
  _delay_ms(1000);

  PORTB = 0x80; // Car red
  _delay_ms(1000);

  PORTH = 0x20; // People green
  _delay_ms(3000);

  // Peole green flash
  for (int i = 0; i < 5; i++)
  {
    PORTH = 0x20;
    _delay_ms(300);

    PORTH = 0x00;
    _delay_ms(300);
  }

  PORTH = 0x40; // People red
  _delay_ms(1000);

  PORTB = 0xC0; // Car red & yellow
  _delay_ms(1000);

  PORTB = 0x20; // Car green
  _delay_ms(1000);
}
// /*
// * Module for using the uC to controll a button
// *
// * @author NAME
// * @date LITEC 2020-12-22
// * @version 1.0
// */

// #include <Arduino.h>

// uint8_t buttonState = 0; //button connected to PB7 . PIN13 on Arduino Atmega 2560
// void setup()
// {
//   DDRB = 0x00;
//   DDRA = 0xFF; //7 segment display connected
// }
// void loop()
// {
//   buttonState = PINB;
//   if (buttonState & 0x80)
//   {
//     PORTA = 0xff;
//   }
//   else
//   {
//     PORTA = 0x00;
//   }
// }

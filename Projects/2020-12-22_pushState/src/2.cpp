// /*
// * Module for using the uC to controll a button
// *
// * @author NAME
// * @date LITEC 2020-12-22
// * @version 1.0
// */

// #include <Arduino.h>

// uint8_t currentButtonState = 0; //button connected to PB7 . PIN13 on Arduino Atmega 2560
// uint8_t ledState = 0;
// void setup()
// {
//   DDRB = 0x00;
//   DDRA = 0xFF; //7 segment display connected
// }
// void loop()
// {
//   currentButtonState = PINB;
//   if (currentButtonState & 0x80)
//   {

//     ledState = (ledState == LOW) ? HIGH : LOW;

//     if (ledState == HIGH)
//     {
//       PORTA = 0xff;
//     }
//     else
//     {
//       PORTA = 0x00;
//     }
//   }
// }

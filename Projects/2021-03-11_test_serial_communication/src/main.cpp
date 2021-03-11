/**
* Module for using the uC with interrupts 
*
* @author Mario Elsnig
* @date LITEC 2021-03-11
* @version 1.0
*/

#include <Arduino.h>
#include "USART.h"

void setup()
{
  USARTInit(0, 9600, 1, 0, 1, 0); // Init Serial port communication
  printf("Hello World!\n");
}

void loop()
{
}
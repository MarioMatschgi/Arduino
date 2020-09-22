/**
* Module for using the uC as input and output device
*
* @author Mario Elsnig
* @date LITEC 2010
* @version 1.0
*
* @see I2CMaster.h for description of interface
*/

// the setup function runs once when you press reset or power the board
void setup() 
{
	DDRB = 0xff;
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	int _time = 500;

	PORTB = 0xff;
	_delay_ms(_time);
	PORTB = 0x00;
	_delay_ms(_time);
}

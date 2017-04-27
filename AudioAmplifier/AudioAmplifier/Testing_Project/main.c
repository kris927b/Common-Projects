/*
 * Testing_Project.c
 *
 * Created: 4/24/2017 10:33:42 AM
 * Author : Kristian N�rgaard Jensen
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include "Dig_Pot_Lib.h"
#include "std_lib.h"


int main(void)
{
	/* Set the MOSI & SCK as Output lines */
	DDRB |= (1 << PINB3) | (1 << PINB5) | (1 << PINB0);
	//DDRB &= ~(1 << PINB4);
	//DDRD |= (1 << PIND0);
	/* Set the SCK pin to low */
	//PORTB &= ~(1 << PINB5);
	PORTB |= (1 << PINB0);
	//PORTD &= ~(1 << PIND0);
	/* Enable SPI */
	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);

    while (1) {
		PORTB &= ~(1 << PINB0);
		SPDR = 0b00100100;
		while(!(SPSR & (1 << SPIF)));
		PORTB |= (1 << PINB0);
		delay(300);
    }
}


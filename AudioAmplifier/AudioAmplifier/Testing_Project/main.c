/*
 * Testing_Project.c
 *
 * Created: 4/24/2017 10:33:42 AM
 * Author : Kristian Nørgaard Jensen
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include "Dig_Pot_Lib.h"
#include "std_lib.h"


int main(void)
{
	/* Set the MOSI & SCK as Output lines */
// 	DDRB |= (1 << PINB3) | (1 << PINB5) | (1 << PINB2);
// 	//DDRB &= ~(1 << PINB4);
// 	//DDRD |= (1 << PIND0);
// 	/* Set the SCK pin to low */
// 	//PORTB &= ~(1 << PINB5);
// 	PORTB |= (1 << PINB0);
// 	//PORTD &= ~(1 << PIND0);
// 	/* Enable SPI */
// 	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
	Init_Pot_Meter();

    while (1) {
		Write_Pot_Meter(255, CS_3);
		delay(300);
    }
}


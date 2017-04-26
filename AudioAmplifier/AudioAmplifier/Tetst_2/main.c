/*
 * Tetst_2.c
 *
 * Created: 4/26/2017 1:16:28 PM
 * Author : kris-
 */ 

#include <avr/io.h>

void delay(uint32_t ms);

int main(void)
{
// 	/* Set the MOSI & SCK as Output lines */
// 	DDRB |= (1 << PINB3) | (1 << PINB5) | (1 << PINB0);
// 	//DDRB &= ~(1 << PINB4);
// 	//DDRD |= (1 << PIND0);
// 	/* Set the SCK pin to low */
// 	//PORTB &= ~(1 << PINB5);
// 	PORTB |= (1 << PINB0);
// 	//PORTD &= ~(1 << PIND0);
// 	/* Enable SPI */
// 	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
	DDRB = 0xFF;

	while (1) {
		PORTB = 0x00;
// 		SPDR = 0b00100100;
// 		while(!(SPSR & (1 << SPIF)));
		PORTB = 0xFF;
		delay(100);
	}
}

void delay(uint32_t ms) {
	uint32_t i = ms * 480;
	while(--i > 0);
}


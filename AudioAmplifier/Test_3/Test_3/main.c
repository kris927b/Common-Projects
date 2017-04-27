/*
 * Test_3.c
 *
 * Created: 4/26/2017 1:26:27 PM
 * Author : kris-
 */ 
 #define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

void delay(uint32_t ms);

int main(void)
{
    /* Set the MOSI & SCK as Output lines */
    DDRB |= (1 << PINB3) | (1 << PINB5) | (1 << PINB0) | (1 << PINB2);
    //DDRB &= ~(1 << PINB4);
    //DDRD |= (1 << PIND0);
    /* Set the SCK pin to low */
    //PORTB &= ~(1 << PINB5);
    PORTB |= (1 << PINB0) | (1 << PINB2);
    //PORTD &= ~(1 << PIND0);
    /* Enable SPI */
    SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
    while (1) {
		for(int i = 0; i < 255; i += 4) {
			PORTB &= ~(1 << PINB0);
			SPDR = 0b00000000;
			while(!(SPSR & (1 << SPIF)));
			SPDR = i;
			while(!(SPSR & (1 << SPIF)));
			PORTB |= (1 << PINB0);
			delay(1);
		}

		for(int i = 255; i > 0; i -= 4) {
			PORTB &= ~(1 << PINB0);
			SPDR = 0b00000000;
			while(!(SPSR & (1 << SPIF)));
			SPDR = i;
			while(!(SPSR & (1 << SPIF)));
			PORTB |= (1 << PINB0);
			delay(1);
		}
    }
}

void delay(uint32_t ms) {
	uint32_t i = ms * 471;
	while(--i > 0);
}
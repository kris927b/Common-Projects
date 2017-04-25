/*
 * SPI_Lib.s
 *
 * Created: 3/22/2017 14:00:00 AM
 * Author : Kristian Nørgaard Jensen
 * Description: SPI Library
 */

#include <avr/io.h>
#include <string.h>
#include "SPI_Lib.h"

//Terminology of SPI			|| Terminology of digital Pot meter
//MOSI == "Master Out Slave In" || SPO
//MISO == "Master In Slave Out" || SPI
//SCK == SPI Clock Line			|| SCK
//SS == "Slave Select			|| CS == "Chip Select"
 
 
void SPI_Init_Master() {
	/* Set the MOSI & SCK as Output lines */
	DDRB |= (1 << PINB3) | (1 << PINB5);
	/* Set the SCK pin to low */
	PORTB &= ~(1 << PINB5);
	
	/* Enable SPI */
	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0); 
}

uint8_t SPI_Send_Data(char data) {
	/* Place the data in the transmitter buffer */
	SPDR = data;

	/* Wait for the transmitter to complete */
	while(!(SPSR & (1 << SPIF)));

	return SPDR
}

uint8_t * SPI_Send_Large_Data(char *data) {
	/* Find the length of the data array */
	uint8_t spi_data[2] = {};
	uint16_t len = 2;
	for(int i = 0; i < len; i++) {
		spi_data[i] = SPI_Send_Data(data[i]);
	}

	return spi_data
}
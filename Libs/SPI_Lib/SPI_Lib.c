/*
 * SPI_Lib.s
 *
 * Created: 3/22/2017 14:00:00 AM
 * Author : Kristian N�rgaard Jensen
 * Description: SPI Library
 */

#include <avr/io.h>
#include <string.h>
#include "SPI_Lib.h"

//Terminology of SPI
//MOSI == "Master Out Slave In"
//MISO == "Master In Slave Out"
//SCK == SPI Clock Line
//SS == "Slave Select
 
 
void SPI_Init_Master() {
	/* Set the MOSI & SCK as Output lines */
	DDRB |= (1 << PINB3) | (1 << PINB5);
	/* Set the SCK pin to low */
	PORTB &= ~(1 << PINB5);
	
	/* Enable SPI */
	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0); 
}

void SPI_Send_Data(char data) {
	/* Place the data in the transmitter buffer */
	SPDR = data

	/* Wait for the transmitter to complete */
	while(!(SPDR & (1 << SPIF)));
}

void SPI_Send_Large_Data(char *data) {
	/* Find the length of the data array */
	uint16_t len = strlen(data);
	for(int i = 0; i < len; i++) {
		SPI_Send_Data(data[i]);
	}


}
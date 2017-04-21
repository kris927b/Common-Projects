/*
 * SPI_Lib.s
 *
 * Created: 3/22/2017 14:00:00 AM
 * Author : Kristian Nørgaard Jensen
 * Description: SPI Library
 */

#include <avr/io.h>
#include "SPI_Lib.h"

//Terminology of SPI
//MOSI == "Master Out Slave In"
//MISO == "Master In Slave Out"
//SCK == SPI Clock Line
//SS == "Slave Select
 
 
void SPI_Init_Master() {
	/* Set the MOSI & SCK as Output lines */
	DDRB |= (1 << PINB5) | (1 << PINB3);
	
}
/*
 * Dig_Pot_Lib.c
 *
 * Created: 4/21/2017 9:35:03 AM
 *  Author: Kristian Nørgaard Jensen
 */
 
#include <avr/io.h>
#include "Dig_Pot_Lib.h"
#include "SPI_Lib.h"

void Init_Pot_Meter() {
	SPI_Init_Master();
	CS_D |= (1 << CS_1) | (1 << CS_2) | (1 << CS_3);
}

void Write_Pot_Meter(uint8_t value, uint8_t CS_pin) {
	CS &= ~(1 << CS_pin);
	char data[2] = {0b00100000, value};
	SPI_Send_Large_Data(data);
} 

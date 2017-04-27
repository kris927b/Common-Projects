/*
 * SPI_Lib.h
 *
 * Created: 3/22/2017 14:00:00 AM
 * Author : Kristian Nørgaard Jensen
 * Description: SPI Library
 */

#ifndef SPI_LIB_H_
#define SPI_LIB_H_

#include <avr/io.h>

void SPI_Init_Master(void);
uint8_t SPI_Send_Data(uint8_t data);
uint8_t * SPI_Send_Large_Data(uint8_t data[]);

#endif /* SPI_LIB_H_ */
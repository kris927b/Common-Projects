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
void SPI_Send_Data(char data);

#endif
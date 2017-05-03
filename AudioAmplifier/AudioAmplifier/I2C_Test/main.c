/*
 * I2C_Test.c
 *
 * Created: 5/1/2017 9:00:55 AM
 * Author : Kristian
 */ 

#include <avr/io.h>
#include "i2cLib.h"
#include "LCD_lib.h"
#include "std_lib.h"


int main(void)
{
	DDRD |= (1 << DDD3);
	PORTD |= (1 << PORTD3);
	i2cInit();
    /* Replace with your application code */
    i2cStart();
	i2cWrite(ADDR);
	i2cWrite(0x00);
	i2cWrite(0x38);
	i2cWrite(0x00);
	i2cWrite(0x39);
	i2cWrite(0x14);
	i2cWrite(0x7F);
	i2cWrite(0x50);
	i2cWrite(0x6C);
	i2cWrite(0x0C);
	i2cWrite(0x01);
	i2cStop();

	i2cStart();
	i2cWrite(ADDR);
	i2cWrite(0x00);
	i2cWrite(0x00);
	i2cStop();
	
	i2cStart();
	i2cWrite(ADDR);
	i2cWrite(0x00);
	i2cWrite(0x80);
	i2cStop();

	i2cStart();
	i2cWrite(ADDR);
	i2cWrite(0x40);
	i2cWrite('H');
	i2cStop();
}


/*
 * LCD_lib.c
 *
 * Created: 4/24/2017 8:45:38 AM
 *  Author: Kristian Nørgaard Jensen
 */ 

 #include "i2cLib.h"

void send_screen_data(unsigned char data) {
	//Send start condition
	i2cStart();
	//Send SLA_W
	i2cWrite(ADDR);
	//Send data
	i2cWrite(data);
	//Send stop condition
	i2cStop();
}
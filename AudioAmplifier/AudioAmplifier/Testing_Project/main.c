/*
 * Testing_Project.c
 *
 * Created: 4/24/2017 10:33:42 AM
 * Author : Kristian Nørgaard Jensen
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include "i2cLib.h"
#include "std_lib.h"
#include "LCD_lib.h"

int main(void)
{
	i2cInit();
	initDisp();

	delay(10);

	char hello[8] = {72, 69, 76, 76, 79, 0};

	write_first_line(hello, 0);

    while (1) {
    }
}


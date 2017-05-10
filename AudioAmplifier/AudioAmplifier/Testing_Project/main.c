/*
 * Testing_Project.c
 *
 * Created: 4/24/2017 10:33:42 AM
 * Author : Kristian Nørgaard Jensen
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include "Dig_Pot_Lib.h"
#include "std_lib.h"


int main(void)
{
	Init_Pot_Meter();

    while (1) {
		Write_Pot_Meter(255, CS_2);
		Write_Pot_Meter(0, CS_1);
		Write_Pot_Meter(90, CS_0);
		delay(300);
    }
}


/*
 * Testing_Project.c
 *
 * Created: 4/24/2017 10:33:42 AM
 * Author : Kristian N�rgaard Jensen
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/delay.h>
#include "Dig_Pot_Lib.h"
#include "std_lib.h"


int main(void)
{
	Init_Pot_Meter();
	Write_Pot_Meter(10, CS_1);
    /* Replace with your application code */
    while (1) 
    {
    }
}

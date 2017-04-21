/*
 * AudioAmplifier.c
 *
 * Created: 4/21/2017 10:44:40 AM
 * Author : Matej Majtan, Domenico Villani & Kristian Nørgaard Jensen
 */ 

#include <avr/io.h>
#include <stdbool.h>

/* Our own libraries, found in the Libs folder in the project */
#include "Libs/Dig_Pot_Lib.h" //Library for the digital pot meter
#include "Libs/SPI_Lib.h" //Library for SPI functionality
#include "Libs/std_lib.h" //Library for common functions that are useful
#include "Libs/usart_lib.h" //Library for Usart
//Include TWI library
//Include LCD library

//Functionality for the four tasks
//Function to update display
//Function to turn off display
//Function to change menu_item

//Flags for different task
uint8_t display_FLAG = 0; //When to update the display (every 100 ms)
uint8_t back_light_FLAG = 0; //When to turn of backlight on the display (after 2 sec.)
uint8_t activity_FLAG = 0; //Are there any activity

//Booleans for different tasks
bool display_task = false;
bool back_light_task = false;

int main(void)
{
	
	init_usart(9600, NONE, ONE);
	Init_Pot_Meter();
	// Init the LCD


    /* Replace with your application code */
    while (1) 
    {
		if(display_task) {
			//Update the display
			//Set the flag value to start again
		}

		if(back_light_task) {
			//Turn of the back_light 

		}
    }
}


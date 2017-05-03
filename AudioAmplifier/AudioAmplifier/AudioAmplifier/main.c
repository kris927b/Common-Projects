/*
 * AudioAmplifier.c
 *
 * Created: 4/21/2017 10:44:40 AM
 * Author : Matej Majtan, Domenico Villani & Kristian Nørgaard Jensen
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

/* Our own libraries, found in the Libs folder in the project */
#include "Libs/Dig_Pot_Lib.h"	//Library for the digital pot meter
#include "Libs/SPI_Lib.h"		//Library for SPI functionality
#include "Libs/std_lib.h"		//Library for common functions that are useful
#include "Libs/usart_lib.h"		//Library for Usart
#include "Libs/i2cLib.h"		//Library for TWI
#include "Libs/LCD_lib.h"		//Library for the LCD

//Functionality for the four tasks
//Function to update display
void update_display(void);
void init_timer(void);
void activity(void);
void init_rot_but(void);
void update_display_values(uint8_t device, uint8_t direction);	// Device: 1 = rotary encoder, 0 = button; 
																// Direction: 1 = up, 0 = down (Direction is only used for the rotary encoder)
//Function to turn off display
//Function to change menu_item

//Index for volumes
uint8_t vol_index[5] = {7, 7, 7, 7, 7};
uint8_t vol_values[16] = {0, 1, 2, 4, 6, 8, 12, 16, 24, 32, 48, 64, 96, 128, 192, 255};
uint8_t ctrl_index = 0;

//Flags for different task
uint8_t display_FLAG = 0; //When to update the display (every 100 ms)
uint8_t display_counter = 0;
uint8_t back_light_FLAG = 0; //When to turn of back light on the display (after 2 sec.)
uint16_t back_light_counter = 0;
uint8_t activity_FLAG = 1; //Are there any activity
uint8_t activity_counter = 1;
uint8_t menu_FLAG = 0;
uint8_t menu_index = 0;
uint8_t equalizer_menu_index = 0;
uint8_t equalizer_menu_FLAG = 0;
uint8_t ctrl_menu_FLAG = 1;
char *vol_control[5];
char *main_menu[5];
char *equalizer_menu[5];

//Menu titles

ISR(PCINT0_vect) {
	if((PINB & (1 << PINB7)) == 0) {
		activity();
		update_display_values(0, 0);
	}
}


ISR(PCINT1_vect) {
	if((PINC & (1 << PINC0)) == 0) {
		if (PINC & (1 << PINC1)) { //CW
			activity();
			update_display_values(1, 0);
		} else { //CCW
			activity();
			update_display_values(1, 1);
		}
	}
}


ISR(TIMER1_COMPA_vect) {
	if(++display_counter == 10) {
		display_FLAG = 1;
		display_counter = 0;
	}

	if (activity_FLAG && activity_counter++ == 20) {
		activity_FLAG = 0;
		activity_counter = 0;
	}

	if(++back_light_counter == 500 && !activity_FLAG) {
		back_light_FLAG = 1;
		back_light_counter = 0;
	}
}


int main(void) {
	init_usart(9600, NONE, ONE);
	Init_Pot_Meter();
	i2cInit();
	initDisp();
	init_timer();
	init_rot_but();

	vol_control[0] = "Volume";
	vol_control[1] = "Bass";
	vol_control[2] = "Mid";
	vol_control[3] = "Treble";
	vol_control[4] = "Brightness";
	main_menu[0] = "Equalizer";
	main_menu[1] = "Brightness";
	main_menu[2] = "Reset";
	main_menu[3] = "Exit";
	main_menu[4] = "  ";
	equalizer_menu[0] = "Bass";
	equalizer_menu[1] = "Mid";
	equalizer_menu[2] = "Treble";
	equalizer_menu[3] = "Back";
	equalizer_menu[4] = "  ";
	sei();
    while (1) 
    {
		if(display_FLAG) {
			update_display();
			display_FLAG = 0;
		}

		if(activity_FLAG) {
			PORTD |= (1 << PORTD3);
		}

		if (back_light_FLAG) {
			PORTD &= ~(1 << PORTD3);
			back_light_FLAG = 0;
		}
    }
}

void update_display() {
	//Send the menu item to the display
	if (ctrl_menu_FLAG) {
		write_volume_control(vol_control[ctrl_index], vol_values[vol_index[ctrl_index]]);
	} else {
		if (equalizer_menu_FLAG) {
			write_menu_items(equalizer_menu[equalizer_menu_index], equalizer_menu[equalizer_menu_index + 1]);
		} else {
			write_menu_items(main_menu[menu_index], main_menu[menu_index + 1]);
		}
	}
	//Update the brightness 

}

void update_display_values(uint8_t device, uint8_t direction) {
	if (device) { //If the device is the rotary encoder
		if (direction) { //If the direction is up
			if (menu_FLAG) { //If we are in a menu
				if (equalizer_menu_FLAG) { //If we are in the equalizer menu
					if (ctrl_menu_FLAG) { //If we are in a control menu
						if(vol_index[ctrl_index] < 15) { 
							vol_index[ctrl_index]++;
						}
					} else {
						if (equalizer_menu_index < 3){
							equalizer_menu_index++;
						}
					}
				} else if(ctrl_menu_FLAG){
					if(vol_index[ctrl_index] > 0) {
						vol_index[ctrl_index]++;
					}
				} else {
					if(menu_index < 3) {
						menu_index++;
					}
				}
			} else {
				if(vol_index[ctrl_index] < 15) {
					vol_index[ctrl_index]++;
				}
			}
		} else {
			if (menu_FLAG) {
				if (equalizer_menu_FLAG) {
					if (ctrl_menu_FLAG) {
						if(vol_index[ctrl_index] > 0) {
							vol_index[ctrl_index]--;
						}
					} else {
						if (equalizer_menu_index > 0) {
							equalizer_menu_index--;
						}
					}
				} else if(ctrl_menu_FLAG){
					if(vol_index[ctrl_index] > 0) {
						vol_index[ctrl_index]--;
					}
				} else {
					if(menu_index > 0) {
						menu_index--;
					}
				}
			} else {
				if(vol_index[ctrl_index] > 0) {
					vol_index[ctrl_index]--;
				}
			}
		}
	} else { //The button is pressed 
		if (menu_FLAG) { // are we in the menu?
			if (equalizer_menu_FLAG) { //Are we in the equalizer menu?
				if (equalizer_menu_index == 3) { //If the index is 3 we wanna to go back
					equalizer_menu_FLAG = 0;
					equalizer_menu_index = 0;
				} else if(ctrl_menu_FLAG) { //If we are in a control menu, we wanna to go back to the equalizer menu
					ctrl_menu_FLAG = 0;
				} else { //If nothing of the above option is true, then we wanna go into a control menu. 
					ctrl_menu_FLAG = 1;
					switch(equalizer_menu_index) { //Select the right index
						case 0:
							ctrl_index = 1;
							break;
						case 1:
							ctrl_index = 2;
							break;
						case 2:
							ctrl_index = 3;
							break;
					}
				}
			} else {
				if(ctrl_menu_FLAG) {
					ctrl_menu_FLAG = 0;
				} else {
					switch (menu_index) {
						case 0:
							equalizer_menu_FLAG = 1;
							break;
						case 1:
							ctrl_menu_FLAG = 1;
							ctrl_index = 4;
							break;
						case 2:
							for(uint8_t i = 0; i < 5; i++) {//Reset the values
								vol_index[i] = 7;
							}
							break;
						case 3:
							menu_FLAG = 0;
							ctrl_index = 0;
							ctrl_menu_FLAG = 1;
							break;
					}
				}
			}
		} else {
			menu_FLAG = 1;
		}
	}
}

void init_timer() {
	TCNT1 = 0;

	OCR1A = 20000;

	TIMSK1 |= (1 << OCF1A);

	TCCR1B |= (1 << CS11) | (1 << WGM12);
}

void activity() {
	activity_FLAG = 1;
	activity_counter = 0;
	back_light_counter = 0;
}

void init_rot_but() {
	PCICR |= (1 << PCIE1) | (1 << PCIE0);
	PCMSK1 |= (1 << PCINT8);
	PCMSK0 |= (1 << PCINT7);
}


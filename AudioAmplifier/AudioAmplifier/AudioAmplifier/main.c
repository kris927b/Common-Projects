/*
 * AudioAmplifier.c
 *
 * Created: 4/21/2017 10:44:40 AM
 * Author : Matej Majtan, Domenico Villani & Kristian Nørgaard Jensen
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

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
void initBrightnessTimer(void);
void setBrightness(uint8_t brightness);
void showScreenSaver(void);
//Function to turn off display
//Function to change menu_item

//Index for volumes
uint8_t vol_index[5] = {7, 7, 7, 7, 15};
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
uint8_t screen_saver_FLAG = 0;
uint16_t screen_saver_counter = 0;
uint8_t screen_saver_pos_idx = 0;
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
	if(++display_counter == 10 && !screen_saver_FLAG) {
		display_FLAG = 1;
		display_counter = 0;
	}

	if (activity_FLAG && ++activity_counter == 20) {
		activity_FLAG = 0;
		activity_counter = 0;
	}

	if(++back_light_counter == 500 && !activity_FLAG) {
		back_light_FLAG = 1;
		back_light_counter = 0;
	}

	if (screen_saver_FLAG) {
		if (++screen_saver_counter == 100 && !activity_FLAG) {
			screen_saver_counter = 0;
			showScreenSaver();
			ctrl_index = 0;
			ctrl_menu_FLAG = 1;
			menu_FLAG = 0;
		}
	} else {
		if (++screen_saver_counter == 1000 && !activity_FLAG) {
			screen_saver_FLAG = 1;
			screen_saver_counter = 0;
			display_FLAG = 0;
		}
	}
}


int main(void) {
	init_usart(9600, NONE, ONE);
	Init_Pot_Meter();
	i2cInit();
	initDisp();
	init_timer();
	init_rot_but();
	initBrightnessTimer();

	vol_control[0] = "Volume";
	vol_control[1] = "Bass";
	vol_control[2] = "Mid-range";
	vol_control[3] = "Treble";
	vol_control[4] = "Brightness";
	main_menu[0] = "1.Equalizer";
	main_menu[1] = "2.Brightness";
	main_menu[2] = "3.Reset";
	main_menu[3] = "4.Exit";
	main_menu[4] = "  ";
	equalizer_menu[0] = "1.Bass";
	equalizer_menu[1] = "2.Mid-range";
	equalizer_menu[2] = "3.Treble";
	equalizer_menu[3] = "4.Back";
	equalizer_menu[4] = "  ";
	sei();
    while (1) 
    {
		if(display_FLAG) {
			update_display();
			display_FLAG = 0;
		}

		if(activity_FLAG) {
			setBrightness(vol_values[vol_index[4]]);
		}

		if (back_light_FLAG) {
			setBrightness(0);
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
	if (ctrl_index == 4) {
		setBrightness(vol_values[vol_index[ctrl_index]]);
	}
}

void update_display_values(uint8_t device, uint8_t direction) {
	/************************************************************************/
	/* Menu overview:														*/
	/*	Master Volume			(Ctrl Menu)									*/
	/*	-> 1.Equalizer			(Main menu)									*/
	/*	-> -> 1.Bass			(EQ Menu)									*/
	/*  -> -> 2.Mid-range		(EQ Menu)									*/
	/*	-> -> 3.Treble			(EQ Menu)									*/
	/*	-> -> 4.Back			(EQ Menu)									*/
	/*	-> 2.Brightness			(Main Menu)									*/
	/*  -> 3.Reset				(Main Menu)									*/
	/*  -> 4.Exit				(Main Menu)									*/
	/************************************************************************/
	if (device) {											//If the device is the rotary encoder
		if (direction) {									//If the direction is up
			if (menu_FLAG) {								//If we are in a menu
				if (equalizer_menu_FLAG) {					//If we are in the equalizer menu
					if (ctrl_menu_FLAG) {					//If we are in a control menu
						if(vol_index[ctrl_index] < 15) {	//If the vol index is less than 15, we can increment it
							vol_index[ctrl_index]++;
						}
					} else {								//If we are not in a ctrl menu, then we must be scrolling through the equalizer menu
						if (equalizer_menu_index < 3){		//As long as the index of the menu is less than 3 we are able to scroll further down
							equalizer_menu_index++;
						}
					}
				} else if(ctrl_menu_FLAG){					//If we are not in the equalizer menu and the ctrl menu flag is set, we must be in the brightness menu
					if(vol_index[ctrl_index] < 15) {		//So if the index is less than 15 we ca increment it, just like with the equalizer above	
						vol_index[ctrl_index]++;
					}
				} else {									//If we are not in the equalizer menu, and we are not in the ctrl menu,
					if(menu_index < 3) {					//then we must be scrolling through the main menu
						menu_index++;						//We want to scroll through the menu if the index of the menu is less than 3. Otherwise we must stall.
					}
				}
			} else {
				if(vol_index[ctrl_index] < 15) {			//If we are not in a menu we must be controlling the master volume.
					vol_index[ctrl_index]++;				//So if the index of the volume is no larger than 15, we want to increment the volume
				}
			}
		} else {											//Else the direction must be down
			if (menu_FLAG) {								//If we are in the main menu
				if (equalizer_menu_FLAG) {					//If we are in the EQ menu
					if (ctrl_menu_FLAG) {					//If we are in a ctrl menu
						if(vol_index[ctrl_index] > 0) {		//If the ctrl index is still bigger than zero, then we can decrement it.
							vol_index[ctrl_index]--;
						}
					} else {								//If we re not in a control menu, we must be scrolling through the EQ menu.
						if (equalizer_menu_index > 0) {		//As long as the index is larger than zero, we can scroll through the menu points
							equalizer_menu_index--;
						}
					}
				} else if(ctrl_menu_FLAG){					//If we are in the main menu and in a ctrl menu
					if(vol_index[ctrl_index] > 0) {			//Then if the menu index is bigger than zero, then we want to decrement the index
						vol_index[ctrl_index]--;
					}
				} else {									//If none of the above is true, then we must be in the main menu
					if(menu_index > 0) {					//So if the index is larger than 0 then we can scroll down trough the menu
						menu_index--;
					}
				}
			} else {										//If we are not in the menu, We must be controlling the master volume
				if(vol_index[ctrl_index] > 0) {				//If the ctrl index is bigger than zero, then we can decrement the master volume
					vol_index[ctrl_index]--;
				}
			}
		}
	} else {												//The button is pressed 
		if (menu_FLAG) {									// are we in the menu?
			if (equalizer_menu_FLAG) {						//Are we in the equalizer menu?
				if (equalizer_menu_index == 3) {			//If the index is 3 we wanna to go back
					equalizer_menu_FLAG = 0;
					equalizer_menu_index = 0;
				} else if(ctrl_menu_FLAG) {					//If we are in a control menu, we wanna to go back to the equalizer menu
					ctrl_menu_FLAG = 0;
				} else {									//If nothing of the above option is true, then we wanna go into a control menu. 
					ctrl_menu_FLAG = 1;
					switch(equalizer_menu_index) {			//Select the right index
						case 0:
							ctrl_index = 1;					//Select the Bass menu
							break;
						case 1:								
							ctrl_index = 2;					//Select the Mid range menu
							break;
						case 2:
							ctrl_index = 3;					//Select the Treble menu
							break;
					}
				}
			} else {										//If we are not in the EQ menu, then we must be in the main menu
				if(ctrl_menu_FLAG) {						//If we are in a ctrl menu, we must be in the brightness menu
					ctrl_menu_FLAG = 0;						//However since it is a button press we want to set the flag to false so we get out of the menu	
				} else {									//If we are in the main menu
					switch (menu_index) {					//We ant to figure out what we want to do, depending on what menu item we are highlighting
						case 0:								
							equalizer_menu_FLAG = 1;		//If we are highlighting EQ menu, then we want to access it
							break;
						case 1:
							ctrl_menu_FLAG = 1;				//If we are highlighting the Brightness menu, then we wanna access it
							ctrl_index = 4;
							break;
						case 2:								//If we are highlighting Reset, then we wanna reset all values
							for(uint8_t i = 0; i < 5; i++) {//Reset the values
								vol_index[i] = 7;
							}
							break;
						case 3:
							menu_FLAG = 0;					//If we are highlighting the Exit point, then we wanna back out and view the master volume ctrl.
							ctrl_index = 0;
							ctrl_menu_FLAG = 1;
							break;
					}
				}
			}
		} else {
			menu_FLAG = 1;									//If a button press occurs and we are at the master volume, then we want to go to the main menu
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
	screen_saver_counter = 0;
	screen_saver_FLAG = 0;
	display_FLAG = 1;
}

void init_rot_but() {
	PCICR |= (1 << PCIE1) | (1 << PCIE0);
	PCMSK1 |= (1 << PCINT8);
	PCMSK0 |= (1 << PCINT7);
}

void initBrightnessTimer() {
	DDRD |= (1 << DDD3); //setting pind3 as output
	TCCR2A |= (1 << COM2B1) | (1 << WGM21) | (1 << WGM20); //non-inverting mode for OC2B, fastPWM
	TCCR2B |= (1 << CS20); //prescaler 8
	OCR2B = 255;
}

void setBrightness(uint8_t brightness) {
	OCR2B = brightness;
}

void showScreenSaver() {
	char line[17] = {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 0};
	char screen_saver[8] = "t(-_-t)";
	uint8_t i = 0;
	uint8_t j = 0;

	if (screen_saver_pos_idx >= 10){
		i = screen_saver_pos_idx - 10;
	} else {
		i = screen_saver_pos_idx;
	}

	for (i; i < strlen(screen_saver) + screen_saver_pos_idx; i++){
		line[i] = screen_saver[j];
		j++;
	}

	if (screen_saver_pos_idx < 10) {
		screen_saver_pos_idx++;
		write_first_line(line, 0);
		char line_2[17] = {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 0};
		write_second_line(line_2, 0);
	} else if (screen_saver_pos_idx >= 10 && screen_saver_pos_idx < 20) {
		screen_saver_pos_idx++;
		char line_2[17] = {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 0};
		write_first_line(line_2, 0);
		write_second_line(line, 0);
	} else if (screen_saver_pos_idx == 20) {
		screen_saver_pos_idx = 0;
	}
}
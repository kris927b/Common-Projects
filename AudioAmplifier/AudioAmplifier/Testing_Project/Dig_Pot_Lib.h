/*
 * Dig_Pot_Lib.h
 *
 * Created: 4/21/2017 9:35:26 AM
 *  Author: Kristian Nørgaard Jensen
 */ 


#ifndef DIG_POT_LIB_H_
#define DIG_POT_LIB_H_

#define CS_1 PINB0 // Master Pot meter
#define CS_2 PINB1 // Bass Pot meter
#define CS_3 PINB2 // Treble Pot meter
#define CS_D DDRB
#define CS PORTB

#include <avr/io.h>

void Init_Pot_Meter(void);
void Write_Pot_Meter(uint8_t value, uint8_t CS_pin);

#endif /* DIG_POT_LIB_H_ */
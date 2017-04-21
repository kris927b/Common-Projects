/*
 * Dig_Pot_Lib.h
 *
 * Created: 4/21/2017 9:35:26 AM
 *  Author: Kristian Nørgaard Jensen
 */ 


#ifndef DIG_POT_LIB_H_
#define DIG_POT_LIB_H_

#define CS_1 PINB0
#define CS_2 PINB1
#define CS_3 PINB2

#include <avr/io.h>

void Init_Pot_Meter(void);
void Write_Pot_Meter(uint8_t value, uint8_t CS);

#endif /* DIG_POT_LIB_H_ */
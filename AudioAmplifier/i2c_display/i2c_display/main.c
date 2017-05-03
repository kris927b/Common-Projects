/*
 * i2c_display.c
 *
 * Created: 4/21/2017 9:01:51 AM
 * Author : Matej Majtan
 */ 

#include <avr/io.h>
#include "std_Lib.h"
#include "LCD_lib.h"

#define LCD_L1		0x80
#define LCD_L2		0xC0

int main(void)
{
    i2cInit();
    initDisp();
    sendCmd(0x01);
    char *str_1 = "1.Equalizer"; // \x8F
	char *str_2 = "2.Reset";
    while (1) 
    {   
        write_first_line(str_1, 1);
		write_second_line(str_2, 1);

        delay(500);
    }
}


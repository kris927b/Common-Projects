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
    DDRD |= (1 << DDD3);
    PORTD |= (1 << PORTD3);
    i2cInit();
    initDisp();
    sendCmd(0x01);
    char *str = "Hejd\x86, Farzad"; // \x8F
    while (1) 
    {   
        for (uint8_t i = 0x00; i <= 0x0F; i++){ //0x00-0x27 first line
            sendCmd(0x00);
            sendCmd(0x80 | i);
            sendData(str[i]);
        }
        for (uint8_t i = 0x40; i <= 0x4F; i++){ //0x40-0x67 second line
            sendCmd(0x00);
            sendCmd(0x80 | i);
            sendData(str[i-0x40]);
        }

        delay(500);
    }
}


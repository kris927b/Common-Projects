#include <avr/io.h>
#include <string.h>
#include "LCD_lib.h"


void sendCmd(char data){
    i2cStart();
    i2cWrite(SLA_W);
    i2cWrite(0x00);
    i2cWrite(data);
    i2cStop();
}

void sendData(char data){
    i2cStart();
    i2cWrite(SLA_W);
    i2cWrite(0x40);
    i2cWrite(data);
    i2cStop();
}

void initDisp(){
	DDRD |= (1 << DDD3);
	PORTD |= (1 << PORTD3);
    i2cStart();
    i2cWrite(SLA_W);
    i2cWrite(0x00);//cmd
    i2cWrite(0x38);//8 bit bus, 2 line disp mode, normal mode
    i2cWrite(0x00);
    i2cWrite(0x39);//8 bit bus, 2 line disp mode, extended mode
    i2cWrite(0x14);//internal OSC freq
    i2cWrite(0x7F);//contrast setting (Highest)
    i2cWrite(0x50);//set ICON address
    i2cWrite(0x6C);//follower control
    i2cWrite(0x0C);//display ON
    i2cWrite(0x01);//clear disp;ay
    i2cStop();
}

void write_first_line(char *data, uint8_t menu) {
	uint16_t len = strlen(data);
	char str[16] = {32};
	uint16_t i = 0;
	uint16_t j = 0;

	if(menu) {
		str[0] = '\x7E';
		i = 1;
		len++;
	}
	for(i; i < len; i++) {
		str[i] = data[j];
		j++;
	}

	for (uint8_t i = 0x00; i <= 0x0F; i++){ //0x00-0x27 first line
		sendCmd(0x00);
		sendCmd(0x80 | i);
		sendData(str[i]);
	}
}

void write_second_line(char *data, uint8_t menu) {
	uint16_t len = strlen(data);
	char str[16] = {32};
	uint16_t i = 0;
	uint16_t j = 0;

	if(menu) {
		i = 1;
		len++;
	}
	for(i; i < len; i++) {
		str[i] = data[j];
		j++;
	}


	for (uint8_t i = 0x40; i <= 0x4F; i++){ //0x40-0x67 second line
		sendCmd(0x00);
		sendCmd(0x80 | i);
		sendData(str[i-0x40]);
	}
}
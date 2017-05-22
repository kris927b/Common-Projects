#include <avr/io.h>
#include <string.h>
#include <stdio.h>
#include "LCD_lib.h"


void sendCmd(char data) {
    i2cStart();
    i2cWrite(SLA_W);
    i2cWrite(0x00);
    i2cWrite(data);
    i2cStop();
}

void sendData(char data) {
    i2cStart();
    i2cWrite(SLA_W);
    i2cWrite(0x40);
    i2cWrite(data);
    i2cStop();
}

void initDisp() {
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
	char str[16] = {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32};
	uint16_t i = 0;
	uint16_t j = 0;

	if(menu) {
		str[0] = '>';
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
	char str[16] = {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32};
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

void write_volume_control(char name[], uint8_t value) {
	char line_1[17] = {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 0};
	char line_2[17] = {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 0};
	uint8_t size = strlen(name);

	for (uint8_t i = 0; i < size; i++){
		line_1[i] = name[i];
	}

	char str[3];
	sprintf(str, "%3d", value);

	for (uint8_t i = 13; i < 16; i++) {
		line_1[i] = str[i - 13];
	}

	uint8_t vol_size = volume_size(value);

	for(uint8_t i = 0; i < vol_size; i++) {
		line_2[i] = '#';
	}

	write_first_line(line_1, 0);
	write_second_line(line_2, 0);
}

uint8_t volume_size(uint8_t value) {
	switch(value) {
		case 0:
			return 1;
			break;
		case 1:
			return 2;
			break;
		case 2:
			return 3;
			break;
		case 4:
			return 4;
			break;
		case 6:
			return 5;
			break;
		case 8:
			return 6;
			break;
		case 12:
			return 7;
			break;
		case 16:
			return 8;
			break;
		case 24:
			return 9;
			break;
		case 32:
			return 10;
			break;
		case 48:
			return 11;
			break;
		case 64:
			return 12;
			break;
		case 96:
			return 13;
			break;
		case 128:
			return 14;
			break;
		case 192:
			return 15;
			break;
		case 255:
			return 16;
			break;
	}
}

void write_menu_items(char item_1[], char item_2[]) {
	char line_1[17] = {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 0};
	char line_2[17] = {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 0};
	uint8_t size_1 = strlen(item_1);
	uint8_t size_2 = strlen(item_2);

	for (uint8_t i = 0; i < size_1; i++){
		line_1[i] = item_1[i];
	}

	for (uint8_t i = 0; i < size_2; i++){
		line_2[i] = item_2[i];
	}

	write_first_line(line_1, 1);
	write_second_line(line_2, 1);
}
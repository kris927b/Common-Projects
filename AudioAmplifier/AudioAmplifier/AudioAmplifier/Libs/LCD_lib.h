

#ifndef LCD_LIB_H_
#define LCD_LIB_H_

#include "i2cLib.h"

#define SLA_W 0x7C
#define SLA_R 0x7D

void sendCmd(char data);
void sendData(char data);
void initDisp();
void write_first_line(char *data, uint8_t menu);
void write_second_line(char *data, uint8_t menu);
void write_volume_control(char *name, uint8_t value);
uint8_t volume_size(uint8_t value);
void write_menu_items(char item_1[], char item_2[]);


#endif /* LCD_LIB_H_ */
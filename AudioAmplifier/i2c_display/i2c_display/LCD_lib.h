

#ifndef LCD_LIB_H_
#define LCD_LIB_H_

#include "i2cLib.h"

#define SLA_W 0x7C
#define SLA_R 0x7D

void sendCmd(char data);
void sendData(char data);
void initDisp();


#endif /* LCD_LIB_H_ */
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
    i2cStart();
    i2cWrite(SLA_W);
    i2cWrite(0x00);//cmd
    i2cWrite(0x38);//8 bit bus, 2 line disp mode, normal mode
    i2cWrite(0x00);
    i2cWrite(0x39);//8 bit bus, 2 line disp mode, extended mode
    i2cWrite(0x14);//internal OSC freq
    i2cWrite(0x7F);//contrast setting (Highest)
    i2cWrite(0x50);//set ICON address
    i2cWrite(0x6C);//follower controll
    i2cWrite(0x0C);//display ON
    i2cWrite(0x01);//clear disp;ay
    i2cStop();
}
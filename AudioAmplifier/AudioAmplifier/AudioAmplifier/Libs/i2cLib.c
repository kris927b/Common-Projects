#include "i2cLib.h"

void i2cInit(){
    TWSR &= ~((1 << TWPS0) | (1 << TWPS1)); //prescaler set to 0
    TWBR = 12; //setting the bit rate to 400kHz
    TWCR |= (1 << TWEN); //i2c enable 
}

void i2cStart(){
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN); //setting interrupt pin, generating starting condition and enabling i2c
    while (!(TWCR & (1 << TWINT))); //waiting for the transmission of start condition to end
}

void i2cStop(){
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN); //setting interrupt pin, gen. stopping condition and enabling i2c 
}

void i2cWrite(unsigned char data){
    TWDR = data; //putting data to data register
    TWCR = (1 << TWINT) | (1 << TWEN); //setting interrupt pin and enabling i2c
	while(!(TWCR & (1 << TWINT)));
}


/*
 * AVRmenu.c
 *
 * Created: 4/6/2017 2:58:44 PM
 * Author : Matej Majtan
 */ 

#include <avr/io.h> 
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include "usart_lib.h"

int readButton();
void printMenu();

int currentMenu = 0;
int currentItem = 0;
char *menuItems[5][4]; // number of menu, number of items in menu, string
char *menuTitle[5]; // number of menu, string
char output[150+1];

int main(void)
{
    DDRC &= ~(1 << DDC0) & ~(1 << DDC1); // can be deleted/ transformed to pinMode function dunno how it works
    PCICR |= (1 << PCIE1) | (1 << PCIE0);
    PCMSK1 |= (1 << PCINT8);
    PCMSK0 |= (1 << PCINT7);
    init_usart(9600,NONE,ONE);
    sei();

    // menu titles
    menuTitle[0] = "MAIN MENU";
    menuTitle[1] = "SETTINGS";
    menuTitle[2] = "PROFILE";
    menuTitle[3] = "AUDIO";
    menuTitle[4] = "USERS";
    // items of menu 0 (MAIN)
    menuItems[0][0] = "SETTINGS";
    menuItems[0][1] = "PROFILE";
    menuItems[0][2] = "AUDIO";
    menuItems[0][3] = "USERS";
    // items of menu 1 (SETTINGS)
    menuItems[1][0] = "GENERAL";
    menuItems[1][1] = "DISPLAY";
    menuItems[1][2] = "MODE";
    menuItems[1][3] = "BACK";
    // items of menu 2 (PROFILE)
    menuItems[2][0] = "NAME";
    menuItems[2][1] = "AGE";
    menuItems[2][2] = "ADDRESS";
    menuItems[2][3] = "BACK";
    // items of menu 3 (AUDIO)
    menuItems[3][0] = "VOLUME";
    menuItems[3][1] = "EQUALIZER";
    menuItems[3][2] = "MUTE";
    menuItems[3][3] = "BACK";
    // items of menu 4 (USERS)
    menuItems[4][0] = "CREATE USER";
    menuItems[4][1] = "REMOVE USER";
    menuItems[4][2] = "MODIFY USER";
    menuItems[4][3] = "BACK";
    //printMenu();
    while (1) 
    {
    
    } //while
} //main

void printMenu(){
    char *green = "\x1B[32m";
    char *white = "\x1B[37;1m";
    usart_transmit_string("\x1B[2J\x1B[H"); // clear console
    sprintf(output, "%s%s\n\r%s%c %s\n\r%s%c %s\n\r%s%c %s\n\r%s%c %s", "\x1B[31;1m", menuTitle[currentMenu],
    currentItem == 0 ? green : white, currentItem == 0 ? '>' : ' ', menuItems[currentMenu][0],
    currentItem == 1 ? green : white, currentItem == 1 ? '>' : ' ', menuItems[currentMenu][1],
    currentItem == 2 ? green : white, currentItem == 2 ? '>' : ' ', menuItems[currentMenu][2],
    currentItem == 3 ? green : white, currentItem == 3 ? '>' : ' ', menuItems[currentMenu][3]);
    usart_transmit_string(output);
}


ISR(PCINT1_vect)
{
    if((PINC & (1 << PINC0)) == 0){
        if (PINC & (1 << PINC1)){ //CW up
            if (currentItem == 0) {
                currentItem = 3;
                } else {
                currentItem--;
            }
        } else { //CCW down
            if (currentItem == 3) {
                currentItem = 0;
                } else {
                currentItem++;
            }
        }
        printMenu();
    }
}

ISR(PCINT0_vect){
    if ((PINB & (1 << PINB7)) == 0){
        switch (currentMenu) {
            case 0: // main menu
            switch (currentItem) {
                case 0: // settings
                currentMenu = 1; currentItem = 0; break;
                case 1: // profile
                currentMenu = 2; currentItem = 0; break;
                case 2: // audio
                currentMenu = 3; currentItem = 0; break;
                case 3: // users
                currentMenu = 4; currentItem = 0; break;
            }
            break;
            case 1: // settings menu
            switch (currentItem) {
                case 0: // general
                currentItem = 0; break;
                case 1: // display
                currentItem = 0; break;
                case 2: // mode
                currentItem = 0; break;
                case 3: // back
                currentMenu = 0; currentItem = 0; break;
            }
            break;
            case 2: // profile menu
            switch (currentItem) {
                case 0: // name
                currentItem = 0; break;
                case 1: // age
                currentItem = 0; break;
                case 2: // address
                currentItem = 0; break;
                case 3: // back
                currentMenu = 0; currentItem = 0; break;
            }
            break;
            case 3: // audio menu
            switch (currentItem) {
                case 0: // volume
                currentItem = 0; break;
                case 1: // equalizer
                currentItem = 0; break;
                case 2: // mute
                currentItem = 0; break;
                case 3: // back
                currentMenu = 0; currentItem = 0; break;
            }
            break;
            case 4: // users menu
            switch (currentItem) {
                case 0: // create user
                currentItem = 0; break;
                case 1: // remove user
                currentItem = 0; break;
                case 2: // modify user
                currentItem = 0; break;
                case 3: // back
                currentMenu = 0; currentItem = 0; break;
            }
            break;
        }
        printMenu();
    }
}
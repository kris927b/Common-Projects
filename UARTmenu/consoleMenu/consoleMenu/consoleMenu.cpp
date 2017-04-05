// consoleMenu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h> // strlen()
#include <stdlib.h> // system("cls")
#include <conio.h> // _getch()

void putIntoStr(char *str, char *input);
int readButton();

int main()
{
    char *menuItems[5][4]; // number of menu, number of items in menu, string  
    char *menuTitle[5]; // number of menu, string
    int currentMenu = 0;
    int currentItem = 0;
    char output[80+1];

    // memu titles
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

    while (1) {
        system("cls");
        sprintf_s(output, "%s\n%c %s\n%c %s\n%c %s\n%c %s",menuTitle[currentMenu], 
                                                currentItem == 0 ? '>' : ' ', menuItems[currentMenu][0],
                                                currentItem == 1 ? '>' : ' ', menuItems[currentMenu][1],
                                                currentItem == 2 ? '>' : ' ', menuItems[currentMenu][2], 
                                                currentItem == 3 ? '>' : ' ', menuItems[currentMenu][3]);
        puts(output);
        int button = readButton();
        if (button == 1) { // up
            if (currentItem == 0) {
                currentItem = 3;
            } else {
                currentItem--;
            }
        } else if (button == 2) { // down
            if (currentItem == 3) {
                currentItem = 0;
            }
            else {
                currentItem++;
            }
        } else if (button == 3) { // select
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
        }
    }
    return 0;
}

void putIntoStr(char *str, char *input) {
    int lenght = strlen(input);
    for (int i = 0; i < lenght; i++) {
        str[i] = input[i];
    }
    str[lenght + 1] = '\0';
}

int readButton(){
    char key = _getch();
    printf("%c", key);
    if (key == 'w') { return 1; }
    else if (key == 's') { return 2; }
    else if (key == ' ') { return 3; }
    else return 0;
}

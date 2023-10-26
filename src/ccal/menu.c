//
// Created by Serhii Berehovyi on 26.10.23.
//

#include <stdio.h>
#include "../../includes/tools/escapesequenzen.h"
#include "../../includes/ccal/menu.h"
#include "../../includes/tools/tools.h"

int getMenu(char* menuTitle, char* menuItems[], int menuItemsCount) {
    char input;

    clearScreen();
    printf("\n%s\n", menuTitle);
    printLine('=', getStringLength(menuTitle));
    printf("\n");

    for(int i = 0; i < menuItemsCount; i++) {
        printf("%i. %s\n", i+1, menuItems[i]);
    }

    printf("\n");

    SAVE_POSITION;
    do {
        RESTORE_POSITION;
        CLEAR_LINE;
        printf("Ihre Wahl: ");
        scanf("%c", &input);
        if(input != '\n')
            clearBuffer();
    } while (input <= '0' || input > '0' + menuItemsCount);

    return input;
}
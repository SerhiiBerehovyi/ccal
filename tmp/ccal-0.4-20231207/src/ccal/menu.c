//
// Created by Anselm Nehls on 27.10.23.
//

#include <stdio.h>
#include <string.h>
#include "../../includes/ccal/datastructure.h"
#include "../../includes/ccal/menu.h"
#include "../../includes/tools/tools.h"


int getMenu(char title[MENUITEM_MAXLENGTH], char* menuItems[MENUITEM_MAXNUM], int numMenuItems)
{
    int menuChoice = 0;
    int valid = 0;

    do {
        clearScreen();
        printf("%s\n", title);
        printLine('=', (int) strlen(title));

        int i;
        for (i = 1; i <= numMenuItems; i++)
        {
            printf("%i. %s\n", i, menuItems[i]);
        }

        printf("\nIhre Wahl: ");
        int scanf_ok = scanf("%i", &menuChoice);
        clearBuffer();

        printf("\n");

        if (scanf_ok && (menuChoice > 0 && menuChoice <= numMenuItems))
        {
            valid = 1;
        }

    } while (!valid);

    return menuChoice;
}
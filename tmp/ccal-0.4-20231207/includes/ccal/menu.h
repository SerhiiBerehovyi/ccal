//
// Created by Anselm Nehls on 27.10.23.
//


#ifndef CCAL_MENU_H
#define CCAL_MENU_H


/*************************************************************************************
* Funktion:         getMenu
*
* Beschreibung:     Gibt ein Menü auf dem Bildschirm aus
*
* Parameter:        char title[]            Menütitel als Array von Zeichen
*                   char* menuItems[]       Auswahloptionen als Array von Zeichenketten
*                   int numMenuItems        Anzahl der Menüoptionen
*
* Ergebnis:         Index der ausgewählten Option
*
*************************************************************************************/
int getMenu(char[], char*[], int);


#endif // CCAL_MENU_H

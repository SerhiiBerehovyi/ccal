//
// Created by Serhii Berehovyi on 26.10.23.
//

#ifndef CCAL_MENU_H
#define CCAL_MENU_H

/******************************************************************************
 * Die Funktion loescht den Bildschirm und gibt erst char* menuTitle
 * auf die Liste aus int menuItemsCount Elementen. Jedes Element ist
 * ein Element aus char** menuItems.
 * Danach wird leere Zeile ausgegeben und die Eingabe Aufforderung
 *
 * Die Funktion wird erst nach der Eingabe gueltiges Menupunktes verlassen.
 *
 * Inputs: char* menuTitle : die Name des Menus.
 *         char** menuItems : die Liste von Menuelementen, die ausgegeben
 *                            werden muessen.
 *         int menuItemsCount : die Anzahl von Elementen in menuItems-Array.
 *
 * Ausgabe: die von User ausgewaehlte Menuelement.
 * ***************************************************************************/
int getMenu(char* menuTitle, char* menuItems[], int menuItemsCount);

#endif //CCAL_MENU_H

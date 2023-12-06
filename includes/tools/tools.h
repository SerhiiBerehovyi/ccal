//
// Created by Serhii Berehovyi on 20.10.23.
//

#ifndef TOOLS_H
#define TOOLS_H


#include <stdio.h>


/*************************************************************************************
* Funktion:         clearScreen
* Beschreibung:     Löscht den Bildschirm
*
* Parameter:        -
* Ergebnis:         -
*************************************************************************************/
void clearScreen();


/*************************************************************************************
* Funktion:         clearBuffer
* Beschreibung:     Leert den Eingabebuffer
*
* Parameter:        -
* Ergebnis:         -
*************************************************************************************/
void clearBuffer();


/*************************************************************************************
* Funktion:         fclearBuffer
* Beschreibung:     Leert den buffer der übergebenen Datei
*
* Parameter:        FILE*       Zeiger auf Datei
* Ergebnis:         -
*************************************************************************************/
void fclearBuffer(FILE*);


/*************************************************************************************
* Funktion:         waitForEnter
* Beschreibung:     Wartet bis der Benutzer Enter drückt
*
* Parameter:        -
* Ergebnis:         -
*************************************************************************************/
void waitForEnter();


/*************************************************************************************
* Funktion:         askYesOrNo
* Beschreibung:     Gibt die übergebene Eingabeaufforderung aus bis der Benutzer
*                   mit J oder N geantwortet hat
*
* Parameter:        char *Question      Eingabeaufforderung als Zeichenkette
*
* Ergebnis:         int                 0 - nein
*                                       1 - ja
*************************************************************************************/
int askYesOrNo(char *Question);

int getStringLength(char *str);


/*************************************************************************************
* Funktion:         printLine
* Beschreibung:     Gibt eine vertikale Linie auf dem Bildschirm aus
*
* Parameter:        pencil      Zeichen mit dem gezeichnet werden soll
*                   count       Wie häufig das Zeichen ausgegeben werden soll
* Ergebnis:         -
*************************************************************************************/
void printLine(char pencil, int count);


/*************************************************************************************
* Funktion:         cut_ctrlchars
* Beschreibung:     Entfernt ASCII-Steuerzeichen vom Ende der übergebenen Zeichenkette
*
* Parameter:        char *lp        Zeiger auf Zeichenkette
* Ergebnis:         -
*************************************************************************************/
void cut_ctrlchars(char *lp);


/*************************************************************************************
* Funktion:         getText
* Beschreibung:     Fordert den Benutzer auf, einen Text einzugeben
*
* Parameter:        char *prompt        Zeiger auf Eingabeaufforderung
*                   int len_max         Maximale Länge des Textes
*                   int required        Pflichtfeld?  1 - ja / 0 - nein
* Ergebnis:         -
*************************************************************************************/
int getText(char *prompt, int len_max, char** text, int required);


#endif //TOOLS_H

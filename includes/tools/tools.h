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


/*************************************************************************************
* Funktion:         to_lowercase
* Beschreibung:     Konvertiert alle Großbuchstaben in einem per Zeiger übergebenen
*                   String in Kleinbuchstaben, ohne den ursprünglichen String zu verändern.
*                   Es wird ein neuer, modifizierter String zurückgegeben.
*                   Bei einem übergebenen NULL-Zeiger oder leerem String gibt die Funktion
*                   NULL zurück.
*
*                   Die Funktion alloziiert dynamischen Speicher für den zurückgegebenen
*                   String. Der aufrufende Code muss diesen später wieder freigeben!
*
* Parameter:        char *text     Zeiger auf den zu konvertierenden Text
* Ergebnis:         char *         Zeiger auf den neuen, nur aus Kleinbuchstaben bestehenden String
*                                  oder NULL bei Fehlern oder wenn der Eingabetext NULL ist
*************************************************************************************/
char *to_lowercase(char *);


/*************************************************************************************
* Funktion:         askForNumber
* Beschreibung:     Gibt die übergebene Eingabeaufforderung aus bis der Benutzer
 *                  eine Zahl eingibt.
*
*
* Parameter:        char *prompt        Eingabeaufforderung als Zeichenkette
*
* Ergebnis:         int                 die von User eingegebene Zahl
*************************************************************************************/
int askForNumber(char *prompt);
#endif //TOOLS_H

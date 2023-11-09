//
// Created by Serhii Berehovyi on 20.10.23.
//

#ifndef UEB01_TOOLS_H
#define UEB01_TOOLS_H

#include "../ccal/datastructure.h"


/******************************************************************************
 * Die Funktion loescht den Eingabepuffer.
 * Alle eingegebene Zeichen bis '\n' werden geloescht.
 * ***************************************************************************/
void clearBuffer();

/******************************************************************************
 * Die Funktion fragt den User nach Eingabetastedruecken und wartet, bis
 * sie gedrueckt wird.
 * ***************************************************************************/
void waitForEnter();

/******************************************************************************
 * Die Funktion fragt den User nach Eingabe von 'j' bzw. 'J' oder nach
 * 'n' bzw. 'N' sobald die valiede Eingabe eingegeben wird.
 *
 * input: char* Question:   ein Zeiger auf eine Zeichenkette - Einladung
 *                          fuer den User, die vor input-Aufforderung
 *                          ausgegeben wird.
 *
 * output:  1, wenn 'j' bzw. 'J' von User eingegeben wurde
 *          0, wenn 'n' bzw. 'N'
 * ***************************************************************************/
int askYesOrNo(char *Question);

/******************************************************************************
 * Die Funktion gibt Zeichen ch num mal und '\n' danach.
 * z.B printLine('=', 10) gitb Zeichen '=' 10 mal auf den Bildschirm
 * und '\n' danach. "==========\n"
 *
 * inputs:  char ch:    Zeichen, der die Zeile bilden muss.
 *          int num:    die Laenge von der Zeile.
 * ***************************************************************************/
void printLine(char ch, int num);

/******************************************************************************
 * Die Funktion zaehlt die Zeichen in einer String und gibt die Laenge dieser
 * String zurueck.
 *
 * input:   const char* str:    ein Zeiger auf Zeichenkette, deren Laenge
 *                              gezaehlt werden muss.
 *
 * output:  (int) die Anzaehl der Zeichen in gegebenen Zeichenkaette.
 * ***************************************************************************/
int getStringLength(const char *str);

/******************************************************************************
 * Die Funktion fragt den User nach Eingabe von Text einer maximalen Laenge.
 * Fuer den eingegebenen Text wird genau so viel Speicher wie noetig reserviert.
 * Falls Laenge der Text groesser als maxLength ist, werden nur erste maxLength
 * Zeichen gespeichert.
 *
 * input:   char* prompt:   ein Zeiger auf Zeichenkette - Einladung zur Eingabe
 *                          fuer User, die vor Eingabe auf den Bildschirm
 *                          ausgegeben werden muss.
 *          int maxLength:  die maximale moegliche Laenge der Eingabe.
 *          char** destination: ein Zeiger auf ein Zeiger auf Speicherzelle,
 *                              wo der Text gespeichert werden muss.
 *                              Fall keine Eingabe passiert, wird *dersination
 *                              auf NULL gesetzt.
 *          int blank:      ist die leere Eingabe erlaubt?
 *                          0, falls nicht,
 *                          1, falls ja.
 *
 * output:  1 nach der erfolgreichen Eingabe,
 *          0, falls destination == NULL, maxLength <= 0 oder falls ein
 *          Fehler bei malloc() vorgekommen ist.
 * ***************************************************************************/
int getText(char* prompt, int maxLength, char** destination, int blank);

/******************************************************************************
 * Die Funktion gibt ein Text bestimmter Laenger auf den Bildschirm aus.
 * Falls der Text laenger als maxLength ist, werden nur erste
 * maxLength-4 ausgegeben und " ..." dazugeschrieben.
 *
 * input:   char* str:  ein Zeiger auf eine Zeichenkette, die ausgegeben muss
 *          int maxLength:  die maximale Laenge der Ausgabe.
 * ***************************************************************************/
void printWithEllipsis(char* str, int maxLength);

#endif //UEB01_TOOLS_H
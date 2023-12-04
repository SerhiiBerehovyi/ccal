//
// Created by Serhii Berehovyi on 20.10.23.
//

#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>

void clearScreen();

void clearBuffer();

void fclearBuffer(FILE*);

void waitForEnter();

int askYesOrNo(char *Question);

int getStringLength(char *str);

void printLine(char pencil, int count);


/**********************************************************
 * Funktion:    getText
 * Parameter:
 * Rückgabe:    1 = Text erfolgreich eingelesen
 *              0 = Fehler
 **********************************************************/
int getText(char* prompt, int len_max, char** text, int required);

#endif //TOOLS_H

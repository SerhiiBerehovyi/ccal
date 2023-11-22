//
// Created by Serhii Berehovyi on 20.10.23.
//

#ifndef UEB01_TOOLS_H
#define UEB01_TOOLS_H

void clearScreen();

void clearBuffer();

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

#endif //UEB01_TOOLS_H

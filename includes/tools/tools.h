//
// Created by Serhii Berehovyi on 20.10.23.
//

#ifndef UEB01_TOOLS_H
#define UEB01_TOOLS_H

void clearScreen();

void clearBuffer();

void waitForEnter();

int askYesOrNo(char *Question);

void printLine(char ch, int num);

int getStringLength(char *str);

int getText(char* prompt, int maxLength, char** destination, int blank);

#endif //UEB01_TOOLS_H

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

int printLine(char pencil, int count);

#endif //UEB01_TOOLS_H

//
// Created by Serhii Berehovyi on 20.10.23.
//


#include "../../includes/tools/tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes/tools/escapesequenzen.h"

/**********************************************************
 *
 **********************************************************/
void clearScreen()
{
    system("clear"); // Linux / angebissenes Obst
    // system("CLS");   // Windows
}

/**********************************************************
 *
 **********************************************************/
void clearBuffer()
{
    char Dummy;

    do
    {
        scanf("%c", &Dummy);
    } while (Dummy != '\n');
}

/**********************************************************
 *
 **********************************************************/
void waitForEnter()
{
    printf("\nBitte Eingabetaste druecken ...");
    clearBuffer();
}

/**********************************************************
 *
 **********************************************************/
int askYesOrNo(char *Question)
{
    char Input;

    do
    {
        printf("%s", Question);
        scanf("%c", &Input);
        if (Input != '\n')
            clearBuffer();
    } while ((Input != 'j') && (Input != 'J') && (Input != 'n') && (Input != 'N'));
    return ((Input == 'j') || (Input == 'J'));
}


void printLine(char ch, int len){
    for(int i = 0; i < len; i++)
        printf("%c", ch);
    printf("\n");
}

int getStringLength(char* str){
    int count = 0;
    while(*str) {
        count += 1;
        str += 1;
    }

    return count;
}

int getText(char* prompt, int maxLength, char** destination, int allowEmpty){
     int scanned;
     int len;
     int result = 0;
     char *input = NULL;
     char format[15];

     if(destination == NULL)
         return 0;

     if(maxLength <= 0)
         return 0;

     input =  malloc(maxLength * sizeof(char) );
     if(input == NULL)
         return 0;

     *destination = NULL;
     sprintf(format, "%%%ds", maxLength);

     SAVE_POSITION;
     do {
         RESTORE_POSITION;
         CLEAR_BELOW;
         printf("%s ", prompt);

         scanned = scanf(format, input);
         printf("%s\n", input);
         clearBuffer();

         if(scanned){
             len = (int) strlen(input);
             if(len > 0) {
                 *destination = calloc(len + 1, sizeof(char));
                 if(*destination){
                     strcpy(*destination, input);
                     result = 1;
                 }
             } else {
                 if(allowEmpty)
                     result = 1;
                 else
                     scanned = 0;
             }
         } else {
             if(allowEmpty) {
                 result = 1;
                 scanned = 1;
             }
         }
     } while(!scanned);

     free(input);
     return result;
}


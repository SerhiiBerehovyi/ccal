//
// Created by Serhii Berehovyi on 20.10.23.
//


#include "../../includes/tools/tools.h"
#include "../../includes/ccal/datastructure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void printLine(char pencil, int count) {
    int i;

    for (i = 0; i < count; i++)
    {
        printf("%c", pencil);
    }

    printf("\n");
}

int getText(char* prompt, int len_max, char** text, int required)
{
    // TODO: print maxlen/required in prompt

    // check parameters
    if (len_max <= 0 || text == NULL) { errorCode = 1; return 0; } // TODO split errors

    // declarations
    char* input = NULL;
    int scanf_ok = 0;
    int result = 0;
    unsigned int len_input = 0;

    // allocate memory for input text
    input = malloc(sizeof(char) * (len_max + 1)); // sizeof eigtl. unnötig, weil char = 1 byte
    if (input == NULL) { errorCode = 1; return 0; }

    // get text
    do {
        printf("%s", prompt);
        scanf_ok = scanf("%s[^\n]", input);
        clearBuffer();

        if (scanf_ok)
        {
            len_input = strlen(input);

            if (len_input > 0)
            {
                *text = malloc(sizeof(char) * (len_input + 1)); // * -> text_ptr selbst, nicht ptr auf text_ptr
                if (text == NULL) { errorCode = 1; return 0; }

                strcpy(*text, input);
                result = 1;
            }
            else if (len_input == 0 && !required)
            {
                result = 1;
            }
            else
            {
                printf("Text darf nicht leer sein.\n");
                scanf_ok = 0;
            }
        }
    } while (!scanf_ok);

    // housekeeping
    free(input);
    return result;
}
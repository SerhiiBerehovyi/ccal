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

void fclearBuffer(FILE *fp)
{
    char tmp;
    do
    {
        fscanf(fp, "%c", &tmp);
    } while (tmp != '\n' && !feof(fp));
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
    if (len_max <= 0 || text == NULL) { errorCode = 1; return 0; } // TODO-opt error handling

    char* input = NULL;
    int scanf_ok = 0;
    int result = 0;
    unsigned int len_input = 0;

    char scanf_format[15] = {0};
    sprintf(scanf_format, "%%%i[^\n]", len_max);

    input = malloc(sizeof(char) * (len_max + 1)); // sizeof eigtl. unnötig, weil char = 1 byte
    if (input == NULL) { errorCode = 1; return 0; }

    do {
        printf("%s", prompt);
        scanf_ok = scanf(scanf_format, input);
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
            else
            {
                if (!required)
                {
                    result = 1;
                }
                else
                {
                    printf("Text darf nicht leer sein.\n"); waitForEnter();
                    scanf_ok = 0;
                }
            }
        }
        else
        {
            if (!required)
            {
                result = 1;
                scanf_ok = 1;
            }
        }
    } while (!scanf_ok);

    free(input);
    return result;
}
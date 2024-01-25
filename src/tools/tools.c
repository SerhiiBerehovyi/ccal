//
// Created by Serhii Berehovyi on 20.10.23.
//


#include "../../includes/tools/tools.h"
#include "../../includes/ccal/datastructure.h"
#include "../../includes/tools/escapesequenzen.h"
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
    printf("\nBitte Eingabetaste druecken. ");
    clearBuffer();
}

int askForNumber(char *prompt) {
    int number, scanned;

    SAVE_POSITION;
    do{
        RESTORE_POSITION;
        CLEAR_BELOW;
        printf("%s", prompt);
        scanned = scanf("%d", &number);
        clearBuffer();
    } while(!scanned);

    return number;
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
    if (len_max <= 0 || text == NULL)
    {
        errorCode = 4;
        return 0;
    }

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


void cut_ctrlchars(char* lp)
{
    while (*lp != '\0')
    {
        if (*lp < 0x20)
        {
            *lp = '\0';
        }
        lp++;
    }
}


char *to_lowercase(char *text)
{
    if (text == NULL)
    {
        return NULL;
    }

    char *lower_text = malloc(strlen(text) + 1);
    if (lower_text == NULL)
    {
        return NULL;
    }

    char *tp         = lower_text;

    while (*text)
    {
        if (*text > 'A' && *text <= 'Z')
        {
            *lower_text = *text + 32;
        }
        else
        {
            *lower_text = *text;
        }
        text++;
        lower_text++;
    }
    *lower_text      = '\0';
    return tp;
}

void printWithEllipsis(char* str, int maxLength){
    if(strlen(str) > maxLength){
        char format[20];
        sprintf(format, "%%.%ds ...", maxLength - 4); // space + ... = 4
        printf(format, str);
    } else {
        printf("%s", str);
    }
}
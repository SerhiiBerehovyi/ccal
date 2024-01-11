//
// Created by Anselm Nehls on 27.10.23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes/tools/tools.h"
#include "../../includes/tools/escapesequenzen.h"
#include "../../includes/ccal/datastructure.h"
#include "../../includes/ccal/database.h"
#include "../../includes/ccal/datetime.h"
#include "../../includes/ccal/sort.h"
#include "../../includes/ccal/calendar.h"
#include "../../includes/ccal/list.h"


int errorCode = 0;
int countAppointments = 0;
sAppointment *First = NULL;
sAppointment *Last = NULL;

void createAppointment(void)
{
    sAppointment *newAppointment = malloc(sizeof(sAppointment));
    if (!newAppointment)
        { return; }

    sTime*  pStartTime  = &newAppointment->StartTime;
    sTime*  pDuration   = NULL;

    HOME; CLEAR;
    printf("Neuen Termin erstellen\n\n");

    if (!getDate("Datum        : ", &newAppointment->Date))
        { return; } CLEAR_BELOW;
    if (!getTime("Beginn       : ", &pStartTime, 1))
        { return; } CLEAR_BELOW;
    if (!getText("Beschreibung : ", DESCRIPTION_MAXLEN, &newAppointment->Description, 1))
        { return; } CLEAR_BELOW;
    if (!getText("Ort   (opt.) : ", LOCATION_MAXLEN, &newAppointment->Location, 0))
        { return; } CLEAR_BELOW;
    if (!getTime("Dauer (opt.) : ", &pDuration, 0))
        { return; } CLEAR_BELOW;

    newAppointment->Duration = pDuration;
    countAppointments++;
    insertInDList(newAppointment);

    printf("\nTermin erfolgreich erstellt.\n");
    waitForEnter();
}


void editAppointment(void)
{
    printf("TODO: Termin bearbeiten\n");
    waitForEnter();
}


void deleteAppointment(void)
{
    HOME;
    CLEAR;
    printf("Terminliste\n");
    printLine('-', strlen("Terminliste"));

    if(!countAppointments)
    {
        printf("\n%s\n", "Sie haben keine Termine im Kalender.");
        waitForEnter();
        return;
    }

    int i = 0;
    sAppointment *tmp = First;
    while(tmp)
    {
        i++;
        printf("%i: ", i);
        printDate(&tmp->Date);
        printf(", ");
        printTime(&tmp->StartTime);
        printf(": %s\n", tmp->Description);

        tmp = tmp->Next;
    }

    int answer;
    SAVE_POSITION;
    do
    {
        RESTORE_POSITION;
        CLEAR_BELOW;
        answer = askForNumber("Welchen Termin moechten Sie loeschen (0 fuer Abbrechen) ? ");
    } while(answer < 0 || answer > countAppointments);

    if(!answer)
        return;

    i = 1;
    tmp = First;
    while(i < answer)
    {
        i++;
        tmp = tmp->Next;
    }

    removeFromDList(tmp);
    countAppointments--;
    printf("\n%s\n", "Der Termin wurde erfolgreich geloescht.");
    waitForEnter();
}


void searchAppointment(void)
{
    printf("TODO: Termin suchen\n");
    waitForEnter();
}


/******************************************************************
 * Das Sortieren entfaellt komplett, da die Termine in die verkaetette
 * Liste schon sortiert eingefeugt werden.
 ******************************************************************/


/*
void sortCalendar(void)
{
    char menuTitle[50] = "Termine sortieren";

    while (1)
    {
        char *menuItems[MENUITEM_MAXNUM];
        menuItems[1] = "Sortieren nach Datum und Uhrzeit";
        menuItems[2] = "Sortieren nach Beschreibung";
        menuItems[3] = "Sortieren nach Ort";
        menuItems[4] = "Sortieren nach Dauer";
        menuItems[5] = "Zurueck zum Hauptmenue";

        int menuChoice = getMenu(menuTitle, menuItems, 5);

        clearScreen();

        switch (menuChoice)
        {
            case 1:
                sort_appointments(&Calendar[0], countAppointments, compare_by_date_and_time);
                waitForEnter();
                listCalendar();
                return;
            case 2:
                sort_appointments(&Calendar[0], countAppointments, compare_by_description);
                waitForEnter();
                listCalendar();
                return;
            case 3:
                sort_appointments(&Calendar[0], countAppointments, compare_by_location);
                if (errorCode != 66)
                {
                    waitForEnter();
                    listCalendar();
                }
                return;
            case 4:
                sort_appointments(&Calendar[0], countAppointments, compare_by_duration);
                waitForEnter();
                listCalendar();
                return;
            default:
                return;
        }
    }

}
 */


void printAppointment(sAppointment* appointment, int print_date)
{
    char printf_format[100] = { 0 };

    if (print_date)
    {
        printf("\n");
        printLine('=', 14);
        printDate(&appointment->Date);
        printf("\n");
        printLine(' ', 14);
    }
    printf(" ");
    printTime(&appointment->StartTime);

    if (appointment->Duration)
    {
        printf(" - ");
        sTime endTime = addTime(&appointment->StartTime, appointment->Duration);
        printTime(&endTime);
    }
    else
    {
        printf("        ");
    }

    if (appointment->Location)
    {
        sprintf(printf_format, " -> %%-%i.%is ~ ", LOCATION_MAXLEN, LOCATION_MAXLEN);
        printf(printf_format, appointment->Location);
    }
    else
    {
        int i;
        for (i = -4; i < LOCATION_MAXLEN; i++)
        {
            printf(" ");
        }
        printf(" ~ ");
    }

    if (strlen(appointment->Description) <= 48)
    {
        printf("%s\n", appointment->Description);
    }
    else
    {
       printf("%.44s ...\n", appointment->Description);
    }
}


void listCalendar(void)
{
    int i = 0;
    int waiting, print_date;
    sDate *printed_date = NULL;

    if (countAppointments > 0)
    {
        HOME; CLEAR;
        printf("Liste aller Termine\n");
        printLine('=', 19);

        sAppointment *tmp = First;
        while(tmp)
        {
            STORE_POS;

            waiting = 0;
            print_date = 0;

            if ( printed_date == NULL
                    || tmp->Date.Day != printed_date->Day
                    || tmp->Date.Month != printed_date->Month
                    || tmp->Date.Year != printed_date->Year)
            {
                print_date = 1;
            }

            printAppointment(tmp, print_date);

            printed_date = &tmp->Date;

            if ((i != 0) && ((i + 1) % LISTITEM_BREAK == 0))
            {
                waiting = 1;
                waitForEnter();
                RESTORE_POS; CLEAR_BELOW;
            }
            i++;
            tmp = tmp->Next;
        }
        if (!waiting)
        {
            waitForEnter();
        }
    }
    else
    {
        printf("Keine Termine im Kalender.\n");
        waitForEnter();
    }
}


void freeAppointments()
{
    int i;
    while(First)
    {
        sAppointment *tmp = First->Next;

        if (First->Description != NULL)
        {
            free(First->Description);
            First->Description = NULL;
        }
        if (First->Location != NULL)
        {
            free(First->Location);
            First->Location = NULL;
        }
        if (First->Duration != NULL)
        {
            free(First->Duration);
            First->Duration = NULL;
        }

        free(First);
        First = tmp;
    }
}


void closeCalendar()
{
    if (countAppointments > 0)
    {
        if (askYesOrNo("Moechten Sie den Kalender speichern? (j/n) "))
        {
            if (saveCalendar())
            {
                printf("\nKalender erfolgreich gespeichert.\n");
            }
            else
            {
                printf("\nKalender konnte nicht gespeichert werden. Bitte nicht an den Support wenden.\n");
            }
            waitForEnter();
        }
        freeAppointments();
    }
    clearScreen();
}


int compare_by_description(sAppointment *first, sAppointment *second)
{
    char *description[2] = { 0 };

    description[0] = to_lowercase(first->Description);
    description[1] = to_lowercase(second->Description);
    int result = strcmp(description[0], description[1]);

    int i;
    for (i = 0; i < 2; i++)
    {
        free(description[i]);
    }

    return result;
}


int compare_by_location(sAppointment *first, sAppointment *second)
{
    sAppointment appointments[2];
    appointments[0] = *first;
    appointments[1] = *second;

    char *location[2] = { 0 };

    int i;
    for (i = 0; i < 2; i++)
    {
        if (appointments[i].Location == NULL)
        {
            if ((location[i] = malloc(1)))
            {
                *location[i] = '\0';
            }
            else
            {
                errorCode = 66; // TODO - enumerate errorCodes
                return 0;
            }
        }
        else
        {
            location[i] = to_lowercase(appointments[i].Location);
        }
    }

    int result = strcmp(location[0], location[1]);

    for (i = 0; i < 2; i++)
    {
        free(location[i]);
    }

    return result;
}


int compare_by_duration(sAppointment *first, sAppointment *second)
{
    sAppointment appointments[2];
    appointments[0] = *first;
    appointments[1] = *second;

    sTime duration[2];

    int i;
    for (i = 0; i < 2; i++)
    {
        if (appointments[i].Duration == NULL)
        {
            duration[i].Hour   = 0;
            duration[i].Minute = 0;
        }
        else
        {
            duration[i] = *appointments[i].Duration;
        }
    }

    if (duration[0].Hour > duration[1].Hour)
    {
        return 1;
    }
    else if (duration[0].Hour < duration[1].Hour)
    {
        return -1;
    }
    else
    {
        if (duration[0].Minute > duration[1].Minute)
        {
            return 1;
        }
        else if (duration[0].Minute < duration[1].Minute)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}


int compare_by_date_and_time(sAppointment *first, sAppointment *second)
{
    if (first->Date.Year > second->Date.Year) return 1;
    if (first->Date.Year < second->Date.Year) return -1;
    if (first->Date.Month > second->Date.Month) return 1;
    if (first->Date.Month < second->Date.Month) return -1;
    if (first->Date.Day > second->Date.Day) return 1;
    if (first->Date.Day < second->Date.Day) return -1;

    if (first->StartTime.Hour > second->StartTime.Hour) return 1;
    if (first->StartTime.Hour < second->StartTime.Hour) return -1;
    if (first->StartTime.Minute > second->StartTime.Minute) return 1;
    if (first->StartTime.Minute < second->StartTime.Minute) return -1;

    return 0;
}


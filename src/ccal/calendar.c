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
#include "../../includes/ccal/menu.h"
#include "../../includes/ccal/sort.h"


int errorCode = 0;
int countAppointments = 0;
sAppointment Calendar[MAXAPPOINTMENTS];


void createAppointment(void)
{
    if (countAppointments < MAXAPPOINTMENTS)
    {
        sTime*  pStartTime  = &Calendar[countAppointments].StartTime;
        sTime*  pDuration   = NULL;

        HOME; CLEAR;
        printf("Neuen Termin erstellen\n\n");

        if (!getDate("Datum        : ", &Calendar[countAppointments].Date))
            { return; } CLEAR_BELOW;
        if (!getTime("Beginn       : ", &pStartTime, 1))
            { return; } CLEAR_BELOW;
        if (!getText("Beschreibung : ", DESCRIPTION_MAXLEN, &Calendar[countAppointments].Description, 1))
            { return; } CLEAR_BELOW;
        if (!getText("Ort   (opt.) : ", LOCATION_MAXLEN, &Calendar[countAppointments].Location, 0))
            { return; } CLEAR_BELOW;
        if (!getTime("Dauer (opt.) : ", &pDuration, 0))
            { return; } CLEAR_BELOW;

        Calendar[countAppointments].Duration = pDuration;
        countAppointments++;

        printf("\nTermin erfolgreich erstellt.\n");
        waitForEnter();
    }
    else
    {
        printf("Der Kalender ist voll.\n");
        waitForEnter();
    }
}


void editAppointment(void)
{
    printf("TODO: Termin bearbeiten\n");
    waitForEnter();
}


void deleteAppointment(void)
{
    printf("TODO: Termin loeschen\n");
    waitForEnter();
}


void searchAppointment(void)
{
    printf("TODO: Termin suchen\n");
    waitForEnter();
}


int compare_by_description(sAppointment *first_appt, sAppointment *second_appt) // TODO
{
    return 0;
}


int compare_location(sAppointment *first_appt, sAppointment *second_appt) // TODO
{
    return 0;
}


int compare_duration(sAppointment *first_appt, sAppointment *second_appt) // TODO
{
    return 0;
}


int compare_by_date_and_time(sAppointment *first, sAppointment *second)
{
    if (first->Date.Year > second->Date.Year)
    {
        return 1;
    }
    else if (first->Date.Year < second->Date.Year)
    {
        return -1;
    }
    else
    {
        if (first->Date.Month > second->Date.Month)
        {
            return 1;
        }
        else if (first->Date.Month < second->Date.Month)
        {
            return -1;
        }
        else
        {
            if (first->Date.Day > second->Date.Day)
            {
                return 1;
            }
            else if (first->Date.Day < second->Date.Day)
            {
                return -1;
            }
            else
            {
                if (first->StartTime.Hour > second->StartTime.Hour)
                {
                    return 1;
                }
                else if (first->StartTime.Hour < second->StartTime.Hour)
                {
                    return -1;
                }
                else
                {
                    if (first->StartTime.Minute > second->StartTime.Minute)
                    {
                        return 1;
                    }
                    else if (first->StartTime.Minute < second->StartTime.Minute)
                    {
                        return -1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
    }
}


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
                return;
            case 2:
                // TODO
                break;
            case 3:
                // TODO
                break;
            case 4:
                // TODO
                break;
            default:
                return;
        }
    }

}


void printAppointment(sAppointment* appointment, int print_date)
{
    char printf_format[100] = { 0 };

    if (print_date)
    {
        printf("\n");
        printLine('=', 50);
        printDate(&appointment->Date);
        printf(":\n");
        printLine('-', 14);
    }
    printf("\t");
    printTime(&appointment->StartTime);

    // TODO calculate EndTime (use new addTime Function) and print it

    if (appointment->Location)
    {
        sprintf(printf_format, " -> %%-%i.%is | ", LOCATION_MAXLEN, LOCATION_MAXLEN);
        printf(printf_format, appointment->Location);
    }
    else
    {
        int i;
        for (i = -4; i < LOCATION_MAXLEN; i++)
        {
            printf(" ");
        }
        printf(" | ");
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
    int i;
    int waiting, print_date;
    sDate printed_date = { 0 };

    if (countAppointments > 0)
    {
        HOME; CLEAR;
        printf("Liste aller Termine\n");
        printLine('=', 19);

        for (i = 0; i < countAppointments; i++)
        {
            waiting = 0;
            print_date = 0;

            if (Calendar[i].Date.Day != printed_date.Day
            || Calendar[i].Date.Month != printed_date.Month
            || Calendar[i].Date.Year != printed_date.Year)
            {
                print_date = 1;
            }

            printAppointment(&Calendar[i], print_date);

            printed_date.Day = Calendar[i].Date.Day;
            printed_date.Month = Calendar[i].Date.Month;
            printed_date.Year = Calendar[i].Date.Year;

            if ((i != 0) && ((i + 1) % LISTITEM_BREAK == 0))
            {
                waiting = 1;
                STORE_POS; waitForEnter();
                RESTORE_POS; CLEAR_BELOW;
            }
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
    for (i = 0; i < MAXAPPOINTMENTS; i++)
    {
        free(Calendar[i].Description);  Calendar[i].Description = NULL;
        free(Calendar[i].Location);     Calendar[i].Location    = NULL;
        free(Calendar[i].Duration);     Calendar[i].Duration    = NULL;
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
//
// Created by Anselm Nehls on 27.10.23.
//
#include <stdio.h>
#include <stdlib.h>
#include "../../includes/tools/tools.h"
#include "../../includes/tools/escapesequenzen.h"
#include "../../includes/ccal/datastructure.h"
#include "../../includes/ccal/datetime.h"


int errorCode = 0;
int countAppointments = 0;
sAppointment Calendar[MAXAPPOINTMENTS];


void createAppointment(void)
{
    if (countAppointments < MAXAPPOINTMENTS)
    {
        sTime*  pStartTime  = &Calendar[countAppointments].StartTime;
        sTime*  pDuration   = malloc(sizeof(sTime));
            if (pDuration == NULL) { errorCode = 1; return; }

        HOME; CLEAR;
        printf("Neuen Termin erstellen\n\n");

        if (!getDate("Datum        : ", &Calendar[countAppointments].Date))
            { return; } CLEAR_BELOW;
        if (!getTime("Beginn       : ", &pStartTime, 1))
            { return; } CLEAR_BELOW;
        if (!getText("Beschreibung : ", 100, &Calendar[countAppointments].Description, 1))
            { return; } CLEAR_BELOW;
        if (!getText("Ort          : ", 15, &Calendar[countAppointments].Location, 0))
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


void sortCalendar(void)
{
    printf("TODO: Kalender sortieren\n");
    waitForEnter();
}


void printAppointment(sAppointment* appointment, int print_date)
{
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

    if (appointment->Location)
    {
        printf(" -> %s\t | ", appointment->Location);
    }
    else
    {
        printf("\t\t | ");
    }
    printf("%s\n", appointment->Description);
}


void listCalendar(void)
{
    // TODO - Ausgabe fertigmachen
    int i;
    int waiting, print_date;
    sDate printed_date = { 0 };

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
            print_date = 1 ;
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
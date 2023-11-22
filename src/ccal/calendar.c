//
// Created by Anselm Nehls on 27.10.23.
//
#include <stdio.h>
#include <stdlib.h>
#include "../../includes/ccal/datastructure.h"
#include "../../includes/tools/tools.h"
#include "../../includes/ccal/datetime.h"


int countAppointments = 0;
sAppointment Calendar[MAXAPPOINTMENTS];


void createAppointment(void)
{
    sTime* pStart = &Calendar[countAppointments].StartTime;
    sTime* pEnd = malloc(sizeof(sTime));

    printf("Neuen Termin erstellen\n\n");

    getDate("Datum        : ", &Calendar[countAppointments].Date);
    getTime("Beginn       : ", &pStart, 1);
    getText("Beschreibung : ", 100, &Calendar[countAppointments].Description, 1);
    getText("Ort          : ", 15, &Calendar[countAppointments].Location, 0);
    getTime("Ende         : ", &pEnd, 0);

    countAppointments++;
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

void listCalendar(void)
{
    // TODO - Ausgabe fertigmachen
    int i;
    sDate* printedDate = NULL;

    printf("Liste aller Termine\n");
    printLine('=', 19);

    for (i = 0; i < countAppointments; i++)
    {
        printf("\n");
        printLine('=', 50);

        if (&Calendar[i].Date != printedDate)
        {
            printDate(&Calendar[i].Date);
            printf(":\n");
            printLine('-', 14);
        }
        printf("\t");
        printTime(&Calendar[i].StartTime);
        if (Calendar[i].Location)
            printf(" -> %s\t | ", Calendar[i].Location);
        else
            printf("\t\t | ");
        printf("%s\n", Calendar[i].Description);

        // group by date
        printedDate = &Calendar[i].Date;

        // TODO alle 15 Termine warten auf Enter
        //if (i % 15 == 0)
            //waitForEnter();
    }
}

void freeAppointment()
{
    // TODO - free Appointments
    // im loop alle Appointments dealloc
}
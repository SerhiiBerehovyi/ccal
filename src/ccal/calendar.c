//
// Created by Anselm Nehls on 27.10.23.
//
#include <stdio.h>
#include "../../includes/ccal/datastructure.h"
#include "../../includes/tools/tools.h"
#include "../../includes/ccal/datetime.h"


int countAppointments = 0;
sAppointment Calendar[MAXAPPOINTMENTS];


void createAppointment(void)
{
    printf("Todo: Termin erstellen\n");
    waitForEnter();
}

void editAppointment(void)
{

    printf("Todo: Termin bearbeiten\n");
    waitForEnter();
}

void deleteAppointment(void)
{
    printf("Todo: Termin loeschen\n");
    waitForEnter();
}

void searchAppointment(void)
{
    printf("Todo: Termin suchen\n");
    waitForEnter();
}

void sortCalendar(void)
{
    printf("Todo: Kalender sortieren\n");
    waitForEnter();
}

void listCalendar(void)
{
    printf("Todo: Termine auflisten\n");
    waitForEnter();
}

/********************************************************************
 * Funktion void inputDate(void)
 *   - Benutzer soll ein Datum eingeben.
 *   - Eingabe wird mit Hilfe der Funktion getDateFromString geparst
 *     und geprueft. Bei gueltigem Datum steht dieses in der Datums-
 *     variable Date.
 *   - Ergebnis der Eingabe wird entsprechend angezeigt.
 * Paramater: keine
 * Funktionsergebnis: nichts
 *******************************************************************/
void inputDate()
{
    sDate Date;
    char Input[20];

    printf("Geben Sie bitte ein gueltiges Datum ein: ");
    *Input = '\0';
    scanf("%19[^\n]", Input);
    clearBuffer();

    if (getDateFromString(Input, &Date))
        printf("Das Datum %02i.%02i.%04i ist gueltig!\n", Date.Day, Date.Month, Date.Year);
    else
        printf("Das eingegebene Datum '%s' ist ungueltig!\n", Input);

    printf("\n");
}

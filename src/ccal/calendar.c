//
// Created by Serhii Berehovyi on 26.10.23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes/ccal/calendar.h"
#include "../../includes/ccal/datastructure.h"
#include "../../includes/ccal/datetime.h"
#include "../../includes/tools/tools.h"
#include "../../includes/tools/escapesequenzen.h"


void createAppointment(){
    CLEAR;
    HOME;

    sAppointment* newAppointment = &Calendar[countAppointment];
    sTime* duration = malloc(sizeof(sTime));

    char* title = "Erfassung eines neuen Termins";
    printf("%s\n", title);
    printLine('=', (int) strlen(title));
    printf("\n");

    getDate("Datum         ", &newAppointment->Date);

    sTime* timeStart =  &newAppointment->TimeStart;
    getTime("Uhrzeit       ", &timeStart, 0);

    getText("Beschreibung  ", 200, &newAppointment->Notes, 0);
    getText("Ort           ", 100, &newAppointment->Location, 1);
    getTime("Dauer         ", &newAppointment->Duration, 1);

    printf("Termin wurde gespeichert!\n\n");

    countAppointment++;
}

void editAppointment(){
    // TODO: function
    printf("TODO: editAppointment\n");
}

void deleteAppointment(){
    // TODO: function
    printf("TODO: deleteAppointment\n");
}

void searchAppointment(){
    // TODO: function
    printf("TODO: searchAppointment\n");
}

void sortCalendar(){
    // TODO: function
    printf("TODO: sortCalendar\n");
}

void listCalendar(){
    CLEAR;
    HOME;

    char* title = "Liste der Termine\n";
    printf("%s", title);
    printLine('=', (int) strlen(title));

    if(!countAppointment)
    {
        printf("Sie haben noch keine Termine eingegebn.\n");
    }

    sDate* date = NULL;
    for(int i = 0; i < countAppointment; i++){
        if(date == NULL
            || (date->Day != Calendar[i].Date.Day
            || date->Month != Calendar[i].Date.Month
            || date->Year != Calendar[i].Date.Year)
        ){
            printf("\n");
            printLine('=', 80);

            date = &Calendar[i].Date;
            printDate(date, 1);
            printf(":\n");
            printLine('-', 15);
        }

        printAppointment(&Calendar[i]);

        if(i != 0 && (i+1) % 15 == 0 && i < countAppointment - 1){
            waitForEnter();
            date = NULL;
            CLEAR;
            HOME;
            printf("%s", title);
            printLine('=', (int) strlen(title));
        }
    }
}

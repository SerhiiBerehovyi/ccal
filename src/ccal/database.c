//
// Created by Serhii Berehovyi on 03.12.23.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../includes/ccal/database.h"
#include "../../includes/ccal/datetime.h"
#include "../../includes/tools/tools.h"



int saveCalendar()
{
    FILE *database = fopen(DATABASE_PATH, "w");
    if(!database)
        return 0;

    fprintf(database, "<Calendar>\n");
    for(int i = 0; i < countAppointment; i++)
    {
        if(!saveAppointment(database, &Calendar[i]))
        {
            printf("Ein Termin konnte nicht gespeichert werden.\n");
            return 0;
        }
    }
    fprintf(database, "</Calendar>");
    fclose(database);

    return 1;
}

int saveAppointment(FILE *database, sAppointment *appointment)
{
    fprintf(database, "\t<Appointment>\n");

    fprintf(database, "\t\t<Date>%02i.%02i.%04i</Date>\n", appointment->Date.Day, appointment->Date.Month, appointment->Date.Year);
    fprintf(database, "\t\t<Time>%02i:%02i</Time>\n", appointment->TimeStart.Hours, appointment->TimeStart.Minutes);
    if(appointment->Notes)
        fprintf(database, "\t\t<Description>%s</Description>\n", appointment->Notes);

    if(appointment->Duration)
        fprintf(database, "\t\t<Duration>%02i:%02i</Duration>\n", appointment->Duration->Hours, appointment->Duration->Minutes);

    if(appointment->Location)
        fprintf(database, "\t\t<Location>%s</Location>\n", appointment->Location);

    fprintf(database, "\t</Appointment>\n");

    return 1;
}

int loadCalendar()
{
    FILE *database = fopen(DATABASE_PATH, "r");
    if(!database)
    {
        printf("Kalender konnte nicht abgelesen werden.\n");
        return 0;
    }

    char lineBuffer[200] = { 0 };
    char *lb;
    int scanned;
    int calendarFound = 0;

    do {
        *lineBuffer = '\0';
        scanned = fscanf(database, "%199[^\n]", lineBuffer);
        fclearBuffer(database);
        lb = lineBuffer;

        if(feof(database))
            break;

        if(*lineBuffer == '\0' || !scanned)
        {
            printf("Der Datenbank konnte nicht geladen werden.\n");
            return 0;
        }

        // skip spaces & tabs
        while(*lb == ' ' || *lb == '\t')
            lb++;

        skipControlCharacters(lb);


        if(!strncmp(lb, "<Calendar>", 10))
        {
            printf("Termine werden geladen.\n");
            calendarFound = 1;
        }

        if(strncmp(lb, "</Calendar>", 11) == 0)
            break;

        if(calendarFound)
        {
            if(!loadAppointment(database, &Calendar[countAppointment++]))
            {
                printf("Termin konnte nicht geladen werden.\n");
                countAppointment--;
            }
        }
    } while(strncmp(lb, "</Calendar>", 11) != 0);

    fclose(database);

    printf("\n%i Terminen wurden erfolgreich geladen.\nFertig.\n", countAppointment);
    waitForEnter();

    return 1;
}

int loadAppointment(FILE *database, sAppointment *appointment)
{
    char lineBuffer[200] = { 0 };
    char *lb;
    int scanned;

    int foundDate = 0;
    int foundTime = 0;
    int foundDuration = 0;
    int foundLocation = 0;
    int foundDescription = 0;

    do{
        *lineBuffer = '\0';
        scanned = fscanf(database, "%199[^\n]", lineBuffer);
        fclearBuffer(database);
        lb = lineBuffer;

        if(feof(database))
            break;

        if(*lineBuffer == '\0' || !scanned)
            continue;

        // skip spaces & tabs
        while(*lb == ' ' || *lb == '\t')
            lb++;

        skipControlCharacters(lb);

        if(!strncmp(lb, "<Date>", 6) && !foundDate)
        {
            unsigned long len = strlen(lb + 6) - 7;
            if (strncmp(lb + 6 + len, "</Date>", 7) == 0)
            {
                cutTail(lb + 6, "</Date>");
                if (!getDateFromString(lb + 6, &appointment->Date))
                {
                    return 0;
                }
                foundDate = 1;
            }
        }
        else if(!strncmp(lb, "<Time>", 6) && !foundTime)
        {
            unsigned long len = strlen(lb + 6) - 7;
            if (strncmp(lb + 6 + len, "</Time>", 7) == 0)
            {
                cutTail(lb + 6, "</Time>");
                if (!getTimeFromString(lb + 6, &appointment->TimeStart))
                {
                    return 0;
                }
                foundTime = 1;
            }
        }
        else if(!strncmp(lb, "<Duration>", 10) && !foundDuration)
        {
            unsigned long len = strlen(lb + 10) - 11;
            if (strncmp(lb + 10 + len, "</Duration>", 11) == 0)
            {
                appointment->Duration = malloc(sizeof(sTime));
                if (appointment->Duration)
                {
                    cutTail(lb + 10, "</Duration>");
                    getTimeFromString(lb + 10, appointment->Duration);
                    foundDuration = 1;
                }
            }
        }
        else if(!strncmp(lb, "<Location>", 10) && !foundLocation)
        {
            unsigned long len = strlen(lb + 10) - 11;
            if (strncmp(lb + 10 + len, "</Location>", 11) == 0)
            {
                appointment->Location = calloc(len + 1, sizeof(char));
                if (appointment->Location)
                {
                    strncpy(appointment->Location, lb + 10, len);
                    if (strlen(appointment->Location) > 0)
                    {
                        foundLocation = 1;
                    }
                    else
                    {
                        free(appointment->Location);
                        appointment->Location = NULL;
                    }
                }
            }
        }
        else if(!strncmp(lb, "<Description>", 13) && !foundDescription)
        {
            unsigned long len = strlen(lb + 13) - 14;
            if (strncmp(lb + 13 + len, "</Description>", 14) == 0)
            {
                appointment->Notes = calloc(len + 1, sizeof(char));
                if (appointment->Notes)
                {
                    strncpy(appointment->Notes, lb + 13, len);
                    foundDescription = 1;
                }
            }
        }
    } while(strncmp(lb, "</Appointment>", 14) != 0);

    if(!foundTime || !foundDate || !foundDescription)
        return 0;

    printf(".");
    return 1;
}
//
// Created by Anselm Nehls on 27.11.23.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../includes/ccal/datastructure.h"
#include "../../includes/ccal/database.h"
#include "../../includes/ccal/datetime.h"
#include "../../includes/tools/tools.h"


int saveCalendar()
{
    int i;

    FILE* fp_database = fopen(DATABASE_FILENAME, "wt");
    if (!fp_database)
    {
        errorCode = 3;
        return 0;
    }

    fprintf(fp_database, "<Calendar>\n");

    for (i = 0; i < countAppointments; i++)
    {
        if (!saveAppointment(fp_database, &Calendar[i]))
        {
            errorCode = 3;
            return 0;
        }
    }

    fprintf(fp_database, "</Calendar>");

    fclose(fp_database);
    return 1;
}


int saveAppointment(FILE* fp, sAppointment* appointment)
{
    fprintf(fp, "\t<Appointment>\n");
    fprintf(fp, "\t\t<Date>%i.%i.%i</Date>\n", appointment->Date.Day, appointment->Date.Month, appointment->Date.Year);
    fprintf(fp, "\t\t<Time>%i:%i</Time>\n", appointment->StartTime.Hour, appointment->StartTime.Minute);
    fprintf(fp, "\t\t<Description>%s</Description>\n", appointment->Description);
    if (appointment->Location)
    {
        fprintf(fp, "\t\t<Location>%s</Location>\n", appointment->Location);
    }
    if (appointment->Duration)
    {
        fprintf(fp, "\t\t<Duration>%i:%i</Duration>\n", appointment->Duration->Hour, appointment->Duration->Minute);
    }
    fprintf(fp, "\t</Appointment>\n");
    return 1;
}


int loadCalendar()
{
    FILE* fp_database = fopen(DATABASE_FILENAME, "rt");
    if (!fp_database)
    {
        errorCode = 2;
        return 0;
    }

    int found_calendar = 0;
    char input_line[100];
    char *lp; // line_ptr

    do
    {
        if (!fscanf(fp_database, "%99[^\n]", input_line))
        {
            errorCode = 2;
            return 0;
        }
        fclearBuffer(fp_database);

        lp = input_line;
        while (*lp == ' ' || *lp == 9) // skip spaces & tabs
        {
            lp++;
        };

        if (strncmp (lp, "<Calendar>", 10) == 0)
        {
            found_calendar = 1;
            printf("Lade Termine\n");
        }

        if (found_calendar)
        {
            if (strncmp(lp, "<Appointment>", 13) == 0)
            {
                loadAppointment(fp_database, &Calendar[countAppointments]);
                countAppointments++;
            }
        }

        if (feof(fp_database))
        {
            break;
        }

    } while (strncmp(lp, "</Calendar>", 11) != 0);

    waitForEnter();

    return 1;
}


int loadAppointment(FILE* fp, sAppointment* appointment)
{
    char input_line[100];
    char *lp;

    printf(".");

    do
    {
        if (!fscanf(fp, "%99[^\n]", input_line))
        {
            errorCode = 2;
            return 0;
        }
        fclearBuffer(fp);

        lp = input_line;
        while (*lp == ' ' || *lp == 9) // skip spaces & tabs
        {
            lp++;
        };

        if (strncmp(lp, "<Date>", 6) == 0)
        {
            unsigned long len = strlen(lp + 6) - 7;
            if (strncmp(lp + 6 + len, "</Date>", 7) == 0)
            {
                if (!getDateFromString(lp + 6, &appointment->Date))
                {
                    errorCode = 2;
                    return 0;
                }
            }
        }
        else if (strncmp(lp, "<Time>", 6) == 0)
        {
            unsigned long len = strlen(lp + 6) - 7;
            if (strncmp(lp + 6 + len, "</Time>", 7) == 0)
            {
                if (!getTimeFromString(lp + 6, &appointment->StartTime))
                {
                    errorCode = 2;
                    return 0;
                }
            }
        }
        else if (strncmp(lp, "<Description>", 13) == 0)
        {
            unsigned long len = strlen(lp + 13) - 14;
            if (strncmp(lp + 13 + len, "</Description>", 14) == 0)
            {
                appointment->Description = calloc(len + 1, sizeof(char));
                if (appointment->Description)
                {
                    strncpy(appointment->Description, lp + 13, len);
                }
            }
        }
        else if (strncmp(lp, "<Location>", 10) == 0)
        {
            unsigned long len = strlen(lp + 10) - 11;
            if (strncmp(lp + 10 + len, "</Location>", 11) == 0)
            {
                appointment->Location = calloc(len + 1, sizeof(char));
                if (appointment->Location)
                {
                    strncpy(appointment->Location, lp + 10, len);
                }
            }
        }
        else if (strncmp(lp, "<Duration>", 10) == 0)
        {
            unsigned long len = strlen(lp + 10) - 11;
            if (strncmp(lp + 10 + len, "</Duration>", 11) == 0)
            {
                appointment->Duration = malloc(sizeof(sTime));
                if (appointment->Duration)
                {
                    getTimeFromString(lp, appointment->Duration);
                }
            }
        }

        if (feof(fp))
        {
            break;
        }

    } while (strncmp(lp, "</Appointment>", 13) != 0);

    if (!isDateValid(&appointment->Date) || !isTimeValid(&appointment->StartTime) || !appointment->Description)
    {
        errorCode = 2;
        return 0;
    }

    return 1;
}
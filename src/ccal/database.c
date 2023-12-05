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
    FILE* fp_database = fopen(DATABASE_FILENAME, "rb");
    if (!fp_database)
    {
        errorCode = 5;
        return 0;
    }

    int foundCalendar = 0;
    char input_line[100] = { 0 };
    char *lp;

    do
    {
        *input_line = '\0';
        int scan_ok = fscanf(fp_database, "%99[^\n]", input_line);
        fclearBuffer(fp_database);

        if (feof(fp_database))
        {
            break;
        }

        if (*input_line == '\0' || !scan_ok)
        {
            errorCode = 2;
            return 0;
        }

        lp = input_line;
        while (*lp == ' ' || *lp == 9) // skip spaces & tabs
        {
            lp++;
        };

        if (strncmp (lp, "<Calendar>", 10) == 0)
        {
            printf("Lade Termine ");
            foundCalendar = 1;
        }

        if (foundCalendar)
        {
            if (strncmp(lp, "<Appointment>", 13) == 0)
            {
                if (loadAppointment(fp_database, &Calendar[countAppointments]))
                {
                    countAppointments++;
                }
                else
                {
                    errorCode = 6;
                }
            }
        }

    } while (strncmp(lp, "</Calendar>", 11) != 0);

    printf("\n");
    waitForEnter();

    return 1;
}


int loadAppointment(FILE* fp, sAppointment* appointment)
{
    char input_line[100] = { 0 };
    char *lp;

    int foundDate = 0;
    int foundTime = 0;
    int foundDescription = 0;
    int foundLocation = 0;
    int foundDuration = 0;

    do
    {
        *input_line = '\0';
        int scan_ok = fscanf(fp, "%99[^\n]", input_line);
        fclearBuffer(fp);

        if (feof(fp))
        {
            break;
        }

        if (*input_line == '\0' || !scan_ok)
        {
            continue;
        }

        lp = input_line;
        while (*lp == ' ' || *lp == 9) // skip spaces & tabs
        {
            lp++;
        }


        if (strncmp(lp, "<Date>", 6) == 0)
        {
            if (!foundDate)
            {
                char* closing_tag = lp + 6;
                while (*closing_tag != '<')
                {
                    closing_tag++;
                }

                if (strncmp(closing_tag, "</Date>", 7) == 0)
                {
                    if (!getDateFromString(lp + 6, &appointment->Date))
                    {
                        return 0;
                    }
                    foundDate = 1;
                }
            }
        }
        else if (strncmp(lp, "<Time>", 6) == 0)
        {
            if (!foundTime)
            {
                char* closing_tag = lp + 6;
                while (*closing_tag != '<')
                {
                    closing_tag++;
                }

                if (strncmp(closing_tag, "</Time>", 7) == 0)
                {
                    if (!getTimeFromString(lp + 6, &appointment->StartTime))
                    {
                        return 0;
                    }
                    foundTime = 1;
                }
            }
        }
        else if (strncmp(lp, "<Description>", 13) == 0)
        {
            if (!foundDescription)
            {
                int len = 0;
                char* closing_tag = lp + 13;
                while (*closing_tag != '<')
                {
                    len++;
                    closing_tag++;
                }

                if (len > 0 && (strncmp(closing_tag, "</Description>", 14) == 0))
                {
                    appointment->Description = calloc(len + 1, sizeof(char));
                    if (appointment->Description)
                    {
                        strncpy(appointment->Description, lp + 13, len);
                        foundDescription = 1;
                    }
                }
            }
        }
        else if (strncmp(lp, "<Location>", 10) == 0)
        {
            if (!foundLocation)
            {
                int len = 0;
                char* closing_tag = lp + 10;
                while (*closing_tag != '<')
                {
                    len++;
                    closing_tag++;
                }

                if (len > 0 && (strncmp(closing_tag, "</Location>", 11) == 0))
                {
                    appointment->Location = calloc(len + 1, sizeof(char));
                    if (appointment->Location)
                    {
                        strncpy(appointment->Location, lp + 10, len);
                        foundLocation = 1;
                    }
                }
            }
        }
        else if (strncmp(lp, "<Duration>", 10) == 0)
        {
            if (!foundDuration)
            {
                char* closing_tag = lp + 10;
                while (*closing_tag != '<')
                {
                    closing_tag++;
                }

                if (strncmp(closing_tag, "</Duration>", 11) == 0)
                {
                    appointment->Duration = malloc(sizeof(sTime));
                    if (appointment->Duration)
                    {
                        getTimeFromString(lp + 10, appointment->Duration);
                        foundDuration = 1;
                    }
                }
            }
        }

    } while (strncmp(lp, "</Appointment>", 13) != 0);

    if (!foundDate || !foundTime || !foundDescription)
    {
        return 0;
    }

    printf(".");
    return 1;
}
//
// Created by Anselm Nehls on 27.11.23.
//

#include <stdio.h>
#include "../../includes/ccal/datastructure.h"
#include "../../includes/ccal/database.h"

//

int saveCalendar()
{
    int i;

    FILE* fp_database = fopen(DATABASE_FILENAME, "wt");
    if (!fp_database)
    {
        errorCode = 2; // TODO-opt define / check error codes ... maybe 2 = could not open file?
        return 0;
    }

    fprintf(fp_database, "<Calendar>\n");

    for (i = 0; i < countAppointments; i++)
    {
        if (!saveAppointment(fp_database, &Calendar[i]))
        {
            errorCode = 3; // TODO-opt errorcodes -- maybe 3? could not save appointment
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


int loadCalendar() // TODO
{
    // open file for reading, get fp
    // loop:
        // read line
        // evaluate line
            // if <Calendar> -> ...?
            // if <Appointment> ->
                // call loadAppointment(fp)
    // check for (end-tags || file end) (sonst Endlosschleife)
    // close file
    return 1;
}


int loadAppointment() // TODO
{
    // receives file ptr
    // go through the fields, read them
    // return to loadCal
    return 1;
}


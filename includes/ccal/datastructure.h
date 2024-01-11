//
// Created by Serhii Berehovyi on 20.10.23.
//

#ifndef CCAL_DATASTRUCTURE_H
#define CCAL_DATASTRUCTURE_H

#define PROGRAM_VERSION "0.6"
#define PROGRAM_TITLE "Kalenderverwaltung"
#define PRINTED_TITLE PROGRAM_TITLE " v" PROGRAM_VERSION

#define MENUITEM_MAXLENGTH 50
#define MENUITEM_MAXNUM 50
#define LISTITEM_BREAK 15

#define LOCATION_MAXLEN 15
#define DESCRIPTION_MAXLEN 100

#define DATABASE_FILENAME "calendar.xml"

enum eDayOfTheWeek
{
    NotADay = 0,
    Mo, Di, Mi, Do, Fr, Sa, So
};


typedef struct
{
    int Day, Month, Year;
    enum eDayOfTheWeek WeekDay;
} sDate;


typedef struct
{
    int Hour, Minute;
} sTime;


typedef struct sAppointment_
{
    sDate Date;
    sTime StartTime;
    sTime* Duration;
    char* Description;
    char* Location;

    struct sAppointment_ *Next;
    struct sAppointment_ *Prev;
} sAppointment;


extern int errorCode;
extern int countAppointments;
extern sAppointment *First, *Last;

#endif //CCAL_DATASTRUCTURE_H

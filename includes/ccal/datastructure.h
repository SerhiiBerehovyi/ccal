//
// Created by Serhii Berehovyi on 20.10.23.
//

#ifndef CCAL_DATASTRUCTURE_H
#define CCAL_DATASTRUCTURE_H


#define MAXAPPOINTMENTS 100
#define MENUITEM_MAXLENGTH 50
#define MENUITEM_MAXNUM 50
#define LISTITEM_BREAK 15

#define LOCATION_MAXLEN 15
#define DESCRIPTION_MAXLEN 100

#define DATABASE_FILENAME "database.xml"

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


typedef struct
{
    sDate Date;
    sTime StartTime;
    sTime* Duration;
    char* Description;
    char* Location;
} sAppointment;


extern int errorCode;
extern int countAppointments;
extern sAppointment Calendar[];


#endif //CCAL_DATASTRUCTURE_H

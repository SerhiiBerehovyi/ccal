//
// Created by Serhii Berehovyi on 20.10.23.
//

#ifndef CCAL_DATASTRUCTURE_H
#define CCAL_DATASTRUCTURE_H


#define MAXAPPOINTMENTS 100
#define MENUITEM_MAXLENGTH 50
#define MENUITEM_MAXNUM 50


enum eDayOfTheWeek
{
    NotADay = 0,
    Mo, Di, Mi, Do, Fr, Sa, Su
};


typedef struct
{
    int Day, Month, Year;
    enum eDayOfTheWeek WeekDay;
} sDate;


typedef struct
{
    int Hour, Minute, Second;
} sTime;


typedef struct
{
    sDate Date;
    sTime StartTime;
    sTime* EndTime;
    char* Description;
    char* Location;
} sAppointment;


extern int countAppointments;
extern sAppointment Calendar[];


#endif //CCAL_DATASTRUCTURE_H

//
// Hier werden die Datenstrukturen der Datenbank mit typedef definiert.
//
// Created by Serhii Berehovyi on 20.10.23.
//

#ifndef CCAL_DATASTRUCTURE_H
#define CCAL_DATASTRUCTURE_H

#define MAXAPPOINTMENTS 100

enum eDayOfTheWeek {
    NotADay, Mo, Tu, We, Th, Fr, Sa, Su
};

typedef struct {
    int Day, Month, Year;
    enum eDayOfTheWeek weekDay;
} sDate;

typedef struct {
    int Hours, Minutes, Seconds;
} sTime;

typedef struct {
    sDate Date;
    sTime TimeStart, TimeEnd;
    char* Notes;
} sAppointment;


extern int countAppointment;
extern sAppointment Calendar[];

#endif //CCAL_DATASTRUCTURE_H

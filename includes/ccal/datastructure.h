//
// Hier werden die Datenstrukturen der Datenbank mit typedef definiert.
//
// Created by Serhii Berehovyi on 20.10.23.
//

#ifndef CCAL_DATASTRUCTURE_H
#define CCAL_DATASTRUCTURE_H

#define MAXAPPOINTMENTS 100

/******************************************************************************
 * Die Enumeration mit Wochentagen.
 * 0 entspricht einem falschen Eingabe - kein Wochentag
 * 1 entspricht dem Montag
 * 2 - Dienstag
 * ...
 * 7 entspricht dem Sonntag
 * ***************************************************************************/
enum eDayOfTheWeek {
    NotADay, Mo, Tu, We, Th, Fr, Sa, Su
};

/******************************************************************************
 * Die Datenstruktur, die ein Datum represeintiert.
 * Tag, Monat und Jahr werden als ein int gespeichert.
 * Die Datenstruktur speichert auch einen Wochentag als enum eDayOfTheWeek
 * ***************************************************************************/
typedef struct {
    int Day, Month, Year;
    enum eDayOfTheWeek weekDay;
} sDate;

/******************************************************************************
 * Die Datenstruktur representiert die Uhrzeit.
 * Stunden und Minuten werden als int gespeichert.
 * ***************************************************************************/
typedef struct {
    int Hours, Minutes;
} sTime;

/******************************************************************************
 * Die Datenstruktur representiert einen Termin.
 * Hier werden das Datum als sDate Objekt, Uhrzeit als sTime Objekt gespeichert,
 * der Dauer als ein Zeiger auf sTime Objekt und Ort mit Beschreibung als
 * Zeiger auf char-Kette gespeichert.
 * ***************************************************************************/
typedef struct {
    sDate Date;
    sTime TimeStart;
    sTime* Duration;
    char* Notes;
    char* Location;
} sAppointment;

// Anzahl von bereits gespeicherten Terminen
extern int countAppointment;

// ein Array mit den bereits gespeicherten Terminen
extern sAppointment Calendar[MAXAPPOINTMENTS];

#endif //CCAL_DATASTRUCTURE_H

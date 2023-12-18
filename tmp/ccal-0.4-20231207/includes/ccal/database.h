//
// Created by Anselm Nehls on 27.11.23.
//

#ifndef CCAL_DATABASE_H
#define CCAL_DATABASE_H


/*************************************************************************************
* Funktion:         saveCalendar
* Beschreibung:     Speichert den globalen Kalender in eine XML-Datei
*
* Parameter:        -
* Ergebnis:         -
*************************************************************************************/
int saveCalendar();


/*************************************************************************************
* Funktion:         saveAppointment
* Beschreibung:     Speichert einen per Zeiger übergebenen Termin in die übergebene
*                   Datei
*
* Parameter:        FILE *                  Zeiger auf XML-Datei
 *                  sAppointment *          Zeiger auf Termin
* Ergebnis:         -
*************************************************************************************/
int saveAppointment(FILE *, sAppointment *);


/*************************************************************************************
* Funktion:         loadCalendar
* Beschreibung:     Lädt den globalen Kalender aus einer XML-Datei
*
* Parameter:        -
* Ergebnis:         -
*************************************************************************************/
int loadCalendar();


/*************************************************************************************
* Funktion:         loadAppointment
* Beschreibung:     Lädt einen Termin aus der übergebenen XML-Datei und speichert
*                   ihn in ein struct
*
* Parameter:        FILE *                  Zeiger auf XML-Datei
 *                  sAppointment *          Zeiger auf zu ladenden Termin
* Ergebnis:         -
*************************************************************************************/
int loadAppointment(FILE *, sAppointment *);


#endif //CCAL_DATABASE_H

//
// Created by Anselm Nehls on 27.10.23.
//


#ifndef CCAL_CALENDAR_H
#define CCAL_CALENDAR_H


/*************************************************************************************
* Funktion:         createAppointment
* Beschreibung:     Fragt vom Benutzer alle zur Erstellung eines neuen
*                   Termins nötigen Informationen ab und speichert diesen Termin in
 *                  einen neuen Datensatz vom Typ sAppointment (global).
*
* Parameter:        -
* Ergebnis:         -
*************************************************************************************/
void createAppointment(void);


/*************************************************************************************
* Funktion:         editAppointment
* Beschreibung:
*
* Parameter:        -
* Ergebnis:         -
*************************************************************************************/
void editAppointment(void);


/*************************************************************************************
* Funktion:         deleteAppointment
* Beschreibung:
*
* Parameter:        -
* Ergebnis:         -
*************************************************************************************/
void deleteAppointment(void);


/*************************************************************************************
* Funktion:         searchAppointment
* Beschreibung:
*
* Parameter:        -
* Ergebnis:         -
*************************************************************************************/
void searchAppointment(void);


/*************************************************************************************
* Funktion:         sortCalendar
* Beschreibung:
*
* Parameter:        -
* Ergebnis:         -
*************************************************************************************/
void sortCalendar(void);


/*************************************************************************************
* Funktion:         printAppointment
* Beschreibung:     Gibt einen Termin auf dem Bildschirm aus
*
* Parameter:        sAppointment appointment    Auszugebender Termin
*                   int print_date              Soll Datum gedruckt werden
*                                               1 - ja  0 - nein
* Ergebnis:         -
**************************************************************************************/
void printAppointment(sAppointment* appointment, int print_date);


/*************************************************************************************
* Funktion:         listCalendar
* Beschreibung:     Gibt den Inhalt des Kalenders auf dem Bildschirm aus
*
* Parameter:        -
* Ergebnis:         -
*************************************************************************************/
void listCalendar(void);


/*************************************************************************************
* Funktion:         freeAppointments
* Beschreibung:     Gibt alle für Termine reservierten Speicherbereiche wieder frei
*
* Parameter:        -
* Ergebnis:         -
*************************************************************************************/
void freeAppointments(void);


/*************************************************************************************
* Funktion:         closeCalendar
* Beschreibung:     Fragt den Benutzer, ob der Kalender gespeichert werden soll,
*                   speichert ggf. den Kalender und beendet dann das Programm
*
* Parameter:        -
* Ergebnis:         -
*************************************************************************************/
void closeCalendar(void);


#endif //CCAL_CALENDAR_H

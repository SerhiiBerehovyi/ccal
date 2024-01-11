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
* Beschreibung:     Listet alle Termine mit einer Nummer auf und fragt den Benutzer
 *                  mittels int askForNumber(char *prompt) aus tools.h nach
 *                  Eingabe einer Zahl. Der under dieser Zahl stehende Termin wird
 *                  geloescht.
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


/*************************************************************************************
* Funktion:         compare_by_description
* Beschreibung:     Vergleicht die Beschreibungen zweier per Zeiger übergebener Termine
*                   und gibt deren alphabetische Reihenfolge zurück (unabhängig von
*                   Groß- / Kleinschreibung)
*
* Parameter:        sAppointment *      Erster Termin
*                   sAppointment *      Zweiter Termin
*
* Ergebnis:         int                  1 - Zweiter Termin, erster Termin
*                                        0 - beide Beschreibungen sind gleich
*                                       -1 - Erster Termin, zweiter Termin
*************************************************************************************/
int compare_by_description(sAppointment *, sAppointment *);


/*************************************************************************************
* Funktion:         compare_by_location
* Beschreibung:     Vergleicht die Ortsangaben zweier per Zeiger übergebener Termine
*                   und gibt deren alphabetische Reihenfolge zurück (unabhängig von
*                   Groß- / Kleinschreibung). Termine ohne Ortsangabe werden an den
*                   Anfang sortiert.
*
* Parameter:        sAppointment *      Erster Termin
*                   sAppointment *      Zweiter Termin
*
* Ergebnis:         int                  1 - Zweiter Termin, erster Termin
*                                        0 - beide Ortsangaben sind gleich
*                                       -1 - Erster Termin, zweiter Termin
*************************************************************************************/
int compare_by_location(sAppointment *, sAppointment *);


/*************************************************************************************
* Funktion:         compare_by_duration
* Beschreibung:     Vergleicht die Dauern zweier per Zeiger übergebener Termine
*                   und gibt deren Reihenfolge zurück.
*                   Termine ohne Angabe einer Dauer werden an den Anfang sortiert.
*
* Parameter:        sAppointment *      Erster Termin
*                   sAppointment *      Zweiter Termin
*
* Ergebnis:         int                  1 - Zweiter Termin kürzer als erster Termin
*                                        0 - beide Termine sind gleich lang
*                                       -1 - Erster Termin kürzer als zweiter Termin
*************************************************************************************/
int compare_by_duration(sAppointment *, sAppointment *);


/*************************************************************************************
* Funktion:         compare_by_date_and_time
* Beschreibung:     Vergleicht die Startzeitpunkte zweier per Zeiger übergebener Termine
*                   und gibt deren zeitliche Reihenfolge zurück.
*
* Parameter:        sAppointment *      Erster Termin
*                   sAppointment *      Zweiter Termin
*
* Ergebnis:         int                  1 - Zweiter Termin liegt vor erstem Termin
*                                        0 - Startzeitpunkt beider Termine gleich
*                                       -1 - Erster Termin liegt vor zweitem Termin
*************************************************************************************/
int compare_by_date_and_time(sAppointment *, sAppointment *);


#endif //CCAL_CALENDAR_H

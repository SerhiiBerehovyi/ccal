//
// Created by Serhii Berehovyi on 25.01.24.
//

#ifndef CCAL_SEARCH_H
#define CCAL_SEARCH_H

#include "datastructure.h"


/*************************************************************************************
* Funktion:         calcDivisionsrest
* Beschreibung:     Berechnet den Divisionsrest von der übergebenen Zeichenkette
 *                  durch MAXINDEX der Hasch-Tabelle
*
* Parameter:        char *      Zeiger auf die Zeichenkette
*
* Ergebnis:         Divisionsrest - Summe aller char-Werte durch MAXINDEX
*************************************************************************************/
int calcDivisionsrest(char *toHash);


/*************************************************************************************
* Funktion:         search
* Beschreibung:     Sucht den ersten Eintrag von Appointment mit übereingestimmten
 *                  Beschreibung und gibt den Zeiger darauf zurück.
*
* Parameter:        sHashEntry*         Zeiger auf eine sHashEntry, in der entsprechender
 *                                      Termin gesucht wird.
 *                  int (*)             Zeiger auf eine Vergleich-Funktion
 *                                      (sAppointment *, sAppointment *)
 *                  sAppointment *      Termin, nach deren Beschreibung gesucht wird.
*
* Ergebnis:         sLIEntry*           Zeiger auf den ersten gefundenen List-Eintrag mit
 *                                      entsprechenden Termin
 *                                      NULL, wenn keinen Eintrag gefunden wurde.
*************************************************************************************/
sLIEntry* search(sHashEntry* appIndex, int (*compare)(sAppointment *, sAppointment *), sAppointment* toSearch);


#endif //CCAL_SEARCH_H

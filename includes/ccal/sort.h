//
// Created by Anselm Nehls on 17.12.23.
//

#include "datastructure.h"

#ifndef CCAL_SORT_H
#define CCAL_SORT_H


/*************************************************************************************
* Funktion:         swap_appointments
* Beschreibung:     Vertauscht zwei per Zeiger übergebene Termine
*
* Parameter:        sAppointment *      Erster Termin
*                   sAppointment *      Zweiter Termin
*
* Ergebnis:         -
*************************************************************************************/
void swap_appointments(sAppointment *, sAppointment *);


/*************************************************************************************
* Funktion:         partition
* Beschreibung:     Teilt ein übergebenes Array von Terminen in zwei Segmente,
*                   basierend auf einem Pivot-Element. Dabei werden alle Termine
*                   die kleiner als der Pivot-Termin sind, links davon positioniert und alle
*                   größeren rechts davon. Ob ein Termin kleiner oder größer als der Pivot ist,
*                   wird mittels einer per Zeiger übergebenen Vergleichsfunktion ermittelt, so
*                   dass anhand verschiedener Vergleichsfunktionen unterschiedliche Eigenschaften
*                   der Termine zum Vergleich herangezogen werden können.
*
* Parameter:        sAppointment *appointments  Zeiger auf das Array von Terminen
*                   int lower_idx               Index des unteren Segments
*                   int upper_idx               Index des oberen Segments
*                   int (*compare_func_ptr)     Zeiger auf die Vergleichsfunktion
*                                               (sAppointment *, sAppointment *)
* Ergebnis:         int                         Index des Pivot-Elements nach der Partitionierung
*************************************************************************************/
int partition(sAppointment *, int, int, int (*) (sAppointment *, sAppointment *));


/*************************************************************************************
* Funktion:         quicksort
* Beschreibung:     Implementiert einen rekursiven Quicksort-Algorithmus zur Sortierung
*                   eines per Zeiger übergebenen Arrays von Terminen.
*                   Zur Bestimmung der Reihenfolge wird eine per Zeiger übergebene
*                   Vergleichsfunktion verwendet, so dass anhand verschiedener
*                   Vergleichsfunktionen unterschiedliche Eigenschaften der Termine
*                   zum Vergleich herangezogen werden können.
*
* Parameter:        sAppointment *appointments  Zeiger auf das Array von Terminen
*                   int lower_idx               Index des unteren Segments
*                   int upper_idx               Index des oberen Segments
*                   int (*compare_func_ptr)     Zeiger auf die Vergleichsfunktion
*                                               (sAppointment *, sAppointment *)
* Ergebnis:         -
*************************************************************************************/
void quicksort(sAppointment *, int, int, int (*) (sAppointment *, sAppointment *));


/*************************************************************************************
* Funktion:         sort_appointments
* Beschreibung:     Sortiert eine Liste von Terminen unter Verwendung des Quicksort-Algorithmus
*                   sowie einer spezifischen Vergleichsfunktion.
*
* Parameter:        sAppointment *appointments  Zeiger auf das Array von Terminen
*                   int count                   Anzahl der Termine im Array
*                   int (*compare_func_ptr)     Zeiger auf die Vergleichsfunktion
*                                               (sAppointment *, sAppointment *)
* Ergebnis:         -
*************************************************************************************/
void sort_appointments(sAppointment *appointments, int count, int (*compare_func_ptr)(sAppointment *, sAppointment *));


#endif //CCAL_SORT_H

//
// Created by Serhii Berehovyi on 11.01.24.
//

#ifndef CCAL_LIST_H
#define CCAL_LIST_H

#include "datastructure.h"


/*************************************************************************************
* Funktion:         insertInDList
*
* Beschreibung:     fuegt einen neuen Element auf die richtige Stelle in der aufsteigend
 *                  sortierten Liste *First ein.
*
* Parameter:        sAppointment *new       Element zum Einfuegen
*
* Ergebnis:         -
*
*************************************************************************************/
void insertInDList(sAppointment *new);

/*************************************************************************************
* Funktion:         removeFromDList
*
* Beschreibung:     loescht einen Element aus der doppelt verkaeteten Liste *First.
*
* Parameter:        sAppointment *app       Link auf einen Element der Liste, der gesloescht
 *                                          werden muss.
*
* Ergebnis:         -
*
*************************************************************************************/
void removeFromDList(sAppointment *app);


#endif //CCAL_LIST_H

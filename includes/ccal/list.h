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


/*************************************************************************************
* Funktion:         insertInSList
* Beschreibung:     Fügt einen neuen Element in die einfach-verkettete Liste hinzu.
*
* Parameter:        sHashEntry *            Zeiger auf den ersten Eintrag der
 *                                          verketteten Liste
 *                  sLIEntry *              Zeiger auf den neuen Element, der
 *                                          eingefügt werden muss.
*
* Ergebnis:         1       :   Wenn der neuen Element erfolgreich eingefügt wurde
 *                  0       :   Andernfalls
*************************************************************************************/
int insertInSList(sHashEntry *hashEntry, sLIEntry *new);


/*************************************************************************************
* Funktion:         removeFromSList
* Beschreibung:     Löscht den Element entry aus der einfach-verketteten Liste.
*
* Parameter:        sHashEntry *            Zeiger auf den ersten Eintrag der
 *                                          verketteten Liste
 *                  sLIEntry *              Zeiger auf den neuen Element, der
 *                                          gelöscht werden muss.
*
* Ergebnis:         ein Link auf aus der Liste gelöschten Element
 *                  oder NULL, wenn das Löschen war nicht erfolgreich.
*************************************************************************************/
sLIEntry* removeFromSList(sHashEntry *hashEntry, sLIEntry *entry);

#endif //CCAL_LIST_H

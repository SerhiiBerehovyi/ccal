//
// Created by Serhii Berehovyi on 20.10.23.
//

#ifndef CCAL_DATETIME_H
#define CCAL_DATETIME_H


#include "datastructure.h"

/*************************************************************************************
* Funktion:         addTime
* Beschreibung:     Addiert zwei im Format sTime vorliegende Zeitangaben
*
* Parameter:        sTime *         Zeiger auf erste Zeitangabe
*                   sTime *         Zeiger auf zweite Zeitangabe
* Ergebnis:         sTime           Resultierende Zeitangabe
*************************************************************************************/
sTime addTime(sTime *, sTime *);


/*******************************************
 * Die Funktion testet, ob das eingegebene Jahr
 * Schaltjahr ist.
 *
 * int year : Jahr zum Pruefen
 *
 * output : 1 , wenn das Jahr ein Schaltjahr ist.
 *          0 , wenn nicht
 * *****************************************/
int isLeapYear(int year);


/*******************************************
 * Die Funktion testet, ob in sDate gespeichertes Datum
 * gueltig ist. Schaltjahre werden auch beruecksichtigt.
 *
 * sDate* date : Zeiger auf in structure gespeichertes Datum,
 *               das auf gueltigkeit geprueft werden muss.
 *
 * output : 1 , wenn das Datum gueltig ist.
 *          0 , wenn nicht
 * *****************************************/
int isDateValid(sDate* date);


/*******************************************
 * Testet, ob sTime eine gültige Zeitangabe im Format hh:mm ist
 *
 * sTime* time: Zeiger auf sTime struct
 *
 * output : 1 , gueltig
 *          0 , ungueltig
 * *****************************************/
int isTimeValid(sTime* time);


/*******************************************
 * Die Funktion konvertiert die gegebene Zeichenkette in
 * eine POSITIVE Zahl, die dann zurueckgibt.
 *
 * char* str : die Zeichenkette, die in eine Zahl konvertiert
 *             werden muss.
 *
 * output : die in str representierende POSITIVE Nummer
 *          -1 , falls in str keine POSITIVE Zahl dargestellt wird.
 * *****************************************/
int stringToInt(char* str);


/*******************************************
 * Die Funktion liest Substring bis zum naechten '.' oder bis zum Ende
 * der Vorgegebenen Zeile *str und speichert die abgelesene
 * Zeichenkette in *dest. Die Rueckgabe ist ein Pointer auf naechsten
 * Zeichen in *str oder auf '\0'
 *
 * char* str  : Pointer auf die Zeile in der wir ein Substring suchen
 * char* dest : Pointer auf die Zeichenkette, in der
 *              Substring gespeichert werden muss.
 *
 * output : Pointer auf den naechsten Zeichen in str oder auf '\0'.
 * *****************************************/
char* getSubstring(char* str, char* dest);


/*******************************************
 * Die Funktion liest die Zeichenkette aus input und prueft
 * das in input eingegebenes Datum auf gueltigkeit.
 * Gueltiges Datum wird dann in date gespeichert.
 *
 * char* input : Zeiger auf die Zeichenkette mit von User
 *               eingegebenen Datum
 * sDate* date : Zeiger auf sDate Struktur, in die gueltiges
 *               Datum gespeichert werden muss.
 *
 * output : 1 , wenn das eingegebene Datum gueltig ist.
 *          0 , wenn nicht
 * *****************************************/
int getDateFromString(char* input, sDate* date);


/*******************************************
 * Die Funktion liest die Zeichenkette aus input und prueft
 * ob es sich um eine valide Zeitangabe im Format hh:mm handelt.
 * Gueltige Zeitangabe wird dann in sTime gespeichert.
 *
 * char* input : Zeiger auf Zeichenkette von User-Input
 *
 * sDate* date : Zeiger auf sDate Struktur, in die gueltige
 *               Zeitangabe gespeichert werden muss.
 *
 * output : 1 , wenn die eingegebene Zeitangabe gueltig ist.
 *          0 , wenn nicht
 * *****************************************/
int getTimeFromString(char* input, sTime* time);


/*************************************************************************************
* Funktion:         getDate
* Beschreibung:     Fordert den Benutzer auf, ein Datum einzugeben und speichert dieses in
*                  einer per Zeiger übergebenen sDate Struktur
*
* Parameter:        char* prompt        Zeiger auf Text-Array mit Eingabeaufforderung
*                   sDate* date         Zeiger auf Speicherziel
* Ergebnis:         0 - Fehler bei Speicherzuweisung
*                   1 - OK
*************************************************************************************/
int getDate(char* prompt, sDate* date);


/*************************************************************************************
* Funktion:         getTime
* Beschreibung:     Fordert den Benutzer auf, eine Zeitangabe einzugeben und speichert
*                   diese in einer per Zeiger übergebenen sTime Struktur
*
* Parameter:        char* prompt        Zeiger auf Text-Array mit Eingabeaufforderung
*                   sTime* time         Zeiger auf Speicherziel
* Ergebnis:         0 - Fehler bei Speicherzuweisung
*                   1 - OK
*************************************************************************************/
int getTime(char* prompt, sTime** time, int required);


/*************************************************************************************
* Funktion:         printDate
* Beschreibung:     Gibt ein per Zeiger übergebenes Datum auf dem Bildschirm aus
*
* Parameter:        sDate* date         Zeiger auf Datum
* Ergebnis:         -
*************************************************************************************/
void printDate(sDate* date);


/*************************************************************************************
* Funktion:         printTime
* Beschreibung:     Gibt eine per Zeiger übergebene Zeitangabe auf dem Bildschirm aus
*
* Parameter:        sTime* time         Zeiger auf Zeitangabe
* Ergebnis:         -
*************************************************************************************/
void printTime(sTime* time);


#endif //CCAL_DATETIME_H

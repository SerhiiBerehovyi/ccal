//
// Created by Serhii Berehovyi on 20.10.23.
//

#ifndef CCAL_DATETIME_H
#define CCAL_DATETIME_H


#include "datastructure.h"


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
int strToInt(char* str);

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
char* getSubstring(char* str, char* dest, char separator);

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

int getTimeFromString(char* input, sTime* time);

int getDate(char* prompt, sDate* date);

int getTime(char* prompt, sTime* time);

void printDate(sDate* date, int withDay);

void printTime(sTime* time);

void printAppointment(sAppointment* appointment);

void freeCalendar(sAppointment* appointments);

#endif //CCAL_DATETIME_H

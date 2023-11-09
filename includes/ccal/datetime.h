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

/******************************************************************************
 * Die Funktion testet, ob in time gespeicherte Zeit gueltig ist.
 *
 * input: sTime* time: ist ein Zeiger auf ein sTime Objekt, in dem
 *                     die Zeit zum Pruefen gespeichert wird.
 *
 * output: 1, wenn die Zeit gueltig ist,
 *         0, wenn nicht
 * ***************************************************************************/
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

/******************************************************************************
 * Die Funktion liest die Zeichenkette aus input und prueft, ob die
 * in input eingegebene Zeichenkette als Zeit interpretiert werden kann.
 * Gueltige Zeit wird dann gespeichert und 1 bzw. 0 wird zurueckgegeben.
 *
 * inputs:  char* input: ist ein Zeiger auf von User eingegebene Zeit.
 *          sTime* time: ist ein Zeiger auf sTime struktur, in die
 *                       gueltige Zeit gespeichert werden muss.
 *
 * output:  1, wenn das eingegebene Zeit gueltig ist,
 *          0, wenn nicht.
 * ***************************************************************************/
int getTimeFromString(char* input, sTime* time);

/******************************************************************************
 * Die Funktion fragt den User nach eingabe von einem Datum solange der
 * das gueltige Datum eingibt.
 *
 * inputs:  char* prompt:   ein Zeiger auf eine Zeichenkette, die
 *                          vor Usereingabe auf den Bildschirm ausgegeben
 *                          werden muss.
 *          sDate* date:    ein Zeiger auf sDate Objekt, in dem das gueltige
 *                          Datum gespeichert werden muss.
 * ***************************************************************************/
void getDate(char* prompt, sDate* date);

/******************************************************************************
 * Die Funktion fragt den User nach eingabe von einer gueltigen Uhrzeit.
 * Es ist hier erlaubt, die leere Eingabe zu machen.
 *
 * inputs:  char* prompt:   ein Zeiger auf Zeichenkette, die vor Usereingabe
 *                          auf den Bildschirm ausgegeben werden muss.
 *          sTime* time:    ein Zeiger auf ein Stime Objekt, in dem die
 *                          gueltige Uhrzeit gespechert werden muss.
 * output:  1, wenn die gueltige Uhrzeit eingegeben wurde und
 *          0, wenn User einfach Eingabetaste drueckt, ohne was einzugeben.
 * ***************************************************************************/
int getTime(char* prompt, sTime* time);

/******************************************************************************
 * Die Funktion gibt das Datum mithilfe von einfachen printf() auf
 * den Bildschirm aus.
 *
 * inputs:  sDate* date:    ein Zeiger auf das Datum, das ausgegeben werden muss.
 *          int withDay:    wenn 1, es wird erst der Wochentag in Format
 *                          Tag, xx.xx.xxxx ausgegeben.
 *                          wenn 0, es wird kein Wochentag ausgegeben
 * ***************************************************************************/
void printDate(sDate* date, int withDay);

/******************************************************************************
 * Die Funktion gibt die Uhrzeit mithilfe von printf() uaf den Bildschirm aus.
 *
 * input:   sTime* time:    ein Zeiger auf sTime Objekt, in dem die Uhrzeit
 *                          gespeichert wird, die auf den Bildschirm ausgegeben
 *                          werden muss.
 * ***************************************************************************/
void printTime(sTime* time);

/******************************************************************************
 * Die Funktion gibt einen Termin appointment auf den Bildschirm aus.
 * Format der Ausgabe ist:
 *      Uhrzeit -> Ort | Beschreibung
 *
 * sAppointment* appointment:   ist ein Zeiger auf sAppointment Objekt,
 *                              der auf den Bildschirm ausgegeben werden muss.
 * ***************************************************************************/
void printAppointment(sAppointment* appointment);

/******************************************************************************
 * Die Funktion geht den Array mit Terminen durch und befreit den Speicher fuer
 * jeden sAppointment Objekt in Calendar[] Array.
 * free() wird fuer sAppointment.Notes, sAppointment.Location und
 * sAppointment.Duration aufgerufen.
 * ***************************************************************************/
void freeCalendar();

#endif //CCAL_DATETIME_H

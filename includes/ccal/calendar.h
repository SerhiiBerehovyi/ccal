//
// Created by Serhii Berehovyi on 26.10.23.
//

#ifndef CCAL_CALENDAR_H
#define CCAL_CALENDAR_H

/******************************************************************************
 * Die Funktion erstellt einen neuen Termin.
 * Der Bildschirm wird erst geloescht, dann der titel der Feld auf den bildschirm
 * ausgegeben.
 * Das Datum, Uhrzeit, Beschreibung, Ort und Dauer werden schrittweise abgefragt.
 *
 * Das Datum und Uhrzeit werden solange gefragt, bis der User die gueltige
 * Daten eingibt. Beschreibung und Ort werden eingegeben und fuer sie
 * wird es genau so viel Speicher, wie sie benoetigen, reserviert.
 * (mithilfe von getText() in - siehe tools.h)
 *
 * Es wird speicher fuer Dauer reserwiert und wenn User kein Dauer fuer
 * gegebenen Termin eingibt, wird free() fuer diesen Speicher aufgerufen.
 * ***************************************************************************/
void createAppointment();

/******************************************************************************
 * ***************************************************************************/
void editAppointment();

/******************************************************************************
 * ***************************************************************************/
void deleteAppointment();

/******************************************************************************
 * ***************************************************************************/
void searchAppointment();

/******************************************************************************
 * ***************************************************************************/
void sortCalendar();

/*****************************************************************************
 * Die Funktion listet alle Termine auf.
 * Es wird erst das Datum ausgegeben, dann alle Termine fuer dieses Datum mithilfe
 * von printAppointment() auf den bildschirm ausgegeben.
 * Auf dem Bildschirm werden 15 Termine ausgegeben. Falls es mehr gibt, wird der
 * User nach dem Eingabetastedruecken gefordert, nachdem die naechste 15
 * Termeni ausgegeben werden.
 * ***************************************************************************/
void listCalendar();


#endif //CCAL_CALENDAR_H

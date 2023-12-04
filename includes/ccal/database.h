//
// Created by Anselm Nehls on 27.11.23.
//
// TODO -  Funktionsheader

#ifndef CCAL_DATABASE_H
#define CCAL_DATABASE_H

int saveCalendar();
int saveAppointment(FILE *, sAppointment *);

int loadCalendar();
int loadAppointment(FILE *, sAppointment *);

#endif //CCAL_DATABASE_H

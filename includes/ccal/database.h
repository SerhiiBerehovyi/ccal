//
// Created by Serhii Berehovyi on 03.12.23.
//

#ifndef CCAL_DATABASE_H
#define CCAL_DATABASE_H


#define DATABASE_PATH "../data/calendar.xml"

#include "datastructure.h"

int saveCalendar();

int saveAppointment(FILE *database, sAppointment *appointment);

int loadCalendar();

int loadAppointment(FILE *database, sAppointment *appointment);

#endif //CCAL_DATABASE_H

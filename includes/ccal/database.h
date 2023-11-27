//
// Created by Anselm Nehls on 27.11.23.
//

#ifndef CCAL_DATABASE_H
#define CCAL_DATABASE_H

int saveCalendar();
int saveAppointment(FILE* fp, sAppointment* appointment);

int loadCalendar();
int loadAppointment();

#endif //CCAL_DATABASE_H

//
// Created by Anselm Nehls on 17.12.23.
//

#include "datastructure.h"

#ifndef CCAL_SORT_H
#define CCAL_SORT_H

void brutesort(sAppointment *appointment, int count);

// TODO funktionsheader

int compare_by_date_and_time(sAppointment *first, sAppointment *second);

void swap_appointments(sAppointment *first, sAppointment *second);

int partition(sAppointment *, int, int, int (*) (sAppointment *, sAppointment *));

void quicksort(sAppointment *, int, int, int (*) (sAppointment *, sAppointment *));

void sort_appointments(sAppointment *appointments, int count, int (*compare_func_ptr)(sAppointment *, sAppointment *));


#endif //CCAL_SORT_H

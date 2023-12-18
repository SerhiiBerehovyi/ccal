//
// Created by Anselm Nehls on 17.12.23.
//

#include <stdio.h>
#include "../../includes/ccal/sort.h"


void swap_appointments(sAppointment *first, sAppointment *second)
{
    sAppointment tmp;

    tmp = *first;
    *first  = *second;
    *second = tmp;
}


int partition(sAppointment *appointments, int lower_idx, int upper_idx, int (*compare_func_ptr) (sAppointment *, sAppointment *))
{
    sAppointment *pivot = appointments + lower_idx;
    int i = lower_idx + 1;
    int j = upper_idx;

    while (i <= j)
    {
        while ( i <= j && compare_func_ptr(appointments + i, pivot) <= 0 )
        {
            i++;
        }
        while ( j >= i && compare_func_ptr(appointments + j, pivot) >= 0 )
        {
            j--;
        }
        if (i < j)
        {
            swap_appointments(appointments + i, appointments + j);
            i++;
            j--;
        }
    }
    i--;
    swap_appointments(pivot, appointments + i);

    printf(".");

    return i;
}


void quicksort(sAppointment *appointments, int lower_idx, int upper_idx, int (*compare_func_ptr) (sAppointment *, sAppointment *))
{
    int pivot;

    if (lower_idx >= upper_idx)
    {
        return;
    }
    else
    {
        pivot = partition(appointments, lower_idx, upper_idx, compare_func_ptr);
        quicksort(appointments, lower_idx, pivot - 1, compare_func_ptr);
        quicksort(appointments, pivot + 1, upper_idx, compare_func_ptr);
    }
}


void sort_appointments(sAppointment *appointments, int count, int (*compare_func_ptr) (sAppointment *, sAppointment *))
{
    printf("Sortiere Kalender ");

    quicksort(appointments, 0, count - 1, compare_func_ptr);

    printf("\n\nFertig.\n");
}

//
// Created by Anselm Nehls on 17.12.23.
//

#include "../../includes/ccal/sort.h"


void swap(sAppointment *this, sAppointment *that)
{
    sAppointment tmp;
    tmp = *this;
    *this = *that;
    *that = tmp;
}


int partition(sAppointment *array, int lower, int upper, int (*compare_func_ptr) (sAppointment *, sAppointment *))
{
    sAppointment *pivot = array + lower;
    int i = lower + 1;
    int j = upper;

    while (i <= j)
    {
        while ( (i <= j) && ((compare_func_ptr(array + i, pivot)) <= 0) )
        {
            i++;
        }
        while ( (j >= i) && ((compare_func_ptr(array + j, pivot)) >= 0) )
        {
            j--;
        }
        if (i < j)
        {
            swap(array + i, array + j);
            i++;
            j--;
        }
    }
    i--;
    swap(pivot, array + i);

    return i;
}

void quicksort(sAppointment *array, int lower, int upper, int (*compare_func_ptr) (sAppointment *, sAppointment *))
{
    int pivot;

    if (lower >= upper)
    {
        return;
    }
    else
    {
        pivot = partition(array, lower, upper, compare_func_ptr);
        quicksort(array, lower, pivot - 1, compare_func_ptr);
        quicksort(array, pivot + 1, upper, compare_func_ptr);
    }
}


void sort_appointments(sAppointment *array, int count, int (*compare_func_ptr) (sAppointment *, sAppointment *))
{
    quicksort(array, 0, countAppointments - 1, compare_func_ptr);
}
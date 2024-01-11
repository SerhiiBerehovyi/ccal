//
// Created by Serhii Berehovyi on 11.01.24.
//

#include <stdlib.h>
#include "../../includes/ccal/list.h"
#include "../../includes/ccal/calendar.h"

void insertInDList(sAppointment *new)
{
    if(!new)
        return;

    if (!First || compare_by_date_and_time(First, new) >= 0)
    {
        new->Prev = NULL;
        new->Next = First;
        if(First)
            First->Prev = new;
        First = new;
    }
    else
    {
        sAppointment *tmp = First;
        while(tmp->Next && compare_by_date_and_time(tmp->Next, new) <= 0)
        {
            tmp = tmp->Next;
        }
        new->Next = tmp->Next;

        if(tmp->Next)
            tmp->Next->Prev = new;
        else
            Last = new;

        tmp->Next = new;
        new->Prev = tmp;
    }
}

void removeFromDList(sAppointment *app)
{
    if(!app) return;

    if(app->Prev) // is not head of the list
    {
        app->Prev->Next = app->Next;
    } else {
        First = app->Next;
    }

    if(app->Next) // is not a last of the list
    {
        app->Next->Prev = app->Prev;
    }
    else
    {
        Last = app->Prev;
    }

    free(app);
}
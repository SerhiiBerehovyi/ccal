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


int insertInSList(sHashEntry *hashEntry, sLIEntry *new)
{
    if(!new || !hashEntry)
    {
        return 0;
    }

    new->next = NULL;

    if(!hashEntry->first)
    {
        hashEntry->first = new;
        hashEntry->last = new;
        return 1;
    }
    else
    {
        hashEntry->last->next = new;
        hashEntry->last = new;
        return 1;
    }
}

sLIEntry* removeFromSList(sHashEntry *hashEntry, sLIEntry *entry)
{
    if(!hashEntry || !entry)
    {
        return NULL;
    }

    sLIEntry *tmp = NULL;
    if(hashEntry->first == entry)
    {
        if(hashEntry->first == hashEntry->last)
        {
            hashEntry->last = NULL;
        }
        tmp = hashEntry->first;
        hashEntry->first = hashEntry->first->next;
        return tmp;
    }

    sLIEntry *prev = hashEntry->first;
    while(prev)
    {
        if(prev->next == entry)
        {
            tmp = prev->next;
            prev->next = entry->next;
            if(prev->next == hashEntry->last)
                hashEntry->last = prev;
            return tmp;
        }
        prev = prev->next;
    }

    return NULL;
}
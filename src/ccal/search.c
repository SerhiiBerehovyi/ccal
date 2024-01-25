//
// Created by Serhii Berehovyi on 25.01.24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../includes/ccal/search.h"
#include "../../includes/ccal/datetime.h"
#include "../../includes/tools/tools.h"
#include "../../includes/tools/escapesequenzen.h"

int calcDivisionsrest(char* toHash)
{
    int sum = 0;

    while(*toHash)
    {
        sum +=   (*toHash);
        toHash++;
    }

    return (  sum % MAXINDEX );
}

sLIEntry* search(sHashEntry* appIndex, int compare(sAppointment *, sAppointment * ), sAppointment* toSearch)
{
    unsigned int index = calcDivisionsrest(toSearch->Description);

    sHashEntry* currHashIndex = appIndex + index;

    if(!currHashIndex->first)
        return NULL;

    sLIEntry* tmp = currHashIndex->first;
    while(tmp)
    {
        if(compare(tmp->data, toSearch) == 0)
            return tmp;

        tmp = tmp->next;
    }

    return NULL;
}

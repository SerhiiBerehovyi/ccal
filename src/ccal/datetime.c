//
// Created by Serhii Berehovyi on 20.10.23.
//


#include "../../includes/ccal/datetime.h"

int isLeapYear(int year) {
    return ( !(year % 4) && (year % 100) || !(year % 400) );
}
int isDateValid(sDate* date) {
    if (date->Year > 2099 || date->Year < 1900)
        return 0;
    if (date->Month >12 || date->Month < 1)
        return 0;

    switch (date->Month) {
        case 4: case 6:
        case 9: case 11:
            if (date->Day < 1 || date->Day > 30)
                return 0;
            break;
        case 2:
            if (date->Day < 1 || date->Day > (28 + isLeapYear(date->Year)) )
                return 0;
            break;
        default:
            if (date->Day < 1 || date->Day > 31)
                return 0;
            break;
    }
    return 1;
}


int strToInt(char* str){
    int result = 0;

    while(*str){
        if (*str < '0' || *str > '9')
            return -1;

        result = result * 10 + (*str - '0');
        str++;
    }

    return result;
}

char* getSubstring(char* str, char* dest){
    while(*str && *str != '.'){
        *dest = *str;
        dest++;
        str++;
    }
    *dest = '\0';
    if (*str)
        str++;
    return str;
}

int getDateFromString(char* input, sDate* date){
    char day[100], month[100], year[100];
    char* tmp = input;

    tmp = getSubstring(tmp, day);
    tmp = getSubstring(tmp, month);
    tmp = getSubstring(tmp, year);

    date->Day = strToInt(day);
    date->Month = strToInt(month);
    date->Year = strToInt(year);

    if (isDateValid(date))
        return 1;
    return 0;
}
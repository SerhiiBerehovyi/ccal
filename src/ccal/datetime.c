//
// Created by Serhii Berehovyi on 20.10.23.
//

#include <stdio.h>
#include "../../includes/ccal/datetime.h"
#include "../../includes/tools/escapesequenzen.h"
#include "../../includes/tools/tools.h"

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


int isTimeValid(sTime* time) {
    if(time->Hours > 24 || time->Hours < 0)
        return 0;

    if(time->Minutes > 59 || time->Minutes < 0)
        return 0;

    if(time->Seconds > 59 || time->Seconds < 0)
        return 0;

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

char* getSubstring(char* str, char* dest, char separator){
    while(*str && *str != separator){
        *dest = *str;
        dest++;
        str++;
    }
    *dest = '\0';
    if (*str) {
        str++;
        return str;
    }
    return NULL;
}

int getDateFromString(char* input, sDate* date){
    char day[20], month[20], year[20];
    char* tmp = input;

    tmp = getSubstring(tmp, day, '.');
    tmp = getSubstring(tmp, month, '.');
    tmp = getSubstring(tmp, year, '.');

    date->Day = strToInt(day);
    date->Month = strToInt(month);
    date->Year = strToInt(year);

    if (isDateValid(date)) {
        // Den Tag finden
        int d = date->Day;
        int m = (date->Month == 2) ? 12 : (date->Month - 2) % 12;
        int c = (int) date->Year / 100;
        int y = date->Year % 100;

        int w = ((int) (d + (int) (2.6 * (double) m - 0.2) +
                y +(int) ((double) y/4) + (int) ((double) c / 4) - 2 * c)) % 7;

        date->weekDay =  (w == 0) ? 7 : w ;

        return 1;
    }

    return 0;
}


int getTimeFromString(char* input, sTime* time){
    char hours[20], minutes[20], seconds[20];
    char* tmp = input;

    tmp = getSubstring(tmp, hours, ':');
    tmp = getSubstring(tmp, minutes, ':');
    tmp = getSubstring(tmp, seconds, ':');

    time->Hours = strToInt(hours);
    time->Minutes = strToInt(minutes);
    time->Seconds = strToInt(seconds);

    if(isTimeValid(time)) {
        return 1;
    }

    return 0;
}


void getDate(char* prompt, sDate* date){
    char input[20];
    int scanned;

    SAVE_POSITION;
    do {
        RESTORE_POSITION;
        CLEAR_BELOW;
        printf("%s: ", prompt);
        *input = '\0';

        scanned = scanf("%19[^\n]", input);
        clearBuffer();

        if (scanned) {
            if (getDateFromString(input, date))
                return;
       }
    } while(1);
}


void getTime(char* prompt, sTime* time){
     char input[20];
     int scanned;

     SAVE_POSITION;
     do {
         RESTORE_POSITION;
         CLEAR_BELOW;
         printf("%s: ", prompt);
         *input = '\0';

         scanned = scanf("%19[^\n]", input);
         clearBuffer();

         if (scanned){
             if (getTimeFromString(input, time))
                 return;
         }
     }while(1);
}
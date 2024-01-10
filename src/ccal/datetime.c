//
// Created by Serhii Berehovyi on 20.10.23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes/ccal/datetime.h"
#include "../../includes/tools/escapesequenzen.h"
#include "../../includes/tools/tools.h"

int countAppointment = 0;
sAppointment Calendar[MAXAPPOINTMENTS];


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
    if(time->Hours > 23 || time->Hours < 0)
        return 0;

    if(time->Minutes > 59 || time->Minutes < 0)
        return 0;

    return 1;
}


int strToInt(char* str){
    if(!*str)
        return -1;

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
    }
    return str;
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

    time->Hours = strToInt(hours);
    time->Minutes = strToInt(minutes);

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


int getTime(char* prompt, sTime** time, int blank){
     char input[20];
     int scanned;

     if(time == NULL)
         return 0;

     if(*time == NULL) {
         *time = malloc(sizeof(sTime));
         if(*time == NULL)
             return 0;
     }

     SAVE_POSITION;
     do {
         RESTORE_POSITION;
         CLEAR_BELOW;
         printf("%s: ", prompt);
         *input = '\0';

         scanned = scanf("%19[^\n]", input);
         clearBuffer();

         if (scanned){
             if (getTimeFromString(input, *time))
                 return 1;
         }

         if (*input == '\0' && blank){
             free(*time);
             *time = NULL;
             return 1;
         }
     }while(1);
}

void printDate(sDate* date, int withDay){
    if(withDay){
        switch (date->weekDay) {
            case NotADay:
                printf("..., ");
                break;
            case Mo:
                printf("Mo, ");
                break;
            case Tu:
                printf("Tu, ");
                break;
            case We:
                printf("We, ");
                break;
            case Th:
                printf("Th, ");
                break;
            case Fr:
                printf("Fr, ");
                break;
            case Sa:
                printf("Sa, ");
                break;
            case Su:
                printf("Su, ");
                break;
        }
    }

    printf("%02i.%02i.%04i", date->Day, date->Month, date->Year);
}

void printTime(sTime* time){
    printf("%02i:%02i", time->Hours, time->Minutes);
}

void printAppointment(sAppointment* appointment) {
    int maxLocationLength = 20;
    int maxNotesLength = 48;

    printTime(&appointment->TimeStart);
    printf(" -> ");

    if (appointment->Location) {
        printWithEllipsis(appointment->Location, maxLocationLength);
        if (strlen(appointment->Location) < maxLocationLength)
            RIGHT(maxLocationLength - (int) strlen(appointment->Location));
    } else {
        RIGHT(maxLocationLength);
    }

    printf(" | ");

    printWithEllipsis(appointment->Notes, maxNotesLength);

    printf("\n");
}

void freeCalendar(){
    for(int i = 0; i < countAppointment; i++){
        freeAppointment(Calendar[i]);
    }
}

void freeAppointment(sAppointment appointment){
    free(appointment.Notes);
    free(appointment.Location);
    if(appointment.Duration != NULL)
        free(appointment.Duration);
}
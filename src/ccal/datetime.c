//
// Created by Serhii Berehovyi on 20.10.23.
//

#include <stdio.h>
#include <stdlib.h>
#include "../../includes/ccal/datetime.h"
#include "../../includes/tools/tools.h"
#include "../../includes/tools/escapesequenzen.h"


int isLeapYear(int year)
{
    return ( !(year % 4) && (year % 100) || !(year % 400) );
}


enum eDayOfTheWeek getWeekday(sDate* date)
{
    if (date->Day > 10)
        return Su;
    else
        return Mo;
}


int isDateValid(sDate* date)
{
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


int isTimeValid(sTime* time)
{
    if ((time->Hour   < 0 || time->Hour   > 24)
    ||  (time->Minute < 0 || time->Minute > 60))
    {
        return 0;
    }
    return 1;
}


int getDateFromString(char *input, sDate *date)
{
    int  valid      = 0;
    char *pDay      = NULL;
    char *pMonth    = NULL;
    char *pYear     = NULL;

    do
    {
        if ((*input >= '0') && (*input <= '9'))
        {
            if (pDay == NULL)
                pDay = input;

            valid = 1;
            input++;
        }
        else if (*input == '.')
        {
            if (pDay == NULL)
            {
                valid = 0;
                break;
            }
            if (pMonth == NULL)
            {
                pMonth = ++input;
            }
            else if (pYear == NULL)
            {
                pYear = ++input;
                break;
            }
        }
        else
        {
            valid = 0;
        }
    } while (valid && (*input != '\n'));

    if (valid)
    {
        sDate d;
        d.Day   = atoi(pDay);
        d.Month = atoi(pMonth);
        d.Year  = atoi(pYear);
        d.WeekDay = getWeekday(&d);

        if (isDateValid(&d))
            *date = d;
        else
            valid = 0;
    }
    return valid;
}


int getTimeFromString(char* input, sTime* time)
{
    int  valid       = 0;
    char *pHour      = NULL;
    char *pMinute    = NULL;

    do
    {
        if ((*input >= '0') && (*input <= '9'))
        {
            if (pHour == NULL)
                pHour = input;

            valid = 1;
            input++;
        }
        else if (*input == ':')
        {
            if (pHour == NULL)
            {
                valid = 0;
                break;
            }
            if (pMinute == NULL)
            {
                pMinute = ++input;
                break;
            }
        }
        else
        {
            valid = 0;
        }
    } while (valid && (*input != '\n'));

    if (valid)
    {
        sTime t;
        t.Hour   =   atoi(pHour);
        t.Minute =   atoi(pMinute);

        if (isTimeValid(&t))
            *time = t;
        else
            valid = 0;
    }
    return valid;
}


int getDate(char* prompt, sDate* date)
{
    if (date == NULL)
    {
        return 0;
    }

    int scanf_ok;
    char input[11]; // 00.00.0000 + \n = 11

    SAVE_POSITION;
    while(1)
    {
        printf("%s", prompt);
        scanf_ok = scanf("%10[^\n]", input);
        clearBuffer();

        if (scanf_ok)
        {
            if (getDateFromString(input, date))
            {
                return 1;
            }
        }
        printf("Format: dd.mm.yyyy\n");
        RESTORE_POS; CLEAR_LINE;
    }
}


int getTime(char* prompt, sTime** time, int required)
{
    if (time == NULL)
    {
        return 0;
    }

    if (*time == NULL)
    {
        *time = malloc(sizeof(sTime));
        if (*time == NULL) { return 0; }
    }

    int scanf_ok;
    char input[6]; // 00:00 + \n = 6

    SAVE_POSITION;
    while(1)
    {
        printf("%s", prompt);
        scanf_ok = scanf("%5[^\n]", input);
        clearBuffer();

        if (scanf_ok)
        {
            if (getTimeFromString(input, *time))
            {
               return 1;
            }
        }
        else
        {
            if (!required)
            {
                free(*time);
                *time = NULL;
                return 1;
            }
        }
        printf("Format: hh:mm\n");
        RESTORE_POS; CLEAR_LINE;
    }
}


void printDate(sDate* date)
{
    char* weekday;
    switch (date->WeekDay) {
        case Mo:
            weekday = "Mo"; break;
        case Di:
            weekday = "Di"; break;
        case Mi:
            weekday = "Mi"; break;
        case Do:
            weekday = "Do"; break;
        case Fr:
            weekday = "Fr"; break;
        case Sa:
            weekday = "Sa"; break;
        case Su:
            weekday = "So"; break;
        case NotADay:
            weekday = "  "; break;
    }
            printf("%s, %.02i.%.02i.%.4i", weekday, date->Day, date->Month, date->Year);
}


void printTime(sTime* time)
{
    printf("%.02i:%.02i", time->Hour, time->Minute);
}

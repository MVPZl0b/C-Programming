#include <stdio.h>
#include <time.h>
/*
Author: COP2220
Date: 4-24-22
Description: this program demonstrates the use of some of the function from the time library
             functions to display current date and time.
*/
int main()
{
    struct tm strtime;
    time_t timeoftheday;
    strtime.tm_year = 2022-1900;
    strtime.tm_mon = 1;
    strtime.tm_mday = 1;
    strtime.tm_hour = 12;
    strtime.tm_min = 30;
    strtime.tm_sec = 30;
    strtime.tm_isdst = 0;
    timeoftheday = mktime(&strtime);
    printf(ctime(&timeoftheday));
    return 0;
}

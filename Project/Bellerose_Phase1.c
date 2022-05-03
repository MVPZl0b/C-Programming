#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
/*
Author: Zackery Bellerose
Date: 04/30/2022
Description: This program is an irrigation controller system simulator

*/

#define buffer 80

struct controller
{
    time_t currentTime;
    struct tm *local_time;
    double rainSensor;
    int zoneCount;
    struct zone
    {
        time_t endTime;
        time_t startTime;
        int totalMinutes;
        int sequence;
        bool skipped;
        char state[10];
    };
    struct zone *pzone;
} typedef controller;

// Prototypes:
void dispDateTime();
int menu();
int selectZoneCount();
void configureZones(controller *pcontroller, int zoneCount);

int main()
{
    // Delcarations:
    controller *pcontroller = malloc(1 * sizeof(controller));
    int option = 0;
    int zoneCount = 0;
    char input[buffer] = {' '};
    char *pinput = NULL;

    while (option != 7)
    {
        option = menu();
        switch (option)
        {
        case 1:
            dispDateTime();
            break;
        case 2: // Option to select the number of zones the user wishes to use.
            zoneCount = selectZoneCount();
            // Allocates memory for each zone.
            pcontroller->pzone = malloc(zoneCount * sizeof(pcontroller->pzone));
            // Sets zoneCount value in controller struct.
            pcontroller->zoneCount = zoneCount;
            break;
        case 3: // Configure each zone.
            configureZones(pcontroller, zoneCount);
            break;
        case 4: // Set rain sensor Limits

            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            printf("\n\nPress any key to continue....");
            getchar(); // Switched from windows to mac, had to change from getch();
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid input. Try again.\n");
            break;
        }
    }
    return 0;
} // end main()

void dispDateTime()
{
    time_t currentTime;
    struct tm *local_time;
    currentTime = time(NULL);
    local_time = localtime(&currentTime);
    // system("cls");                                                    // clear screen
    printf("\nThe current date and time is %s\n", asctime(local_time)); // display system date and time.
}

int menu()
{
    dispDateTime();
    char input[buffer] = "";
    char *pinput = NULL;
    int choice = 0;
    printf("-1-Set date and time\n"
           "-2-Select number of zones\n"
           "-3-Configure operation of all zones\n"
           "-4-Set Rain sensor limits\n"
           "-5-Schedule the operation\n"
           "-6-Reset system\n"
           "-7-Quit Program\n"
           "===>Enter choice: ");
    pinput = fgets(input, buffer, stdin);
    strtok(pinput, "\n");
    choice = atoi(pinput);
    return choice;
} // End menu()

// Option number 2: Sel;ect number of zones.
int selectZoneCount()
{

    int zoneCount = 0;
    char input[buffer] = "";
    char *pinput = NULL;
    dispDateTime();
    printf("Please select the number of zones you wish to use: ");
    pinput = fgets(input, buffer, stdin);
    strtok(pinput, "\n");
    zoneCount = atoi(pinput);

    return zoneCount;
}

void configureZones(controller *pcontroller, int zoneCount)
{

    char input[buffer] = "";
    char *pinput = NULL;

    int currentZone = 0;
    dispDateTime();
    while (currentZone < zoneCount)
    {
        int option = 1;
        printf("Would you like to configure zone %d? 1 for yes, 2 for no: ", currentZone);
        pinput = fgets(input, buffer, stdin);
        strtok(pinput, "\n");
        option = atoi(pinput);
        if(option != 2) {
            struct tm zoneTime;
            time_t timeoftheday;

            printf("Please enter the start month (00) for zone %d: ", currentZone);
            pinput = fgets(input, buffer, stdin);
            strtok(pinput, "\n");
            zoneTime.tm_year = 2022-1900;
            zoneTime.tm_mon = atoi(pinput) - 1;

            printf("Please enter the start day (00) for zone %d: ", currentZone);
            pinput = fgets(input, buffer, stdin);
            strtok(pinput, "\n");
            zoneTime.tm_mday = atoi(pinput);

            printf("Please enter the start hour (00) for zone %d: ", currentZone);
            pinput = fgets(input, buffer, stdin);
            strtok(pinput, "\n");
            zoneTime.tm_hour = atoi(pinput);

            printf("Please enter the start minute (00) for zone %d: ", currentZone);
            pinput = fgets(input, buffer, stdin);
            strtok(pinput, "\n");
            zoneTime.tm_min = atoi(pinput);

            timeoftheday = mktime(&zoneTime);
            pcontroller->pzone[currentZone].startTime = timeoftheday;
            printf("The start time you have selected for zone %d is %s\n", currentZone, ctime(&timeoftheday));

            printf("Please enter the end month (00) for zone %d: ", currentZone);
            pinput = fgets(input, buffer, stdin);
            strtok(pinput, "\n");
            zoneTime.tm_year = 2022-1900;
            zoneTime.tm_mon = atoi(pinput) - 1;

            printf("Please enter the end day (00) for zone %d: ", currentZone);
            pinput = fgets(input, buffer, stdin);
            strtok(pinput, "\n");
            zoneTime.tm_mday = atoi(pinput);

            printf("Please enter the end hour (00) for zone %d: ", currentZone);
            pinput = fgets(input, buffer, stdin);
            strtok(pinput, "\n");
            zoneTime.tm_hour = atoi(pinput);

            printf("Please enter the end minute (00) for zone %d: ", currentZone);
            pinput = fgets(input, buffer, stdin);
            strtok(pinput, "\n");
            zoneTime.tm_min = atoi(pinput);

            timeoftheday = mktime(&zoneTime);
            pcontroller->pzone[currentZone].endTime = timeoftheday;
            printf("The end time you have selected for zone %d is %s\n", currentZone, ctime(&timeoftheday));
        }
        currentZone++;
        continue;
    }

    printf("Press any key to continue to the menu....");
    getchar();
} // end configureZones()

int setSensorLimits(controller *pcontroller) {
    char input[buffer] = "";
    char *pinput = NULL;
} // end setSensorLimits()
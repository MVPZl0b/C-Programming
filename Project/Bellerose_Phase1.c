#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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
        time_t operationTime;
        time_t currentTimeZone;
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

int main()
{
    // Delcarations:
    
    controller *pcontroller = malloc(3 * sizeof(controller));
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
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            printf("\n\nPress any key to continue....");
            getch();
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
    system("cls");                                                    // clear screen
    printf("The current date and time is %s\n", asctime(local_time)); // display system date and time.
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
           "-5-Schedule the operation"
           "-6-Reset system"
           "-7-Quit Program"
           "===>Enter choice: ");
    pinput = fgets(input, buffer, stdin);
    strtok(pinput, "\n");
    choice = atoi(pinput);
    return choice;
} // End menu()

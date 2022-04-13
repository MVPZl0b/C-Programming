#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
/*
Author: Zackery Bellerose
Date: 4-12-22
Description:  This program will allow users to create and store Dragracers.
*/
struct Dragracer
{
    char id[9];
    char make[25];
    double size;
    int horsepower;
    bool status;
} typedef Dragracer;

// buffer
#define buffer 80
// Prototypes:
int menu(int drcount);
void getDragracer(Dragracer *pcurrent);
void displayDragracer(Dragracer *pcurrent);
int searchDragracer(Dragracer *pdr, Dragracer *psearchID, int drCount);
bool getSupercharger(Dragracer *pcurrent);
int checkSuperCharger(Dragracer *pdr, int drcount);
void getLeaderboardReport(Dragracer *pdr, int drcount);

int main()
{
    // Variable Declarations:
    Dragracer *pdr = malloc(100 * sizeof(Dragracer));
    int option = 0;
    int drcount = 0;
    char input[buffer] = {' '};
    char *pinput = NULL;
    char searchID[9] = {' '};
    int foundAt = -1;
    while (option != 5)
    {
        option = menu(drcount);
        switch (option)
        {
        case 1: // Add a dragracer
            getDragracer(pdr + drcount);
            drcount++;
            break;
        case 2: // Display all dragracer
            for (int i = 0; i < drcount; i++)
            {
                displayDragracer(pdr + i);
            }
            break;
        case 3: // Search for a dragracer
            fflush(stdin);
            printf("Please enter the ID of the dragracer you want to seach for: ");
            pinput = fgets(input, buffer, stdin);
            strtok(pinput, "\n");
            strcpy(searchID, pinput);
            foundAt = searchDragracer(pdr, searchID, drcount);
            if (foundAt < 0)
            {
                printf("%s was not found in the database!\n", searchID);
            }
            else
            {
                displayDragracer(pdr + foundAt);
            }
            break;
        // Extra Credit: a,b,c
        case 4: // Leaderboard check. checks number of supercharger installs, biggest and smallest engines.
            getLeaderboardReport(pdr, drcount);
            break;
        case 5: // quit program.
            printf("\n\nAny key to continue...\n"); getch();
            printf("Goodbye!\n");
            break;
        default:
            printf("Wrong selection! Try again.\n");
            break;
        }
    }
    return 0;
} // end main

// Displays menu to select option.
int menu(int drcount)
{
    int option = 0;
    printf("\n");
    if (drcount > 0)
    {
        printf("-1-Add a Dragracer\n"
               "-2-Display all Dragracers\n"
               "-3-Search for a Dragracerby ID\n"
               "-4-Check leaderboard\n"
               "-5-Quit program\n"
               "Enter option 1-4: ");
    }
    else
    {
        printf("-1-Add a Dragracer\n"
               "-4-Quit program\n"
               "Enter option 1-4: ");
    }
    scanf("%d", &option);

    return option;
} // end menu

void getDragracer(Dragracer *pcurrent)
{
    char input[buffer] = {' '};
    char *pinput = NULL;
    fflush(stdin);
    printf("Please enter the dragracers ID: ");
    pinput = fgets(input, buffer, stdin);
    strtok(pinput, "\n");
    strcpy(pcurrent->id, pinput);
    printf("Please enter the dragracers Make: ");
    pinput = fgets(input, buffer, stdin);
    strtok(pinput, "\n");
    strcpy(pcurrent->make, pinput);
    printf("Please enter the dragracers Size: ");
    pinput = fgets(input, buffer, stdin);
    pcurrent->size = atof(pinput);
    printf("PLease enter the dragracers Horsepower: ");
    pinput = fgets(input, buffer, stdin);
    pcurrent->horsepower = atoi(pinput);
    pcurrent->status = getSupercharger(pcurrent);
} // end getDragracer

// Function to display a racecar's data.
void displayDragracer(Dragracer *pcurrent)
{
    printf("\nDragracer ID : %s\n"
           "          Make: %s\n"
           "          Size : %2.2f\n"
           "          Horsepower: %d\n"
           "          Install supercharger: %s",
           pcurrent->id, pcurrent->make, pcurrent->size, pcurrent->horsepower, pcurrent->status == 1 ? "Yes" : "No");
} // end displayDragracer

// Function to search for a dragracer. Inputs - pointer to drag struct, ID user is searching for, total dragracer count.
int searchDragracer(Dragracer *pdr, Dragracer *psearchID, int drCount)
{
    for (int i = 0; i < drCount; i++)
    {
        if (strcmp((pdr + i)->id, psearchID) == 0)
        {
            return i;
        }
    }
    return -1;
} // end searchRacecar

// Checks if a supercharger needs to be installed.
// Criterial for supercharger: size > 3; horsepower < 200
bool getSupercharger(Dragracer *pcurrent)
{
    if (pcurrent->horsepower < 200 && pcurrent->size > 3)
    {
        return true;
    }
    return false;
} // end getSupercharger

// Function checks number of drag racers who's engines are selected to have a supercharger installed.
int checkSuperCharger(Dragracer *pdr, int drcount)
{
    int count = 0;
    for (int i = 0; i < drcount; i++)
    {
        if ((pdr + i)->status == true)
            count++;
    }
    return count;
} // end checkSuperCharger

void getLeaderboardReport(Dragracer *pdr, int drcount)
{
    int smallest = 0;
    int biggest = 0;
    for (int i = 0; i < drcount; i++)
    {
        if (smallest = 0)
        {
            smallest = i;
        }
        //check for smallest engine. checks it against the stored id for smallest.
        if ((pdr + i)->horsepower < (pdr + smallest)->horsepower)
        {
            smallest = i;
        }
        //check for biggest engine. checks it against the stored id for biggest.
        if ((pdr + i)->horsepower > (pdr + smallest)->horsepower)
        {
            biggest = i;
        }
    }
    printf("----------------------------\n");
    printf("\t\t\tLeaderboard\n");
    printf("\t\tsmallest engine is: %d\n", (pdr + smallest)->horsepower);
    printf("\t\tbiggest is: %d\n", (pdr + biggest)->horsepower);
    printf("----------------------------\n");
    printf("The total superchargers selected to be installed: %d\n", checkSuperCharger(pdr, drcount));
} // end checkSuperCharger

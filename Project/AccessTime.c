#include <stdio.h>
#include <time.h>
#include <conio.h>
#define Length 256
int main()
{
    char buffer[Length] = " ";
    time_t currentTime;
    struct tm *local_time;
    printf("Any key to read the current time from the system...\n"); getch();
   currentTime = time(NULL);
    printf("Any key to convert the time from current to local...\n"); getch();
    local_time =  localtime(&currentTime);
    printf("Any key to show the time...\n"); getch();
    printf("Current time is: %s\n", asctime(local_time));
    printf("Any key to display Day of the week, Month, days in the month...\n "); getch();
    strftime(buffer, Length, "%A, %b, %d\n", local_time);
    printf(buffer);
    printf("Any key to display hours, minutes, second and PM or AM of a given day...\n "); getch();
    strftime(buffer, Length, "%I:%M:%S %p", local_time);
    printf(buffer);
    return 0;
}

#include <stdio.h>
#include <time.h>

int main()
{
   srand(time(0));
   int sensorValue = 0;
   double sensorActualValue = 0.0;
   int fraction = 0;

   for(int i = 0; i < 100; i++)
   {
       fraction = rand()%2;
       if(fraction == 1)
       {
            sensorValue = rand() % 2 + 1;
            sensorActualValue = sensorValue + .5;
       }//end if

       printf("Current value set in the sensor is: %2.2f\n", sensorActualValue);
   }//end for i
       return 0;
}

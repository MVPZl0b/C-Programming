#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/*
Author: Saylani
:Date: 4-24-22
Description: a demonstration of a struct of struct
*/

struct student
{
    double avg;
    struct course
    {
        double cost;
        int score;
    };
    struct course* pcourse;
}typedef student;
//prototypes:
void getStudent(student* pst, int current);
void getAVG(student* pst, int current);
void dispStudent(student* pst, int current);
int main()
{
    //declarations:
        //declare 3 students:
            student* pst = malloc(3*sizeof(student));//allocate memory for 3 students
            for(int i = 0; i < 3; i++)
            {
                (pst + i)->pcourse = malloc(sizeof((pst +i)->pcourse));//allocate memory for each of the courses the student has..here one course only
            }//end for i
    //input:
    printf("any key to start entering students...\n"); getch();
    for(int i = 0 ; i < 3;i++)
    {
        printf("Student#%d: \n", (i+1));
        getStudent(pst, i);
    }//end for i
    //calc avg
     printf("any key to start averaging scores...\n"); getch();
    for(int i = 0 ; i < 3;i++)
    {
        getAVG(pst, i);
    }//end for i
    //output:
     printf("any key to display all students...\n"); getch();
    for(int i = 0 ; i < 3;i++)
    {
        dispStudent(pst, i);
    }//end for i

    return 0;
}//end main
//========================================================
void getStudent(student* pst, int current)
{
    // (pst + current)->pcourse = malloc((pst + current)->pcourse);
     char input[80] = " ";
     char* pinput = NULL;
     printf("Enter this course cost: ");
     pinput = fgets(input, 80, stdin);
     //validate
     (pst + current)->pcourse->cost = atof(pinput);
     printf("Enter this course score: ");
     pinput = fgets(input, 80, stdin);
     //validate
     (pst + current)->pcourse->score = atoi(pinput);
}//end getStudent
//==========================================================
void getAVG(student* pst, int current)
{
    (pst + current)->avg = (pst + current)->pcourse->score;
}//end getAVG
//==========================================================
void dispStudent(student* pst, int current)
{
    printf("This student AVG: %2.2f\n"
           "             Course Cost: %2.2f\n"
           "             Score in this course: %d\n",
           (pst + current)->avg, (pst + current)->pcourse->cost, (pst + current)->pcourse->score);
}//end dispStudent
//=========================================================

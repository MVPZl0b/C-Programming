#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/*
Author: Saylani
:Date: 4-24-22
Description: a demonstration of a struct of struct: now, we got an array of struct of students and related array of struct of courses
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
void getStudent(student* pst, int current, int numberOfCourses);
void getAVG(student* pst, int current, int numberOfCourses);
void dispStudent(student* pst, int current, int numberOfCourses);
int main()
{
    //declarations:
        //declare 3 students:
            student* pst = malloc(3*sizeof(student));//allocate memory for 3 students
            int numberOfCourses = 0;
            printf("How many courses each student MUST be registered in? ");
            scanf("%d", &numberOfCourses);
            for(int i = 0; i < 3; i++)
            {
                (pst + i)->pcourse = malloc(numberOfCourses*sizeof((pst + i)->pcourse));//allocate memory for each of the courses the student is taking..each is taking 2
            }//end for i
    //input:
    printf("any key to start entering students...\n"); getch();
    for(int i = 0 ; i < 3;i++)
    {
        printf("Student#%d: \n", (i+1));
        getStudent(pst, i, numberOfCourses);
    }//end for i
    //calc avg
     printf("any key to start averaging scores...\n"); getch();
    for(int i = 0 ; i < 3;i++)
    {
        getAVG(pst, i,numberOfCourses);
    }//end for i
    //output:
     printf("any key to display all students...\n"); getch();
    for(int i = 0 ; i < 3;i++)
    {
        dispStudent(pst, i, numberOfCourses);
    }//end for i

    return 0;
}//end main
//========================================================
void getStudent(student* pst, int current,int numberOfCourses)
{
     char input[80] = " ";
     char* pinput = NULL;
     printf("Course data for this students...number of courses: %d...any key to start...\n", numberOfCourses); getch();
     fflush(stdin);
     for(int i = 0 ; i< numberOfCourses; i++)
     {
         printf("Enter this course cost: ");
        pinput = fgets(input, 80, stdin);
        //validate
        (pst + current)->pcourse[i].cost = atof(pinput);
        printf("Enter this course score: ");
        pinput = fgets(input, 80, stdin);
        //validate
        (pst + current)->pcourse[i].score = atoi(pinput);
     }//end for int i
}//end getStudent
//==========================================================
void getAVG(student* pst, int current, int numberOfCourses)
{
    int totalScores = 0;
    for(int i = 0 ; i < numberOfCourses; i++)
        totalScores = totalScores + (pst + current)->pcourse[i].score;
    (pst + current)->avg = totalScores / numberOfCourses;
}//end getAVG
//==========================================================
void dispStudent(student* pst, int current, int numberOfCourses)
{
    printf("Courses taken by this students:\n");
    for(int i = 0; i < numberOfCourses; i++)
    {
        printf("Course#%d                        :"
               "             Course Cost         : %2.2f\n"
               "             Score in this course: %d\n",
            (i + 1), (pst + current)->pcourse[i].cost, (pst + current)->pcourse[i].score);
    }//end for i
    printf("Average of all courses for this student: %2.2f\n", (pst + current)->avg);
}//end dispStudent
//=========================================================

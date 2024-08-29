#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "ta.h"
//TA Helpign function . which is caled in TA Loop 

void help_student(int sleep_time, int waiting_students)
{
    printf("TA busy helping a student for %d second(s) - waiting student(s) = %d\n", sleep_time, waiting_students);
    sleep(sleep_time);
}


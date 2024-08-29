#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include "ta.h"
//student programming function which is called in student_loop

void programming(int lnumber, int sleep_time)
{
	printf("\tStudent %d programming for %d second(s)\n" , lnumber, sleep_time);
	

	sleep(sleep_time);

}
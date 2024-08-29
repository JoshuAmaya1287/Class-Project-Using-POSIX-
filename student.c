#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include "ta.h"


void* student_loop(void* param)
{
	int* lnumber = (int*)param;
	int sleep_time;
	int time_through_loop = 0; //time students are allowed to go back to the TA'S Office

	srand((unsigned)time(NULL));
	sleep_time = rand() % MAX_SLEEP_TIME + 1;

	/*

	*Start with a loop ,running thew integer varaible times_through_Loop
	* student programming for a short while and coming to the TA'S Office
	* aquire the mutex lock, goign to the TA'S office so waiting_students is increased by 1
	* if there is seatrs(s),modify any shared data(waiting students and singal the TA that a studnet is waitng (student takes a seat)
	* release the mutex lock
	* wait for the TA(semaphore)
	* [if no seats available at the time , the student would come back  later . Releas ethe Mutex lock]
	* Note a variable is being passed to the student loop , it is a good practifve to include return NULL,at the end of llloop



	*/


	while (time_through_loop < 1)
	{

		programming(*lnumber, sleep_time);//sleep	



		pthread_mutex_lock(&mutex_lock);//mutex lock,Acquiring the mutex

		if (waiting_students < NUM_OF_SEATS)
		{

			waiting_students++;

			printf("\tStudent %d takes a seat -- waiting students(s) = %d\n", *lnumber, waiting_students);

			sem_post(&students_sem);

			pthread_mutex_unlock(&mutex_lock);//release mutex lock  for the if statement if there are available seats

			sem_wait(&ta_sem); // wait for the TA

			time_through_loop++;
		}
		else
		{
			printf("\t Student %d will try later\n", *lnumber);//student id goes here

			pthread_mutex_unlock(&mutex_lock);//Release the mutex lock for the if statment if there are no available seats

		}




	}
	return NULL;
}
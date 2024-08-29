#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include "ta.h"



void* ta_loop(void* param)
{
	int i;
	int rem_student;
	//local varibable, store waiting_students Without holding the mutex_lock
	int sleep_time;
	//seed random generator
	srand((unsigned)time(NULL));



	/*



	*Start with a loop running indefimitely- while(i){}
	* TA Napping and waitnig fro students to visit - sem_wait()
	*  once a student arrives,aquire the mutex lock and modify  any shared data( waiting_Students)
	* release teh mutex lock when done
	* help the student for a short while (to sleep for a short while)
	*  afte rthe student is helped, signal any waiting students , if any that the TA is available -Sem_post()
	*



*/

	while (1)//PARTIALLY CORRECT,
	{

		sleep_time = rand() % MAX_SLEEP_TIME + 1;

		sem_wait(&students_sem);

		pthread_mutex_lock(&mutex_lock);//mutex lock

		rem_student = waiting_students--;

		pthread_mutex_unlock(&mutex_lock);

		help_student(sleep_time, rem_student);//sleep

		sem_post(&ta_sem);//signal the ta is available


		





	}
	return NULL;
	
}
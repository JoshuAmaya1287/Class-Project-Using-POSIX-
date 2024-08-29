#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "ta.h"

pthread_t ta;
pthread_t students[NUM_OF_STUDENTS];


void init()
{

	if (pthread_mutex_init(&mutex_lock, NULL) != 0)
		printf("%s\n", strerror(errno)); //COME BACK LATER

	//Note that this line has two folds: one is nitializing the mutex lock and error checking for the intializatiron 
	//we will this structure throughouyt

	 
	if ((sem_init(&ta_sem, 0,0) != 0))//Initial value (3rd parameter can be 0 or 1 )
		printf("Error Initializing TA semaphore");

	if ((sem_init(&students_sem, 0, 0 )!= 0))//REVIEW THISSSSS
		printf("Error Initializing Student semaphore");//INITIALIZE THE  student sem 

		waiting_students = 0;

	for (int i = 0; i < NUM_OF_STUDENTS; i++)
		student_id[i]=i;





	

}



int main(void)
{
	int i,j;
	init();

	//cRETAE THE TA Thread , MY JOB,REVIEW
	
	pthread_create(&ta,0, ta_loop, NULL);
		
	
		
	

	//Create the Student thread
	for (i = 0; i < NUM_OF_STUDENTS;i++)
	{
		 pthread_create(&students[i], 0, student_loop, (void*)&student_id[i]);
		 sleep(1); //delay the thread creatiung (and also tis include the parent thread as well )


		//Make sure that srandom seeds a different number , it seed differently every second 

	}
	//join the student threads(NEED A LOOP) use loop with pthreadjoin
	for (i = 0; i < NUM_OF_STUDENTS; i++)
	{
		pthread_join(students[i], NULL);//REVIEW THISSSS
	}
	
	if(pthread_cancel(ta) != 0)
		printf("%s\n", strerror(errno)); //COME BACK LATER
	
	//For  the TA threwad, you want to forcefully stop it using pthread_cancel(ta)
	

	return 0; 
	

	



}
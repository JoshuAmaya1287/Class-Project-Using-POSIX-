//Header file for the program

#include <pthread.h>
#include <semaphore.h>



//The max time in Seconds to sleep/program/help
#define MAX_SLEEP_TIME 5

//Number of max waiting students (# of seats)
#define MAX_WAITING_STUDENTS 3


//Number of potential students coming to the TA'S Office
#define NUM_OF_STUDENTS 5

//Number of available seat
#define NUM_OF_SEATS 3

//Declare semaphores
sem_t ta_sem;
sem_t students_sem;

pthread_mutex_t mutex_lock;

//The nymber of waiting students

int waiting_students;

//Students being served
int student_number;

//the numeric id for each student
int student_id[NUM_OF_STUDENTS];

//Student thread function 
void* student_loop(void* param);

//TA Thread function
void* ta_loop(void* param);

//Stimulate student programming

void programming(int lnumber, int sleep_time);

//Stimulate TA Helping a student
void help_student(int sleep_time, int waiting_students);
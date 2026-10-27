// Program to demonstrate semaphores

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void *my_thread(void *arg)
{
   //wait
   sem_wait(&mutex);

   printf("\nEntered...\n");

   //critical section
   sleep(4);
					
   //signal
   printf("\nExiting...\n");

   sem_post(&mutex);
}

int main()
{
    pthread_t t1,t2;

    sem_init(&mutex, 0, 1);

    pthread_create(&t1, NULL, my_thread, NULL);
	
    sleep(2);
	
    pthread_create(&t2, NULL, my_thread, NULL);
	
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
	
    sem_destroy(&mutex);
	
    return 0;
}	

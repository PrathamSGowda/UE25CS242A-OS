// Program to demo deadlock prevention by changing the order of resources being locked

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t tid1, tid2;
pthread_mutex_t mutex1,mutex2;


/* thread one runs this function */
void *thread1(void *param)
{
    pthread_mutex_lock(&mutex1);
    sleep(5);
    pthread_mutex_lock(&mutex2);

    printf("Entering thread 1 \n");
    sleep(5);
    printf("Exiting thread 1 \n");

    pthread_mutex_unlock(&mutex1);
    sleep(5);
    pthread_mutex_unlock(&mutex2);
    pthread_exit(0);
}

/* thread two runs this function */
void *thread2(void *param)
{
    pthread_mutex_lock(&mutex1);
    sleep(5);
    pthread_mutex_lock(&mutex2);
    
    printf("Entering thread 2 \n");
    sleep(5);
    printf("Exiting thread 2 \n");
 
    pthread_mutex_unlock(&mutex2);
    sleep(5);
    pthread_mutex_unlock(&mutex1);
    pthread_exit(0);
}

int main(void)
{

    int error;

    if (pthread_mutex_init(&mutex1, NULL) != 0) 
    {
       printf("\n first mutex init has failed\n");
       return 1;
    }

    if (pthread_mutex_init(&mutex2, NULL) != 0) 
    {
       printf("\n second mutex init has failed\n");
       return 1;
    }

    error = pthread_create(&tid1, NULL, &thread1, NULL);
       
    if (error != 0)
       printf("\n First thread can't be created :[%s]", strerror(error));
							
    error = pthread_create(&tid2, NULL, &thread2, NULL);
       
    if (error != 0)
       printf("\n Second thread can't be created :[%s]", strerror(error));
 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global variable - shared by all threads
int g = 0;

// Thread function
void *myThreadFunction(void *vargp)
{
  int myid = *(int *)vargp;
  
  // Static variable - shared by all threads
  static int s = 0;
  
  // Local variable - private to each thread
  int l = 0;
  
  // Change local, static and global variable
  ++l;
  ++s;
  ++g;
  
  printf("Thread ID: %d, Local: %d, Static: %d, GLobal: %d\n", myid, l, s, g);
  
  pthread_exit(NULL);
}

int main()
{
  int i;
  pthread_t tid[3];
  
  // Create three threads
  for(i = 0; i < 3; i++)
  {
    pthread_create(&tid[i], NULL, myThreadFunction, &i);
    pthread_join(tid[i], NULL);
  }
  
  printf("In main()\n");
  
  return 0;
}

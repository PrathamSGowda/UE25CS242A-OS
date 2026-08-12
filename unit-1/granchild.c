#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
  pid_t p1, p2;
  int y = 0;
  p1 = fork();
  if(p1>0) // code is executing in parent process
  {
    y = y-1;
    printf("This is parent. Process ID = %d, y = %d\n", getpid(),y);
  }
  else if(p1==0) // code is executing in child process
  {
    p2 = fork();
    if(p2>0)
    {
      wait(NULL);
    }
    else if(p2==0)
    {
      y = y+5;
      printf("This is grandchild. Process ID = %d, Parent Process ID = %d, y = %d\n", getpid(),getppid(),y);
      exit(0);
    }
    y = y+1;
    printf("This is child. Process ID = %d, Parent Process ID = %d, y = %d\n", getpid(),getppid(),y);
  }
  else // fork failed
    printf("fork creation failed..\n");
}

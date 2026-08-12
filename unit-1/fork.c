// program to demonstrate fork() and show how parent and child have independent copies of same variable y

#include <stdio.h>
#include <unistd.h>
int main()
{
  pid_t p1;
  int y = 0;
  p1 = fork();
  if(p1>0) // code is executing in parent process
  {
    y = y-1;
    printf("This is parent. Process ID = %d, y = %d\n", getpid(),y);
  }
  else if(p1==0) // code is executing in child process
  {
    y = y+1;
    printf("This is child. Process ID = %d, Parent Process ID = %d, y = %d\n", getpid(),getppid(),y);
  }
  else // fork failed
    printf("fork creation failed..\n");
}

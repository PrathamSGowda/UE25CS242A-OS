#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  pid_t pid = fork();
  if(pid>0)
  {
    printf("This is parent. Process ID = %d\n", getpid());
    exit(0);
  }
  else if(pid==0)
  {
    sleep(15);
    printf("This is child. Process ID = %d, Parent Process ID = %d\n", getpid(),getppid());
  }
}

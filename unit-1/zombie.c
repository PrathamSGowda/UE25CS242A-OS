#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
  pid_t pid = fork();
  if(pid>0)
  {
    sleep(10);
    printf("In parent\n");
  }
  else if(pid == 0)
  {
    printf("In child\n");
    exit(0);
  }
}

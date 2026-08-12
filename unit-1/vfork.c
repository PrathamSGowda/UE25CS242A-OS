#include <stdio.h>
#include <unistd.h>

int main()
{
  pid_t p1;
  int i = 0, y = 0;
  p1 = vfork();
  if(p1>0)
  {
    for(i=0;i<5;i++)
    {
      sleep(i);
      y= y-1;
      printf("This is parent. Process ID = %d, y = %d\n", getpid(),y);
    }
  }
  else if(p1==0)
  {
    for(i=0; i<5; i++)
    {
      sleep(i);
      y = y+1;
      printf("This is child. Process ID = %d, Parent Process ID = %d, y = %d\n", getpid(),getppid(),y);
    }
    _exit(0);
  }
  else
    printf("fork creation failed...\n");
}

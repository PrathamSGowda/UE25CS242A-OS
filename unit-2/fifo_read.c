#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100

int main()
{
  int fd1;
  char buff[BUFFER_SIZE] = "";
  
  char myfifo[BUFFER_SIZE] = "/tmp/myfifo";
  
  mkfifo(myfifo, 0666);
  
  fd1 = open(myfifo, O_RDONLY);
  read(fd1, buff, BUFFER_SIZE);
  
  printf("Information read: %s", buff);
  close(fd1);
  
  return 0;
}
  

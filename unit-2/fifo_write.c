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
  int fd;
  char buff[BUFFER_SIZE] = "";
  
  char myfifo[BUFFER_SIZE] = "/tmp/myfifo";
  
  printf("Enter the message to be passed\n");
  read(0, buff, BUFFER_SIZE);
  
  mkfifo(myfifo, 0666);
  
  fd = open(myfifo, O_WRONLY);
  
  write(fd, buff, strlen(buff)+1);
  close(fd);
  
  sleep(10);
  return 0;
}

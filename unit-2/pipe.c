#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100
#define READ_END 0
#define WRITE_END 1

int main()
{
  char write_msg[BUFFER_SIZE] = "Greetings from parent process\n";
  char read_msg[BUFFER_SIZE] = " ";
  
  int fd[2];
  pid_t P1;

  if(pipe(fd) == -1)
  {
    printf("pipe creation failed\n");
    return 1;
  }
  
  P1 = fork();
  if(P1>0)
  {
    close(fd[READ_END]);
    write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
    close(fd[WRITE_END]);
    wait(NULL);
  }
  
  else if(P1 == 0)
  {
    close(fd[WRITE_END]);
    read(fd[READ_END], read_msg, BUFFER_SIZE);
    printf("Message from parent : ** %s ** \n", read_msg);
    close(fd[READ_END]);
  }
  
  else
    printf("fork creation failed\n");
}

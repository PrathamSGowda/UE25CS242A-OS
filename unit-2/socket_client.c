#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "/tmp/mysocket"

int main()
{
  int sockfd;
  struct sockaddr_un addr;
  char buffer[100];
  
  sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
  
  addr.sun_family = AF_UNIX;
  strcpy(addr.sun_path, SOCKET_PATH);
  
  connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  
  strcpy(buffer, "Hello Server");
  write(sockfd, buffer, strlen(buffer) + 1);
  
  read(sockfd, buffer, sizeof(buffer));
  printf("Reply from server: %s\n",buffer);
  
  close(sockfd);
  return 0;
}

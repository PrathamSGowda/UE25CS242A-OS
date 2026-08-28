#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "/tmp/mysocket"

int main()
{
  int server_fd, client_fd;
  struct sockaddr_un addr;
  
  char buffer[100];
  
  // create socket
  server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
  
  // configure socket address
  addr.sun_family = AF_UNIX;
  
  strcpy(addr.sun_path, SOCKET_PATH);
  
  // remove old socket file if it exists
  unlink(SOCKET_PATH);
  
  // bind socket
  bind(server_fd, (struct sockaddr *)&addr, sizeof(addr));
  
  // listen for client
  listen(server_fd, 5);
  
  printf("Server is waiting..\n");
  
  client_fd = accept(server_fd, NULL, NULL);
  
  read(client_fd, buffer, sizeof(buffer));
  printf("Message from client: %s\n", buffer);
  
  strcpy(buffer, "Hello CLient");
  write(client_fd, buffer, strlen(buffer) + 1);
  
  close(client_fd);
  close(server_fd);
  
  unlink(SOCKET_PATH);
  
  return 0;
}

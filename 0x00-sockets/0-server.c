#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12345
#define SIZE 1024
#define BACKLOG 10

/**
  * main - program entry point
  *
  * Return: 0 on success and 1 or -1 on failure
  */
int main(void)
{
	int socket_acccept;

	int socket_fd = socket(
		AF_INET,
		SOCK_STREAM,
		0
	);
	struct sockaddr_in server_address;

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	server_address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	bind(
		socket_fd,
		(struct sockaddr *)&server_address,
		sizeof(server_address)
	);
	while (1)
	{
		int listener = listen(socket_fd,BACKLOG);
		if (listener < 0)
		{
			printf("Error: unable to listen on %i, error %i", PORT, errno);
			return (-1);
		}
		socket_acccept = accept(socket_fd, NULL, NULL);

		close(socket_acccept);
	}
	return (0);
}

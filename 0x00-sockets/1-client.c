#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12345
#define BACKLOG 10

/**
 *
 *
 *
 */
int main(void)
{
	int socket_accept;

	int socket_fd = socket(AF_INET,	SOCK_STREAM, 0);

	struct sockaddr_in server_t;

	server_t.sin_family = AF_INET;
	server_t.sin_port = htons(PORT);
	server_t.sin_addr.s_addr = INADDR_ANY;

	if (bind(socket_fd, (struct sockaddr *)&server_t,sizeof(server_t)) == -1)
	{
		printf("Failed to bind socket: %s\n", strerror(errno));
		return (-1);
	}

	while (1)
	{
		int listener = listen(socket_fd, BACKLOG);
		if (!listener)
		{
			printf("Error: Unable to listen on %i - %s\n", PORT, strerror(errno));
			return (-1);
		}
		socket_acccept = accept4(socket_fd, (struct sockaddr *)&server_t, sizeof(server_t, EFAULT));
		if (!socket_acccept)
		{
			printf("Error: Unable to accept socket on %i - %s\n", PORT, strerror(errno));
			return (-1);
		}
		
		close(socket_accept);
	}
	return (0);

}
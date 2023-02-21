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
#define BACKLOG 10
/**
 * main - main entry point
 *
 * Return: 0 on success, 1 or -1 on failure
 */
int main(void)
{
	int server_socket, client_socket;
	struct sockaddr_in server_getaddrinfo;
	struct sockaddr_in client_getaddrinfo;
	unsigned int client_length;

	if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		errno = EINVAL;
		printf("socket error on %d\n", server_socket);
		if (errno != EINPROGRESS)
			printf("error creating socket: %s\n", strerror(errno));
	}

	memset(&server_getaddrinfo, 0, sizeof(server_getaddrinfo));
	server_getaddrinfo.sin_family = AF_INET;
	server_getaddrinfo.sin_addr.s_addr = htonl(INADDR_ANY);
	server_getaddrinfo.sin_port = htons(PORT);

	if (bind(server_socket, (struct sockaddr *)&server_getaddrinfo, sizeof(server_getaddrinfo)) < 0)
	{
		errno = EINVAL;
		printf("Couldn't bind to server socket %d\n", server_getaddrinfo.sin_addr.s_addr);
		if (errno != EINVAL)
			printf("error: %s\n", strerror(errno));
	}

	if (listen(server_socket, BACKLOG) < 0)
	{
		errno = EINVAL;
		printf("Couldn't listen to server socket %d\n", server_socket);
		if (errno != EINVAL)
			printf("Error %s\n", strerror(errno));
		return (-1);
	}

	for (;;)
	{
		client_length = sizeof(server_getaddrinfo);

		if ((client_socket = accept(server_socket, (struct sockaddr *)&server_getaddrinfo, &client_length)) < 0)
		{
			perror("accept failed");
			return (-1);

		}

		printf("Client IP address: %s\n", inet_ntoa(client_getaddrinfo.sin_addr));

		
	}


}

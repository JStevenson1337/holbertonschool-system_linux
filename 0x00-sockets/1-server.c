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

	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	if (server_socket < 0)
	{
		perror("socket error: %s", strerror(errno));
	}
	memset(&server_getaddrinfo, 0, sizeof(server_getaddrinfo));
	server_getaddrinfo.sin_family = AF_INET;
	server_getaddrinfo.sin_addr.s_addr = htonl(INADDR_ANY);
	server_getaddrinfo.sin_port = htons(PORT);
	if (bind(server_socket,
		(struct sockaddr *)&server_getaddrinfo,
		sizeof(server_getaddrinfo)) < 0)
	{
		perror("bind error: %s", strerror(errno));
	}
	if (listen(server_socket, BACKLOG) < 0)
	{
		perror("listen error: %s", strerror(errno));
		return (-1);
	}
	for (;;)
	{
		client_length = sizeof(server_getaddrinfo);
		client_socket = accept(server_socket,
		(struct sockaddr *)&server_getaddrinfo,
		&client_length);
		if (client_socket < 0)
		{
			perror("accept error: %s", strerror(errno));
			return (-1);
		}
		printf("Client IP address: %s\n", inet_ntoa(client_getaddrinfo.sin_addr));
	}
}

#include "rest_api.h"
#define SOCKET_SIZE sizeof(*(my_socket->addr))
/**
 * create_socket - creates a new socket
 * @domain: domain of the socket
 * @type: type of the socket
 * @protocol: protocol of the socket
 *
 * Return: socket file descriptor or -1 in failure
 */
int create_socket(int domain, int type, int protocol)
{
	int socket_fd = 0;
	int opt = 1;
	int result = 0;

	socket_fd = socket(domain, type, protocol);
	if (socket_fd == -1)
	{
		printf("Socket error %s\n", strerror(errno));
		return (-1);
	}
	result = setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	if (result == -1)
	{
		printf("Option error %s\n", strerror(errno));
		return (-1);
	}
	return (socket_fd);
}

/**
 * bind_listen_socket - socket binds and listen to specific port
 * @my_socket: structure with the socket information
 *
 * Return: 1 on success 0 on failure
 */
int bind_listen_socket(socket_params *my_socket)
{
	my_socket->addr->sin_family = AF_INET;
	my_socket->addr->sin_port = htons(my_socket->port);
	my_socket->addr->sin_addr.s_addr = inet_addr(my_socket->ip_addr);
	if (bind(my_socket->fd, (sockaddr *)(my_socket->addr), SOCKET_SIZE) == -1)
	{
		printf("Binding error %s\n", strerror(errno));
		return (0);
	}
	if (listen(my_socket->fd, 132) == -1)
	{
		printf("Listen error %s\n", strerror(errno));
		return (0);
	}
	printf("Server listening on port %d\n", my_socket->port);
	return (1);
}

/**
 * accept_connection - accepts connections from a socket
 * @my_socket: server socket
 * @my_client: client socket
 * Return: 1 on success 0 on failure
 */
int accept_connection(socket_params *my_socket, socket_params *my_client)
{
	socklen_t client_size;
	char *client_address;
	int fd;

	client_size = sizeof(my_client->addr);
	fd = my_socket->fd;
	my_client->fd = accept(fd, (sockaddr *) (my_client->addr), &client_size);
	if (my_client->fd == -1)
	{
		printf("Accept error %s\n", strerror(errno));
		return (0);
	}
	client_address = inet_ntoa(my_client->addr->sin_addr);
	printf("Client connected: %s\n", client_address);
	return (1);
}

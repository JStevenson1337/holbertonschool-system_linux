#include "sockets.h"

/**
 * print_error_and_exit - self explanatory
 * @str: program to print error for
 * Return: 0
 */
int print_error_and_exit(char *str)
{
	printf("%s: %s", str, strerror(errno));
	return (EXIT_FAILURE);
}

/**
 * recieve_message_from_socket - receive a message from a socket
 * @sockfd: socket to recieve message from
 * Return: number of bytes, or -1
 */
int recieve_message_from_socket(int sockfd)
{
	ssize_t bytes;
	char message[BYTES_READ];

	bytes = recv(sockfd, message, BYTES_READ, 0);

	if (bytes > 0)
	{
		message[bytes] = 0;
		printf("Message received: \"%s\"\n", message);
	}

	close(sockfd);
	return (EXIT_SUCCESS);

}

/**
 * accept_socket - accept an entereing connection, prints the IP address
 *                 of the connected client
 * @socket: socket to accept connection
 * Return: new socket, or -1 on failure
 */
int accept_socket(int socket)
{
	int new_socket;
	struct sockaddr_in address;
	socklen_t address_len;

	address_len = sizeof(address);
	new_socket = accept(socket,
			(struct sockaddr *)&address, (socklen_t *)&address_len);

	if (new_socket == -1)
		print_error_and_exit("accept");

	printf("Client connected: %s\n", inet_ntoa(address.sin_addr));
	return (new_socket);
}

/**
 * bind_socket - assigns a name to a socket
 * @socket: socket to assign address (name)
 * Return: 0 on success, -1 on failure
 */
int bind_socket(int socket)
{
	int bin;
	struct sockaddr_in addr;

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(PORT);
	bin = bind(socket, (struct sockaddr *)&addr, sizeof(addr));

	if (bin == -1)
		print_error_and_exit("bind");

	return (bin);
}

/**
 * main - opens an IPv4/TCP socket, and listens to traffic on port 12345
 * Return: int
 */
int main(void)
{
	int socket_fd, socket_accepted;

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	if (socket_fd == -1)
		print_error_and_exit("socket");

	bind_socket(socket_fd);

	if (listen(socket_fd, 1) == -1)
		print_error_and_exit("listen");

	printf("Server listening on port %d\n", PORT);

	socket_accepted = accept_socket(socket_fd);

	if (recieve_message_from_socket(socket_accepted) == -1)
		print_error_and_exit("recv");

	close(socket_fd);
	close(socket_accepted);
	return (EXIT_SUCCESS);

}

#include "server_API.h"


int spinup_server(void)
{
	struct sockaddr_in server_address;
	int fd_server_socket;

	setbuf(stdout, NULL);
	fd_server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (fd_server_socket < 0)
	{
		perror("Socket create failed:");
		return(EXIT_FAILURE);
	}

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(fd_server_socket,
		(struct sockaddr *)&server_address,
		sizeof(server_address))
		< 0)
	{
		perror("Bind failed:");
		return(EXIT_SUCCESS);
	}

	if (listen(fd_server_socket, 8) < 0)
	{
		perror("Listen failed:");
		return(EXIT_FAILURE);
	}

	printf("Server listening on port %d\n", ntohs(server_address.sin_port));

	while (1)
		accept_connection(fd_server_socket, server_address);
	
	close(fd_server_socket);
}

int accept_connection(int fd_server_socket, struct sockaddr_in server_address)
{
	int fd_client_socket, addrlen = sizeof(server_address);

	fd_client_socket = accept(fd_server_socket,
				(struct sockaddr *)&server_address,
				(socklen_t*)&addrlen);

	if (fd_client_socket < 0)
	{
		perror("failed to accept");
		return(EXIT_FAILURE);
	}

	printf("Client connected: %s\n", inet_ntoa(server_address.sin_addr));
	break_print_request(fd_client_socket);
	close(fd_client_socket);
	return (EXIT_SUCCESS);
}

int send_message(int fd_client_socket)
{
	char *message = "HTTP/1.1 200 OK\n";

	send(fd_client_socket, message, strlen(message), 0);
	return (0);
}
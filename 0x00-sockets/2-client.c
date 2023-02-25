#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char **argv)
{
	ushort port;
	char *host;
	struct sockaddr_in server_getaddrinfo,
						client_getaddrinfo;
	unsigned int client_length;
	int connector, connection_string;
	struct in_addr
	{
		unsigned long s_addr;
	}

	if (argc < 2)
	{
		printf("Usage: %s <host> <port>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	*host = argv[1];
	port = atoi(argv[2]);

	// create_socket(host, port)

	client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (!client_socket)
	{
		perror("socket");
		return (EXIT_FAILURE);
	}

	echo_server_address.sin_family = AF_INET;
	echo_server_address.sin_addr.s_addr = 
		inet_addr(echo_server_address.sin_addr.s_addr);
	echo_server_address.sin_port = htons(echoServPort);

	connect(client_socket,
			(struct sockaddr *)&echo_server_address,
			sizeof(echo_server_address));

	if (connect != 0)
	{
		perror("connect");
		return (EXIT_FAILURE);
	}

	for (;;)
	{
		echo_string_length = strlen(echo_string);

		send(client_socket, echoString,
			echo_string_length, 0);
		if (send == -1)
		{
			perror("send");
			perror("errno(send)");
		}
	}






}
#include <asm-generic/socket.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/wait.h>
#define PORT 12345






int main()
{
	int net_socket, listen_server;


	net_socket = socket(AF_INET, SOCK_STREAM, SO_KEEPALIVE);

	while (1)
	{
		listen_server = listen(net_socket, 99);
		if (listen_server == -1)
		{
			printf("%c", errno);
			return (-1);

		}


	}
	return (0);

}

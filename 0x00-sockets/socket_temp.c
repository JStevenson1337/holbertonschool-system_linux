#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>



// Usual socket headers
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <arpa/inet.h>
#define PORT 12345
#define SIZE 1024
#define BACKLOG 10  // Passed to listen()


/**
 * TODO: Create socket with socket() call
 * TODO: bind() this to an IP and port where it can
 * TODO: listen() for connections, then
 * TODO: accept() connection
 */



 /**
  * main - program entry point
  *
  * Return: 0 on success and 1 or -1 on failure
  */
int main(void)
{
	int socket_acccept;
	/* Socket Setup: Create socket endpoint for communication, returns a descriptor */
	/***********************************************************************/
	int socket_fd = socket(
		AF_INET, /* Domain: Specifies Protocol Family */
		SOCK_STREAM, /* Type: specifies commnuication semantics */
		0 /* Protocol: 0 because a single protocol for the family */
	);

	/* Construct Local address structure*/
	/**********************************************************************/
	/*
	TODO: Gather more information about socket structure and socket function pointers
	*/
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	/* inet_addr("127.0.0.1")*/
	server_address.sin_addr.s_addr =htonl(INADDR_LOOPBACK);

	/* Bind socket to local address */
	/*******************************************************************/

	/* bind() assigns the address to the socket */
	/* referred to by the file descriptor socket_fd*/

	bind(
		socket_fd, /* fd referring to a socket */
		(struct sockaddr *)&server_address, /* address to be assigned to the socket */
		sizeof(server_address) /* Size (bytes) of the address structure */
	);

	/* Set the scoket to listen for incoming commections */
	/******************************************************/

	int listener = listen(
		socket_fd, /* fd referring to a socket */
		BACKLOG /* # of holding connections */
	);

	if (listener < 0)
	{
		printf("Error: unable to listen on port %i, error %i", PORT, errno);
		return (-1);
	}

	/* Wait for connection */
	/********************************************************/
	while(1)
	{
		socket_acccept = accept(socket_fd, NULL, NULL);
		close(socket_acccept);
	}
	return (0);
}
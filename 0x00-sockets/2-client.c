#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	struct addrinfo hints;
    struct addrinfo *result, *rp;
    struct sockaddr_in *sa;
    int s;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    s = atoi(argv[1]);
    if (s <= 0 || s > 65535) {
        fprintf(stderr, "Invalid port: %s\n", argv[1]);
        exit(1);
    }

    sa = calloc(1, sizeof(struct sockaddr_in));
	if (!sa) {
        perror("calloc");
        exit(1);
    }
	sa->sin_family = AF_INET;
	sa->sin_port = htons(s);
	sa->sin_addr.s_addr = htonl(INADDR_ANY);

	result = NULL;
	errno = 0;
	s = getaddrinfo(argv[0], argv[1], &hints, &result);
	if (s!= 0) {
        perror("getaddrinfo");
        exit(1);
    }
	rp = result;
	while (rp) {
        printf("%s:%s\n", rp->ai_canonname, rp->ai_addr->sa_data);
        rp = rp->ai_next;
    }
	freeaddrinfo(result);
	exit(0);
	return 0;
}
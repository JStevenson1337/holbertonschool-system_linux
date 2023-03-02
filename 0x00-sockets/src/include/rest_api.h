#ifndef _REST_API_H_
#define _REST_API_H_

#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>

#define MSG_LEN 8192

/*HTTP RESPONSES*/
#define OK_RESPONSE "HTTP/1.1 200 OK\r\n"
#define BAD_RESPONSE "HTTP/1.1 404 Not Found\r\n\r\n"
#define NO_CONTENT_RESPONSE "HTTP/1.1 204 No Content\r\n\r\n"
#define UNPROCCESABLE_RESPONSE "HTTP/1.1 422 Unprocessable Entity\r\n\r\n"
#define CREATED_RESPONSE "HTTP/1.1 201 Created\r\n"
#define LENGTH_REQ_RESPONSE "HTTP/1.1 411 Length Required\r\n\r\n"

/**
 * struct socket_params - socket neccesary params
 * @fd: socket file descriptor
 * @port: socket port
 * @ip_addr: socket ip address
 * @addr: socket data structure
 *
 * Description: This structure give us input arguments
 * to use sockets - for Holberton project
 */
typedef struct socket_params
{
	int fd;
	int port;
	char *ip_addr;
	struct sockaddr_in *addr;
} socket_params;

/**
 * struct response_parse - stores the HTTP response params
 * @method: stores the method of the HTTP request
 * @path: stores the path to be used
 * @version: stores the version
 *
 * Description: This structure give us input arguments
 * to use sockets - for Holberton project
 */
typedef struct response_parse
{
	char *method;
	char *path;
	char *version;
} response_parse;

/**
 * struct query_data - stores queries with name and value
 * @name: querie name
 * @value: querie value
 *
 * Description: Used to store query values
 * to use sockets - for Holberton project
 */
typedef struct query_data
{
	char *name;
	char *value;
} query_data;


/**
 * struct todo - creates a todo task
 * @id: task id
 * @title: task title
 * @description: task description
 */
typedef struct todo
{
	int id;
	char title[100];
	char description[100];
} todo_task;

typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;

int create_socket(int domain, int type, int protocol);
int bind_listen_socket(socket_params *my_socket);
int accept_connection(socket_params *my_socket, socket_params *my_client);
int parse_message(char message[], response_parse *response);
int free_response(response_parse *response);
query_data **parse_queries(char message[], int *num_queries);
void free_query(query_data **query, int query_len);
query_data **parse_headers(char message[], int *num_headers);
query_data **parse_body(char message[], int *num_body);
char *get_key_value(char *key, query_data **structure, int struct_len);
char *parse_response(char message[], response_parse *response);
char *create_todo(char message[]);
char *get_todos();
char *get_todo(int id);
char *delete_todo(int id);
#endif /* REST_API_H */

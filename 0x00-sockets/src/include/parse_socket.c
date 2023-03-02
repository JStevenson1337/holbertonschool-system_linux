#include "rest_api.h"
#define TOKEN " \t\r\n"
/**
 * parse_message - extracts information from socket message
 * @message: full message
 * @response: line to scan
 *
 * Return: 1 on success 0 on failure
 */
int parse_message(char message[], response_parse *response)
{
	char cpy_message[MSG_LEN];
	char *method, *path, *version;

	if (!strcpy(cpy_message, message))
		return (0);
	method = strtok(cpy_message, TOKEN);
	response->method = calloc(strlen(method) + 1, 1);
	strcpy(response->method, method);
	path = strtok(NULL, TOKEN);
	response->path = calloc(strlen(path) + 1, 1);
	strcpy(response->path, path);
	version = strtok(NULL, TOKEN);
	response->version = calloc(strlen(version) + 1, 1);
	strcpy(response->version, version);
	return (1);
}

/**
 * free_response - frees the memory for a response
 * @response: structure with the response
 *
 * Return: 1 on success
 */
int free_response(response_parse *response)
{
	free(response->method);
	free(response->path);
	free(response->version);
	return (1);
}

/**
 * parse_queries - parse queries from the URL
 * @message: pointer of pointer with the strings
 * @num_queries: number of queries
 *
 * Return: 1 on success 0 on error
 */
query_data **parse_queries(char message[], int *num_queries)
{
	int i = 0;
	char *equal_position, *value;
	int index = 0;
	char cpy_message[MSG_LEN];
	query_data **querie = NULL;

	if (!strcpy(cpy_message, message))
		return (NULL);
	cpy_message[strlen(message)] = '\0';
	*num_queries = 0;
	while (cpy_message[i++])
	{
		if (cpy_message[i] == '?' || cpy_message[i] == '&')
		{
			(*num_queries)++;
		}
	}
	if (!*num_queries)
		return (NULL);
	strtok(cpy_message, "?");
	querie = calloc((*num_queries) + 1, sizeof(query_data *));
	if (!querie)
		return (NULL);
	for (i = 0; i < *num_queries; i++)
	{
		value = strtok(NULL, "?&");
		equal_position = strchr(value, '=');
		index = (int)(equal_position - value);
		querie[i] = malloc(sizeof(query_data));
		querie[i]->name = calloc(index + 1, 1);
		querie[i]->value = calloc(strlen(value) - index + 1, 1);
		strncpy(querie[i]->name, value, index);
		strcpy(querie[i]->value, value + index + 1);
	}
	return (querie);
}

/**
 * free_query - parse queries from the URL
 * @query: pointer of pointer with the strings
 * @query_len: number of queries
 *
 * Return: 1 on success 0 on error
 */
void free_query(query_data **query, int query_len)
{
	int i;

	for (i = 0; i < query_len; i++)
	{
		free(query[i]->name);
		free(query[i]->value);
		free(query[i]);
	}
	free(query);
}

/**
 * parse_headers - parse headers from the response
 * @message: pointer of pointer with the strings
 * @num_headers: number of headers
 *
 * Return: 1 on success 0 on error
 */
query_data **parse_headers(char message[], int *num_headers)
{
	int i = 0;
	char *equal_position, *value;
	int index = 0;
	char cpy_message[MSG_LEN];
	query_data **querie = NULL;

	if (!strcpy(cpy_message, message))
		return (NULL);
	cpy_message[strlen(message)] = '\0';
	*num_headers = 0;
	while (cpy_message[i++])
	{
		if (cpy_message[i] == ':')
		{
			(*num_headers)++;
		}
	}
	if (!*num_headers)
		return (NULL);
	(*num_headers)--;
	strtok(cpy_message, "\r\n");
	querie = calloc((*num_headers) + 1, sizeof(query_data *));
	if (!querie)
		return (NULL);
	for (i = 0; i < *num_headers; i++)
	{
		value = strtok(NULL, "\r\n");
		equal_position = strchr(value, ':');
		if (!equal_position)
			break;
		index = (int)(equal_position - value);
		querie[i] = malloc(sizeof(query_data));
		querie[i]->name = calloc(index + 1, 1);
		querie[i]->value = calloc(strlen(value) - index, 1);
		strncpy(querie[i]->name, value, index);
		strcpy(querie[i]->value, value + index + 2);
	}
	return (querie);
}

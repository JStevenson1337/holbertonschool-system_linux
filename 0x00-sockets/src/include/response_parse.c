#include "rest_api.h"
#define TOKEN " \t\r\n"
/**
 * parse_response - gets what to do with the response method & path
 * @message: full message
 * @response: line to scan
 *
 * Return: 1 on success 0 on failure
 */
char *parse_response(char message[], response_parse *response)
{
	char path[MSG_LEN];
	char *filtered_path = NULL;
	query_data **query = NULL;
	int num_queries = 0;
	char *id = NULL;

	query = parse_queries(response->path, &num_queries);
	id = get_key_value("id", query, num_queries);
	strcpy(path, response->path);
	filtered_path = strtok(path, "?");
	if (strcmp(filtered_path, "/todos") == 0 && id)
	{
		if (strcmp(response->method, "GET") == 0)
			return (get_todo(atoi(id)));
		else if (strcmp(response->method, "DELETE") == 0)
			return (delete_todo(atoi(id)));
	}
	else if (strcmp(filtered_path, "/todos") == 0)
	{
		if (strcmp(response->method, "POST") == 0)
			return (create_todo(message));
		else if (strcmp(response->method, "GET") == 0)
			return (get_todos());
		return (BAD_RESPONSE);
	}
	return (BAD_RESPONSE);
}

/**
 * get_key_value - gets the value of the desired key
 * @key: Key used to get the value
 * @structure: query names and data
 * @struct_len: len
 * Return: value on success or null if not found
 */
char *get_key_value(char *key, query_data **structure, int struct_len)
{
	int i = 0;

	for (i = 0; i < struct_len; i++)
	{
		if (strcmp(structure[i]->name, key) == 0)
			return (structure[i]->value);
	}
	return (NULL);
}

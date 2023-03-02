#include "rest_api.h"
/**
 * parse_body - parse body from the response
 * @message: pointer of pointer with the strings
 * @num_body: number of body
 *
 * Return: 1 on success 0 on error
 */
query_data **parse_body(char message[], int *num_body)
{
	int i = 0;
	char *equal_position, *value, *last_line;
	int index = 0;
	char cpy_message[MSG_LEN];
	query_data **querie = NULL;

	*num_body = 0;
	last_line = strrchr(message, '\n');
	if (!last_line)
		return (NULL);
	if (!strcpy(cpy_message, last_line + 1))
		return (NULL);
	cpy_message[strlen(last_line)] = '\0';
	while (cpy_message[i++])
	{
		if (cpy_message[i] == '=')
		{
			(*num_body)++;
		}
	}
	if (!*num_body)
		return (NULL);
	querie = calloc((*num_body) + 1, sizeof(query_data *));
	if (!querie)
		return (NULL);
	for (i = 0; i < *num_body; i++)
	{
		if (i == 0)
			value = strtok(last_line + 1, "&");
		else
			value = strtok(NULL, "&");
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

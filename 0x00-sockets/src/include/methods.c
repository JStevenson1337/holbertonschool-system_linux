#include "rest_api.h"
#define TOKEN " \t\r\n"

extern int todo_id;
extern todo_task **todo_tasks;

/**
 * get_response- response using object json format
 * @task:  task used
 * Return: char with response
 */
static char *get_response(todo_task *task)
{
	int i = 0;
	static char get_response[1000];
	char data[1000];
	char value[1000];
	char content_length[20];

	memset(data, 0, 1000);
	strcpy(data, "{");
	for (i = 0; i < 3; i++)
	{
		if (i == 0)
			sprintf(value, "\"id\":%d,", task->id);
		if (i == 1)
			sprintf(value, "\"title\":\"%s\",", task->title);
		if (i == 2)
			sprintf(value, "\"description\":\"%s\"", task->description);
		strcat(data, value);
	}
	strcat(data, "}");
	sprintf(content_length, "%lu", strlen(data));
	memset(get_response, 0, 1000);
	strcpy(get_response, OK_RESPONSE);
	strcat(get_response, "Content-Length: ");
	strcat(get_response, content_length);
	strcat(get_response, "\r\n");
	strcat(get_response, "Content-Type: application/json\r\n\r\n");
	strcat(get_response, data);
	return (get_response);
}

/**
 * create_response - response using object json format
 * @task: task used
 * Return: Nothing
 */
static char *create_response(todo_task *task)
{
	int i = 0;
	static char response[1000];
	char data[1000];
	char value[1000];
	char content_length[20];

	memset(data, 0, 1000);
	strcpy(data, "{");
	for (i = 0; i < 3; i++)
	{
		if (i == 0)
			sprintf(value, "\"id\":%d,", task->id);
		if (i == 1)
			sprintf(value, "\"title\":\"%s\",", task->title);
		if (i == 2)
			sprintf(value, "\"description\":\"%s\"", task->description);
		strcat(data, value);
	}
	strcat(data, "}");
	sprintf(content_length, "%lu", strlen(data));
	memset(response, 0, 1000);
	strcpy(response, CREATED_RESPONSE);
	strcat(response, "Content-Length: ");
	strcat(response, content_length);
	strcat(response, "\r\n");
	strcat(response, "Content-Type: application/json\r\n\r\n");
	strcat(response, data);
	return (response);
}

/**
 * create_todo - extracts information from socket message
 * @message: full message
 * Return: 1 on success 0 on failure
 */
char *create_todo(char message[])
{
	int num_headers = 0, num_body = 0;
	char *title = NULL, *description = NULL;
	char *content_length = NULL;
	query_data **headers = NULL, **body = NULL;

	headers = parse_headers(message, &num_headers);
	content_length = get_key_value("Content-Length", headers, num_headers);
	if (!content_length)
		return (LENGTH_REQ_RESPONSE);
	body = parse_body(message, &num_body);
	title = get_key_value("title", body, num_body);
	description = get_key_value("description", body, num_body);
	if (!title || !description)
		return (UNPROCCESABLE_RESPONSE);
	todo_tasks = realloc(todo_tasks, sizeof(todo_task *) * (todo_id + 1));
	todo_tasks[todo_id] = malloc(sizeof(todo_task));
	todo_tasks[todo_id]->id = todo_id;
	strcpy(todo_tasks[todo_id]->title, title);
	strcpy(todo_tasks[todo_id]->description, description);
	free_query(body, num_body);
	free_query(headers, num_headers);
	return (create_response(todo_tasks[todo_id++]));
}
/**
 * get_todos - gets a list with all todos
 *
 * Return: message with all todos
 */
char *get_todos()
{
	int i = 0, j = 0;
	static char get_response[1000];
	char data[1000];
	char value[1000];
	char content_length[20];

	memset(data, 0, 1000);
	strcpy(data, "[");
	for (j = 0; j < todo_id; j++)
	{
		if (todo_tasks[j])
		{
			strcat(data, "{");
			for (i = 0; i < 3; i++)
			{
				if (i == 0)
					sprintf(value, "\"id\":%d,", todo_tasks[j]->id);
				if (i == 1)
					sprintf(value, "\"title\":\"%s\",", todo_tasks[j]->title);
				if (i == 2)
					sprintf(value, "\"description\":\"%s\"", todo_tasks[j]->description);
				strcat(data, value);
			}
			strcat(data, "}");
			if (j != todo_id - 1)
				strcat(data, ",");
		}
	}
	strcat(data, "]");
	sprintf(content_length, "%lu", strlen(data));
	memset(get_response, 0, 1000);
	strcpy(get_response, OK_RESPONSE);
	strcat(get_response, "Content-Length: ");
	strcat(get_response, content_length);
	strcat(get_response, "\r\n");
	strcat(get_response, "Content-Type: application/json\r\n\r\n");
	strcat(get_response, data);
	return (get_response);
}

/**
 * get_todo - gets a todo
 * @id: id
 * Return: message with all todos
 */
char *get_todo(int id)
{
	int j = 0;
	todo_task *found_task = NULL;

	for (j = 0; j < todo_id; j++)
	{
		if (todo_tasks[j])
			if (todo_tasks[j]->id == id)
				found_task = todo_tasks[j];
	}
	if (!found_task)
		return (BAD_RESPONSE);
	return (get_response(found_task));
}

/**
 * delete_todo - deletes a todo
 * @id: id
 * Return: message with all todos
 */
char *delete_todo(int id)
{
	int j = 0;
	todo_task *found_task = NULL;

	for (j = 0; j < todo_id; j++)
	{
		if (todo_tasks[j])
			if (todo_tasks[j]->id == id)
			{
				found_task = todo_tasks[j];
				break;
			}
	}
	if (!found_task)
		return (BAD_RESPONSE);
	free(found_task);
	todo_tasks[j] = NULL;
	return (NO_CONTENT_RESPONSE);
}

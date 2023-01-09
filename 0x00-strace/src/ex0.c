#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
extern char **environ;
#define CURRENT_ARG


typedef struct node
{
	int data;
	struct node *next;
} node_t;

node_t *head;

void insert(int x)
{
	node_t *temp = malloc(sizeof(node_t));
	temp -> data = x;
	temp -> next = NULL;

	if (head != NULL)
	{
		temp -> next = head;
	}
	head = temp;
}

void copy(node_t *head, int arr[CURRENT_ARG], int n)
{	
	node_t *temp = malloc(sizeof(node_t));
	temp -> data = arr[0];
	temp -> head = NULL;
	head = temp;

	int i;
	for (i = 1; i < n; i++)
	{
		node_t *temp2 = malloc(sizeof(node_t));
		temp -> next = temp2;
		temp2 -> data = arr[i];
		temp2 -> = NULL;
		temp = temp2;
	}
}

void printList()
{
	node_t *temp = head;
	printf("List is : ");

	while (temp != NULL)
	{
		printf(" %d ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}

/**
 * main - Entry Point
 * argc: argument count
 * argv: argument vector
 *
 * ONLY parameter to be passed in 
 * fully qualified path of binary file
 *      ie "./ex0 /usr/bin/ls"
*/
int main(int argc, char *argv[])
{
	int i;
	char *cmd = argv[1];
	char *args[] = {};
	// char **environ};

	if (argc == 1)
	{
		printf("No Command passed to %s\n", argv[0]);
	}
	if (argc > 2)
	{
		printf("Here!\n");
		*argv = (int *)calloc(CURRENT_ARG, sizeof(char));
		int i = 0;
		for (i = 0; i < CURRENT_ARG; i++)
		{
			printf("arrays = [%d] ", i);
			scanf("%s", &argv[i]);
		}
		for (i = 0; i < CURRENT_ARG; i++)
		{
			printf("array [%s] = %s \n", i, argv[i]);

			copy(head, argv[CURRENT_ARG], CURRENT_ARG);
			printList();

			getchar();

		}
	}
	// for (CURRENT_ARG = 0; CURRENT_ARG < argc; CURRENT_ARG++)
	// {
	// 	printf("%s\n", argv[CURRENT_ARG]);
	// 	// snprintf(args, sizeof(argv), "%s", argv);
	// }
	// memcpy(args, argv, sizeof(char *));

	
	execve(
		cmd,
		args,
		environ
	);
	printf(">>> Error = %i\n", errno);


	return 0;
}

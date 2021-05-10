#include "monty.h"

stack_t *head = NULL;

/**
 * main - interpreter for monty byte code
 * @argc: number of arguments to main
 * @argv: double pointer to arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	unsigned int line_no = 0, int_arg = 0, status = 0;
	char *line = NULL, *command = NULL, *arg = NULL;
	size_t size;
	funcs_t *headptr = NULL, *tmp = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	funcs_init(&headptr);
	printf("funcs_t initialized\n");
	tmp = headptr;
	printf("Opening file...\n");
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, fp) != -1)
	{
		line_no++;
		command = strtok(line, " ");
		arg = strchr(command, '\n');
		if (arg)
			*arg = 0;
		arg = strtok(NULL, " ");
		printf("Command: $%s$, Argument: %s\n", command, arg);
		while (tmp != NULL)
		{
	  		if (strcmp(command, tmp->n->opcode) == 0)
			{
				if (arg)
					int_arg = atoi(arg);
				tmp->n->f(&head, int_arg);
				status = 1;
				break;
			}
			tmp =  tmp->next;
		}
		if (status == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
line_no, command);
			exit(EXIT_FAILURE);
		}
		status = 0;
	}
	if (!feof(fp))
	{
		fprintf(stderr, "Error reading line %d\n", line_no + 1);
		exit(EXIT_FAILURE);
	}
	return (0);
}

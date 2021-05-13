#include "monty.h"

/**
 * pstr_stack - print a string using stack elements from the top
 * @head: double pointer to head node of stack
 * @line_number: line number of instruction in the file being read
 *
 * Return: no return value (void)
 */
void pstr_stack(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	(void)line_number;

	if (head == NULL || (*head) == NULL)
	{
		printf("\n");
		return;
	}
	while (temp)
	{
		if (temp->n >= 1 && temp->n <= 127)
		{
			if (isprint(temp->n))
				printf("%c", temp->n);
			else
				my_print(temp->n);
		}
		else
			break;
		temp = temp->next;
	}
	printf("\n");
}

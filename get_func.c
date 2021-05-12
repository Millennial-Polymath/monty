#include "monty.h"

/**
 * get_func - returns the function to be called
 * @s: pointer to char array containing requested function
 *
 * Return: void function pointer
 */
void (*get_func(char *s))(stack_t **head, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push_stack},
		{"pall", pall_stack},
		{"pint", pint},
		{"pop", pop_stack},
		{"swap", swap},
		{"add", add_node},
		{"nop", nop},
		{"sub", sub_node},
		{"div", divide},
		{"mul", multiply},
		{"mod", modulus},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, s) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}

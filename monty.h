#ifndef MONTY_H
#define MONTY_H

/*Header files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*Struct definitions*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct funcs_s - doubly linked list representation of an instruction_t struct
 * @n: instruction_t struct
 * @prev: points to the previous funcs_t node
 * @next: points to the next funcs_t node
 *
 */
typedef struct funcs_s
{
        instruction_t n;
        struct stack_s *prev;
        struct stack_s *next;
} funcs_t;
/*Variable definition*/

/*Function prototypes*/
void add_dnodeint(stack_t **head, unsigned int line_number);
void print_dlistint(stack_t **h, unsigned int line_no);
#endif /* MONTY_H */

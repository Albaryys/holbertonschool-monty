#include "monty.h"
#include <ctype.h>
/**
 * push - Adds a new node with a given value to the top of the stack.
 * @stack: A double pointer to the stack.
 * @line_number: The line number where the push instruction is executed
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *value = strtok(NULL, " \n");

	if (value == NULL || !isdigit(*value))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(value);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

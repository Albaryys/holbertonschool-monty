#include "monty.h"

/**
 * pop - Removes the top element from the stack.
 * @stack: A double pointer to the stack.
 * @line_number: The line number where the pop instruction is executed.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;

	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

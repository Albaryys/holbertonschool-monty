#include "monty.h"

/**
 * add - Adds the top two elements of the stack and removes the top element.
 * @stack: A double pointer to the stack.
 * @line_number: The line number in the file
 *  where the add instruction is executed.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;

	pop(stack, line_number);
}

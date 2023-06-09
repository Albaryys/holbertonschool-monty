#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A double pointer to the stack.
 * @line_number: The line number in the file
 * where the swap instruction is executed.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int temp = (*stack)->n;

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

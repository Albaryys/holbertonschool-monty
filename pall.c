#include "monty.h"
/**
 * pall - Prints all the values in the stack, starting from the top.
 * @stack: A double pointer to the stack.
 * @line_number: The line number in the file
 * where the pall instruction is executed.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

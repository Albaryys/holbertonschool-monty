#include "monty.h"

/**
 * execute_instruction - Executes the instruction corresponding
 * to the given opcode.
 * @instructions: An array of instruction structures.
 * @opcode: The opcode of the instruction to be executed.
 * @line_number: The line number in the file where the instruction is executed.
 */

void execute_instruction(instruction_t *instructions, char *opcode,
			 unsigned int line_number)
{
	int i = 0;

	while (instructions[i].opcode)
	{

		if (strcmp(instructions[i].opcode, opcode) == 0)
		{

			instructions[i].f(&stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

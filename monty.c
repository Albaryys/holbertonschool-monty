#include "monty.h"

/**
 * process_file - Process a file containing Monty bytecode instructions.
 * @filename: The name of the file to be processed.
 *
 * Description: This function opens the specified file,
 * reads the bytecode instructions line by line,
 * and executes the corresponding instructions.
 * It uses the execute_instruction` function
 * to execute each instruction. After processing
 * the file, it closes the file and frees the stack.
 */
void process_file(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	instruction_t instructions[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	char line[100];
	unsigned int line_number = 1;

	while (fgets(line, sizeof(line), file))
	{
		char *opcode = strtok(line, " \n");

		if (opcode != NULL && opcode[0] != '#')
			execute_instruction(instructions, opcode, line_number);

		line_number++;
	}

	fclose(file);
}

/**
 * main - Entry point of the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Description: This function serves as the entry point
 * of the Monty interpreter. It checks if the correct number
 * of command-line arguments is provided.
 * It calls the`process_file` function to process
 * the Monty bytecode file specified in the command-line argument.
 * Finally, it frees the stack and returns 0.
 *
 * Return: 0 on success, or EXIT_FAILURE if the incorrect
 *  number of arguments is provided.
 */
int main(int argc, char *argv[])
{


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	process_file(argv[1]);
	free_stack(&stack);
	return (0);
}

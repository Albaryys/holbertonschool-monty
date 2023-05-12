#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct stack_s - A stack data structure.
 * @n: The value stored in the stack node.
 * @prev: A pointer to the previous node in the stack.
 * @next: A pointer to the next node in the stack.
 *
 * Description:
 * This structure represents a node in a stack. It contains a value (`n`) and
 * pointers to the previous and next nodes in the stack.
 */


typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - An instruction for the Monty bytecode interpreter.
 * @opcode: The opcode of the instruction.
 * @f: A function pointer to the corresponding instruction handler.
 *
 * Description:
 * This structure represents an instruction for the Monty bytecode interpreter.
 * It contains an opcode (a string) and a function pointer (`f`) to the handler
 * function that executes the instruction.
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *stack;

void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);

void execute_instruction(instruction_t *instructions, char *opcode,
			 unsigned int line_number);

#endif

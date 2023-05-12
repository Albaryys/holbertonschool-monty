## C - Stacks, Queues - LIFO, FIFO

### DESCRIPTION:
This is a project for the C programming language focused on stacks and queues, specifically the concepts of LIFO (Last In, First Out) and FIFO (First In, First Out).

### REQUIREMENTS:
- The program must be written in C.
- The program must compile without any errors or warnings using gcc on Ubuntu 20.04 LTS
- The program must use the Betty style.
- The program must not have any memory leaks or errors.
- You are allowed to use a maximum of one global variable
- No more than 5 functions per file
- You are allowed to use the C standard library
- Prototypes of all functions should be included in the header file monty.h
- Your header files should be include guarded

### COMPILATION COMMAND:
It will be compiled on Ubuntu 20.04 LTS using gcc:

### COMPILATION COMMAND:
To compile the program, use the following command:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

### MONTY LANGUAGE:
Monty 0.98 is a scripting language that uses Monty byte codes, similar to Python. It operates on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCode files.
## MONTY BYTE CODE FILES
Files containing Monty byte codes usually have the .m extension. Each line in the file represents an instruction, and there can be any number of spaces before or after the opcode and its argument.
```
push 0
push 1
push 2
push 3
pall
```

Monty byte code files can contain blank lines (empty or made of spaces only), and any additional text after the opcode or its required argument is not considered.

```
push 0 Push 0 onto the stack
push 1 Push 1 onto the stack

push 2
  push 3
                   pall    $

push 4

    push 5    $
      push    6        $

pall This is the end of our program. Monty is awesome!

```

### THE MONTY PROGRAM
The monty program is used to interpret Monty byte code files.

Usage: monty file

file is the path to the file containing Monty byte code
If no file or more than one argument is given to the program, it should print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
If the file cannot be opened, it should print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
If the file contains an invalid instruction, it should print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
<line_number> is the line number where the instruction appears
Line numbers always start at 1
The monty program runs the byte codes line by line and stops if:
It executed every line of the file
It finds an error

### AUTHORS:
Chaherdine Abdou, Arnaud Tily

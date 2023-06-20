#ifndef MONTY_H
#define MONTY_H

/*Sure, here are more detailed steps on how to solve the task of implementing the push and pall opcodes:

1. Define the `stack_t` data structure:
   - `stack_t` is a doubly linked list node that represents a stack.
   - It contains an integer value `n`, and pointers to the previous and next nodes in the stack, `prev` and `next`.
2. Define the `instruction_t` data structure:
   - `instruction_t` contains an opcode and a function pointer to handle the opcode.
   - The opcode is a string that describes the operation to be performed.
   - The function pointer is a pointer to a function that takes a pointer to a `stack_t` node and an unsigned integer as arguments, and returns nothing.
3. Implement the `push` opcode:
   - Parse the input string using the `strtok` function to extract the integer value.
   - Check if the input is a valid integer using the `isdigit` function.
   - Convert the input string to an integer using the `atoi` function.
   - Create a new `stack_t` node, initialize it with the input value, and add it to the top of the stack.
   - If there is an error, print an error message and exit with a failure status.
4. Implement the `pall` opcode:
   - Iterate over the stack from top to bottom, printing each value.
   - If the stack is empty, do not print anything.
5. Write the main function:
   - Open the input file using the `fopen` function.
   - Read each line of the file using the `getline` function.
   - Parse each line using the `strtok` function to extract the opcode and any arguments.
   - Search for the opcode in the `instruction_t` table using a loop and the `strcmp` function.
   - If the opcode is found, call the corresponding function with the stack and line number as arguments.
   - If the opcode is not found, print an error message and exit with a failure status.
6. Test the program:
   - Create a test file containing Monty bytecode instructions that use the push and pall opcodes.
   - Run the program with the test file as input.
   - Verify that the output matches the expected output.
   - If there are any errors, debug the program using print statements and a debugger.
	 
	 >> free everything in time 
	 */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
				char *opcode;
				void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct data_s
{
	FILE *file_descriptor;
	char *buff;
	char *org_cmnds;
	

} data_t;

extern data_t data;

int execution(FILE *file_d, char *str, stack_t **stack, unsigned int i);
void add_node(stack_t **h, unsigned int n);
void push_func(stack_t **h, unsigned int cnt);
void pall_func(stack_t **h, unsigned int coun);
void free_td(stack_t *h);


#endif

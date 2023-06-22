#ifndef MONTY_H
#define MONTY_H

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

/**
 * struct data_s - Data structure for Monty interpreter.
 * @file_descriptor: Pointer to the Monty bytecode file.
 * @buff: Current line of the bytecode file.
 * @org_cmnds: Original command string.
 *
 * Description: Data structure for storing information
 *  related to the Monty interpreter.
 */
typedef struct data_s
{
	FILE *file_descriptor;
	char *buff;
	char *org_cmnds;

} data_t;

extern data_t data;

int handl_execution(FILE *file_d, char *str, stack_t **stack, unsigned int i);
void add_node(stack_t **h, unsigned int n);
void push_function(stack_t **h, unsigned int c);
void pall_function(stack_t **h, unsigned int c);
void pint_function(stack_t **h, unsigned int c);
void pop_function(stack_t **h, unsigned int c);
void swap_function(stack_t **h, unsigned int c);
void nop_function(stack_t **h, unsigned int c);
void print_stack(stack_t **stack);
void free_td(stack_t *h);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void add_function(stack_t **stack, unsigned int line_number);
void sub_function(stack_t **stack, unsigned int line_number);
void div_function(stack_t **stack, unsigned int line_number);
void mul_function(stack_t **stack, unsigned int line_number);

#endif
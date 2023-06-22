#include "monty.h"

/**
 * add_function - Adds the top two elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Current line number of the bytecode file.
 *
 * Return: void
 */
void add_function(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_td(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop_function(stack, line_number);
}

/**
 * sub_function - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the head of the stack.
 * @line_number: Current line number of the bytecode file.
 *
 * Return: void
 */
void sub_function(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_td(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop_function(stack, line_number);
}

/**
 * div_function - Divides the second top element of the stack by the top element.
 * @stack: Pointer to the head of the stack.
 * @line_number: Current line number of the bytecode file.
 *
 * Return: void
 */
void div_function(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_td(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_td(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop_function(stack, line_number);
}

/**
 * mul_function - Multiplies the second top element of the stack with the top element.
 * @stack: Pointer to the head of the stack.
 * @line_number: Current line number of the bytecode file.
 *
 * Return: void
 */
void mul_function(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_td(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop_function(stack, line_number);
}

#include "monty.h"

/**
 * div_function - Divides the second top element of the
 * stack by the top element.
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

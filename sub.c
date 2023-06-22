#include "monty.h"

/**
 * sub_function - Subtracts the top element of the stack
 * from the second top element.
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

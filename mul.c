#include"monty.h"
/**
 * mul_function - Multiplies the second top element of
 * the stack with the top element.
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

	int result = (*stack)->next->n * (*stack)->n;

	pop_function(stack, line_number);
	(*stack)->n = result;
}

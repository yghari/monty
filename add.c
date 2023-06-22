#include"add.c"
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

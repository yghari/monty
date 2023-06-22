#include "monty.h"
/**
 * swap_function - Swaps the top two elements of the stack.
 * @h: Pointer to the head of the stack.
 * @c: Current line number of the bytecode file.
 *
 * Return: void
 */
void swap_function(stack_t **h, unsigned int c)
{
	stack_t *tmp;
	int len = 0, hold;

	tmp = *h;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", c);
		/*fclose(data.file_descriptor);*/
		free(data.buff);
		free_td(*h);
		exit(EXIT_FAILURE);
	}
	tmp = *h;
	hold = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = hold;
}

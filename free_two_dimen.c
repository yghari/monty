#include "monty.h"
/**
 * free_td - Frees a two-dimensional stack.
 * @h: Pointer to the head of the stack.
 *
 * Return: void
 */
void free_td(stack_t *h)
{
	stack_t *temp;

	temp = h;
	while (h)
	{
		temp = h->next;
		free(h);
		h = temp;
	}
}

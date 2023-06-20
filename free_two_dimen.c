#include "monty.h"

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

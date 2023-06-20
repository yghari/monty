#include "monty.h"

void free_td(stack_t *h)
{
	// hada kayfreeyi two dimantional array
	stack_t *temp;

	temp = h;
	while (h)
	{
		temp = h->next;
		free(h);
		h = temp;
	}
}

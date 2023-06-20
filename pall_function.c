#include "monty.h"

void pall_func(stack_t **h, unsigned int coun)
{
	stack_t *temp;
	(void)coun;

	temp = *h;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
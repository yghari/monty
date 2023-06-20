#include "monty.h"

void pall_function(stack_t **h, unsigned int c)
{
	// had pall function katprinti liya chnu kayen fstack ga3 lvalues li kaynin
	stack_t *temp;
	(void)c;

	temp = *h;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
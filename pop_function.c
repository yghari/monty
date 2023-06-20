#include "monty.h"

void pop_function(stack_t **h, unsigned int c)
{
  // pop kattiyer lprevious value 
  // katkhdem b7al lpint ghi hiya 3owet matprinti katremovii
	stack_t *temp;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", c);
		fclose(data.file_descriptor);
		free(data.buff);
		free_td(*h);
		exit(1);
	}
	temp = *h;
	*h = temp->next;
	free(temp);
}
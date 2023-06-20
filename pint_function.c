#include "monty.h"

void pint_func(stack_t **h, unsigned int coun)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", coun);
		fclose(data.file_descriptor);
		free(data.buff);
		free_td(*h);
		exit(1);
	}
	printf("%d\n", (*h)->n);
}
#include "monty.h"

void pint_function(stack_t **h, unsigned int c)
{
	// hadi katprinti liya ghi lvalue li 9bel men lcommand 
	// matalan push 2 w dert murah pint
	// atprinta liya ghi 2
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", c);
		fclose(data.file_descriptor);
		free(data.buff);
		free_td(*h);
		exit(1);
	}
	printf("%d\n", (*h)->n);
}
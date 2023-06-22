#include "monty.h"
/**
 * push_function - Pushes an element to the stack.
 * @h: Pointer to the head of the stack.
 * @c: Current line number of the bytecode file.
 *
 * Return: void
 */
void push_function(stack_t **h, unsigned int c)
{
	int i, j = 0, flg = 0;

	if (data.org_cmnds)
	{
		if (data.org_cmnds[0] == '-')
		{
			j++;
		}
		while (data.org_cmnds[j] != '\0')
		{
			if (data.org_cmnds[j] < 48 || data.org_cmnds[j] > 57)
				flg = 1;
			j++;
		}
		if (flg == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", c);
			/*fclose(data.file_descriptor);*/
			free_td(*h);
			free(data.buff);
			exit(1);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", c);
		/*fclose(data.file_descriptor);*/
		free_td(*h);
		free(data.buff);
		exit(1);
	}
	i = atoi(data.org_cmnds);
	add_node(h, i);
}

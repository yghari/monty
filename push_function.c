#include "monty.h"

void push_func(stack_t **h, unsigned int cnt)
{
	int i, j = 0, flg = 0;

	if (data.org_cmnds)
	{
		if (data.org_cmnds[0] == '-')
			j++;
		for (; data.org_cmnds[j] != '\0'; j++)
		{
			if (data.org_cmnds[j] > 57 || data.org_cmnds[j] < 48)
				flg = 1;
		}
		if (flg == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", cnt);
			fclose(data.file_descriptor);
			free_td(*h);
			free(data.buff);
			exit(1);
			}
		}
	else
	{ 
		fprintf(stderr, "L%d: usage: push integer\n", cnt);
		fclose(data.file_descriptor);
		free_td(*h);
		free(data.buff);
		exit(1);
	}
	i = atoi(data.org_cmnds);
	add_node(h, i);
}
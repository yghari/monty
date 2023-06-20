#include "monty.h"

//a.out -- av[1] 00.m
data_t data = {NULL, NULL, NULL};

void print_stack(stack_t **stack)
{
	stack_t *current_node = *stack;

	while (current_node != NULL)
	{
		printf("stack value |=>: %d\n", current_node->n);
		current_node = current_node->next;
	}
}

int main(int ac, char *av[])
{
	FILE *fp;
	size_t len = 0;
	unsigned int count = 0 ;
	stack_t *stack = NULL;
	ssize_t s_read = 1;
	char *buffer;


	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(1);
	}
	fp = fopen(av[1], "r");
	if (!fp)
	{

		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(1);
	}

	while (s_read > 0)
	{
		buffer = NULL;
		s_read = getline(&buffer, &len, fp);
		count++;
		data.buff = buffer;
		if (s_read > 0)
		{
			execution(fp, buffer, &stack, count);
		}
		free(buffer);
		//print_stack(&stack);
		// printf("|len|=> : %ld\n", len);
		// printf("|buffer|=> : %s\n", buffer);
	}
	fclose(fp);
	free_td(stack);
	return (0);
}

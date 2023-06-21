#include "monty.h"

data_t data = {NULL, NULL, NULL};
/**
 * print_stack - Prints the values of a stack.
 * @stack: Pointer to the head of the stack.
 *
 * Return: void
 */
void print_stack(stack_t **stack)
{
	stack_t *current_node = *stack;

	while (current_node != NULL)
	{
		printf("stack value |=>: %d\n", current_node->n);
		current_node = current_node->next;
	}
}
/**
 * main - Entry point of the Monty interpreter.
 * @ac: Number of command line arguments.
 * @av: Array of command line arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int ac, char *av[])
{
	FILE *fp;
	size_t len = 0;
	unsigned int count = 0;
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
			handl_execution(fp, buffer, &stack, count);
		}
		free(buffer);
	}
	fclose(fp);
	free_td(stack);
	return (0);
}

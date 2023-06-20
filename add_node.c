#include "monty.h"

void add_node(stack_t **h, unsigned int n)
{

	stack_t *new_node, *tmp;

	tmp = *h;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (tmp)
		tmp->prev = new_node;
	new_node->n = n;
	new_node->next = *h;
	new_node->prev = NULL;
	*h = new_node;
}

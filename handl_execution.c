#include "monty.h"
/**
 * handl_execution - Handles the execution of Monty instructions.
 * @file_d: Pointer to the Monty bytecode file.
 * @str: Current line of the bytecode file.
 * @stack: Pointer to the head of the stack.
 * @count_i: Current line number of the bytecode file.
 *
 * Return: 0 on success, 1 on failure.
 */
int handl_execution(FILE *file_d, char *str, stack_t **stack
, unsigned int count_i)
{
	instruction_t comand[] = {
		{"push", push_function},
		{"pall", pall_function},
		{"pint", pint_function},
		{"pop", pop_function},
		{"swap", swap_function},
		{"nop", nop_function},
		{"add", add_function},
		{"sub", sub_function},
		{"div", div_function},
		{"mul", mul_function},
		{NULL, NULL}
	};

	unsigned int i = 0;
	char *split_instr;

	split_instr = strtok(str, " \t\n");
	data.org_cmnds = strtok(NULL, " \t\n");

	while (comand[i].opcode && split_instr)
	{

		if (strcmp(split_instr, comand[i].opcode) == 0)
		{
			comand[i].f(stack, count_i);
			return (0);
		}
		i++;
	}
	if (split_instr && comand[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count_i, split_instr);
		free_td(*stack);
		fclose(file_d);
		free(str);
		exit(1);
	}
	return (1);
}

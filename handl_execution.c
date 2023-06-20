#include "monty.h"


//this is where i handle the comand or instructions like pop or push or pint ...
int handl_execution(FILE *file_d, char *str, stack_t **stack, unsigned int count_i)
{
	instruction_t comand[] = {
		{"push",push_function},
		{"pall",pall_function},
		{"pint",pint_function},
		{"pop",pop_function},
		{"swap",swap_function},
		{"nop",nop_function},
		{NULL, NULL}
	};

	unsigned int i = 0;
	char *split_instr;
//like we remember that strtok katspliti one dimention w katrdu two dimentionall array 
	split_instr = strtok(str, " \t\n");
	// dakci li derna splitina btab wla nw line wl space bach yb9ana ghi l cmnd
	data.org_cmnds = strtok(NULL, " \t\n");
	// hna b9ina kan7tu les cmnd fhad org_cmnds ze3ma organized commands hahah

	while(comand[i].opcode && split_instr)
	{
		// this is where magic happen 
		// gltl lwhile mat7bess ta tl9a null wla fach lcommand ytssalaw
		if (strcmp(split_instr, comand[i].opcode) == 0)
		{
			// strcmp tacompari str luwel m3a lcommand li 3endna
			// had l3iba na hiya lfunction li 7atina alx flheader 
			// katakhed stack kaml w dak lcount_i huwa lindice dyal comand
			// 7iit pointer to function
			comand[i].f(stack, count_i);
			return (0);
		}
		i++;
	}
	if (split_instr && comand[i].opcode == NULL)
	{
		// had khlass dyal lerror
		fprintf(stderr, "L%d: unknown instruction %s\n", count_i, split_instr);
		free_td(*stack);
		fclose(file_d);
		free(str);
		exit(1);
	}
	return (1);
}
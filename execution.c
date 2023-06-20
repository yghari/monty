#include "monty.h"

int execution(FILE *file_d, char *str, stack_t **stack, unsigned int count_i)
{
  instruction_t comand[] = {
    {"push",push_func},
    {"pall",pall_func},
    {NULL, NULL}
  };

  unsigned int i = 0;
  char *split_instr;

  split_instr = strtok(str, " \t\n");
  data.org_cmnds = strtok(NULL, " \t\n");

  while(comand[i].opcode && split_instr)
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
    exit(EXIT_FAILURE);
  }
  return (1);
}
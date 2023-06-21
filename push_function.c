#include "monty.h"

void push_function(stack_t **h, unsigned int c)
{
	//hadi t9edri t9uli hiya li kat3mrli stack 
	// katb9a tpushi value bvalue fstack
	int i, j = 0, flg = 0;

	if (data.org_cmnds)
	{
		while (data.org_cmnds[j] != '\0')
		{
			// hna ghantcheki wach dik l7aja li mura lcomand wach machi ra9m la kant machi ra9m ghan7et flflag 1 w nhbat nprinti lerror
			if (data.org_cmnds[j] > 57 || data.org_cmnds[j] < 48)
				flg = 1;
			 j++;
		}
		if (flg == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", c);
			fclose(data.file_descriptor);
			free_td(*h);
			free(data.buff);
			exit(1);
			}
		}
	else
	{
		//hadi f 7allat lerror diret bla mantcheki dak ra9m
		fprintf(stderr, "L%d: usage: push integer\n", c);
		fclose(data.file_descriptor);
		free_td(*h);
		free(data.buff);
		exit(1);
	}
	// mhm hna kan7uwel dak ra9m lint 7it kaykun mzl character
	i = atoi(data.org_cmnds);
	//safi w naaddi node flhead 
	// had lvariable h dima kan3ni bih lhead
	add_node(h, i);
}
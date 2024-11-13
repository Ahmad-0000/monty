#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


void mod(char **linearray, stack_t **rear, unsigned int linenum)
{
	if (!(*rear))
	{
		fprintf(stderr, "L%d: cant't mod, stack is too short\n", linenum);
		freewarray(linearray);
		exit(EXIT_FAILURE);
	}
	if (!(*rear)->prev)
	{
		fprintf(stderr, "L%d: cant't mod, stack is too short\n", linenum);
		freestack(*rear);
		freewarray(linearray);
		exit(EXIT_FAILURE);
	}
	if (!(*rear)->n)
	{
		fprintf(stderr, "L%d: division by zero\n", linenum);
		freestack(*rear);
		freewarray(linearray);
		exit(EXIT_FAILURE);
	}
	(*rear)->prev->n %= (*rear)->n;
	*rear = (*rear)->prev;
	free((*rear)->next);
	(*rear)->next = NULL;
}

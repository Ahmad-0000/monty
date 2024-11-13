#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "monty.h"

void add(char **linearray, stack_t **rear, unsigned int linenum)
{
	if (!(*rear))
	{
		fprintf(stderr, "L%d: cant't add, stack is too short\n", linenum);
		freewarray(linearray);
		exit(EXIT_FAILURE);
	}
	if (!(*rear)->prev)
	{
		fprintf(stderr, "L%d: cant't add, stack is too short\n", linenum);
		freestack(*rear);
		freewarray(linearray);
		exit(EXIT_FAILURE);
	}
	(*rear)->prev->n += (*rear)->n;
	*rear = (*rear)->prev;
	free((*rear)->next);
	(*rear)->next = NULL;
}

void nop(char **linearray __attribute__((unused)),
	 stack_t **rear __attribute__((unused)),
	 unsigned int linenum __attribute__((unused))
	 )
{
	return;
}

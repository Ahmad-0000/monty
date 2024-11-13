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

void pchar(char **linearray, stack_t **rear, unsigned int linenum)
{
	if (!(*rear))
	{
		fprintf(stderr, "L%d: can't pchar, stack is empty\n", linenum);
		freewarray(linearray);
		exit(EXIT_FAILURE);
	}
	if ((*rear)->n > 127 || (*rear)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value is out of range", linenum);
		freewarray(linearray);
		freestack(*rear);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*rear)->n);
}


void pstr(char **linearray __attribute__((unused)), stack_t **rear, unsigned int linenum __attribute__((unused)))
{
        stack_t *temp;

        temp = *rear;
        while (temp && temp->n)
	{
		if (temp->n > 127 || temp->n < 0)
			break;
		printf("%c", temp->n);
		temp = temp->prev;
	}
	putchar('\n');
}

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

void rotl(char **linearray __attribute__((unused)), stack_t **rear, unsigned int linenum __attribute__((unused)))
{
	stack_t *temp1, *temp2;

	if (!(*rear) || !(*rear)->prev)
		return;
	temp1 = temp2 = *rear;
	*rear = (*rear)->prev;
	while (temp1->prev)
		temp1 = temp1->prev;
	temp2->prev->next = NULL;
	temp1->prev = temp2;
	temp2->prev = NULL;
	temp2->next = temp1;
}


void rotr(char **linearray __attribute__((unused)), stack_t **rear, unsigned int linenum __attribute__((unused)))
{
	stack_t *temp1, *temp2;

	if (!(*rear) || !(*rear)->prev)
		return;
	temp1 = temp2 = *rear;
	while (temp1->prev)
		temp1 = temp1->prev;
	temp1->prev = *rear;
	temp1->prev->next = temp1;
	temp1->next->prev = NULL;
	temp1->next = NULL;
	*rear = temp1;
}

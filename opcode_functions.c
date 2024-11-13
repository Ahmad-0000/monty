#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "monty.h"


void push(char **linearray, stack_t **rear, unsigned int linenum)
{
        int i;
        stack_t *new_node;

	if (!linearray[1])
		goto error;
	if ((linearray[1][0] < '0' || linearray[1][0] > '9') && linearray[1][0] != '-')
		fprintf(stderr, "L%d: usage: push integer\n", linenum);
	for (i = 1; linearray[1][i]; i++)
		if (linearray[1][i] < '0' || linearray[1][i] > '9')
			goto error;
	new_node = malloc(sizeof(*new_node));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		goto error2;
	}
	new_node->n = atoi(linearray[1]);
	new_node->next = NULL;
	if (!(*rear))
	{
		new_node->prev = NULL;
		*rear = new_node;
		return;
	}
	new_node->prev = *rear;
	(*rear)->next = new_node;
	*rear = new_node;
	return;
error:
	fprintf(stderr, "L%d: usage: push integer\n", linenum);
error2:
	freewarray(linearray);
	freestack(*rear);
	exit(EXIT_FAILURE);
}

void pall(char **linearray __attribute__((unused)), stack_t **rear, unsigned int linenum __attribute__((unused)))
{
        stack_t *temp;

        temp = *rear;
        while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}

void pint(char **linearray, stack_t **rear, unsigned int linenum)
{
	if (!(*rear))
	{
		fprintf(stderr, "L%d: can't pint, stack is empty\n", linenum);
		freewarray(linearray);
		freestack(*rear);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*rear)->n);
}

void pop(char **linearray, stack_t **rear, unsigned int linenum)
{
	if (!(*rear))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", linenum);
		freewarray(linearray);
		exit(EXIT_FAILURE);	
	}
	if ((*rear)->prev)
	{
		*rear = (*rear)->prev;
		free((*rear)->next);
		(*rear)->next = NULL;
		return;
	}
	free(*rear);
	*rear = NULL;
}

void swap(char **linearray, stack_t **rear, unsigned int linenum __attribute__((unused)))
{
	int temp;

	if (!(*rear))
	{
		fprintf(stderr, "L%d: can't swap, stack is too short\n", linenum);
		freewarray(linearray);
		exit(EXIT_FAILURE);
	}
	if (!(*rear)->prev)
	{
		fprintf(stderr, "L%d: can't swap, stack is too short\n", linenum);
		freewarray(linearray);
		freestack(*rear);
		exit(EXIT_FAILURE);
	}
	temp = (*rear)->prev->n;
	(*rear)->prev->n = (*rear)->n;
	(*rear)->n = temp;
}

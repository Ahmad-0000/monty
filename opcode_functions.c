#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "monty.h"


void push(char **linearray, stack_t **rear, unsigned int linenum)
{
        int i;
        stack_t *new_node;

	if (!linearray[1])
	{
		fprintf(stderr, "L%d: usage: push integer\n", linenum);
		goto error;
	}
	if ((linearray[1][0] < '0' || linearray[1][0] > '9') && linearray[1][0] != '-')
	{
		fprintf(stderr, "L%d: usage: push integer\n", linenum);
		goto error;
	}
	for (i = 1; linearray[1][i]; i++)
	{
		if (linearray[1][i] < '0' || linearray[1][i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", linenum);
			goto error;
		}
	}
	new_node = malloc(sizeof(*new_node));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		goto error;
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
	printf("Here\n");
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

/*void pint(stack_t **stack_head, unsigned int line_num)
{
        stack_t *temp;
        int char_read = 1;
        char c = '\0';

        if (stack_head == NULL || *stack_head == NULL)
        {
            c = skip_after(c, &char_read);
            errcpi(line_num);
        }
        temp = *stack_head;
        while (temp->next != NULL)
            temp = temp->next;
        printf("%d\n", temp->n);
        c = skip_after(c, &char_read);
}

void pop(stack_t **stack_head, unsigned int line_num)
{
        stack_t *temp;
        int char_read = 1;
        char c = '\0';

        if (stack_head == NULL || *stack_head == NULL)
        {
            c = skip_after(c, &char_read);
            fprintf(stderr , "L%u: can't pop an empty stack\n", line_num);
            exit(EXIT_FAILURE);
        }
        temp = *stack_head;
        while (temp->next != NULL)
            temp = temp->next;
        if (temp->prev == NULL)
        {
            free(temp);
            *stack_head = NULL;
        }
        else
        {
            temp->prev->next = NULL;
            free(temp);
        }
        skip_after(c, &char_read);
}

void swap(stack_t **stack_head, unsigned int line_num)
{
        int char_read = 1;
        char c = '\0';
        stack_t *temp;
        int nodes_num = 0;

        if (stack_head == NULL || *stack_head == NULL)
        {
            c = skip_after(c, &char_read);
            errcs(line_num);
        }
        temp = *stack_head;
        while (temp != NULL)
        {
            temp = temp->next;
            nodes_num++;
        }
        if (nodes_num < 2)
        {
            c = skip_after(c, &char_read);
            errcs(line_num);
        }
        temp = *stack_head;
        while (temp->next->next != NULL)
            temp = temp->next;
        if (nodes_num > 2)
            temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next->next = temp;
        temp->prev = temp->next;
        temp->next = NULL;
        skip_after(c, &char_read);
} */

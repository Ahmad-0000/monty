#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "monty.h"

extern int fd;

void push(stack_t **stack_head, unsigned int line_num)
{
        char c;
        int char_read = 1;
        char integer[12];
        int i = 1;
        char j = 0;
        stack_t *temp_head, *new_node;

        fill_integer(integer);
        char_read = read(fd, &c, 1);
        while (c == ' ' && char_read > 0)
            char_read = read(fd, &c, 1);
        if (c == '\n' || char_read == 0 || (c != '-' && (c < '0' || c > '9')))
            errcp(line_num);
        temp_head = (stack_head == NULL) ? NULL : *stack_head;
        new_node = malloc(sizeof(*new_node));
        if (new_node == NULL)
            errcm();
        new_node->next = new_node->prev = NULL;
        if (c == '-')
            char_read = get_neg(integer, &c, &j, line_num, &i);
        else
            char_read =  get_pos(integer, &c, &j, line_num, &i);
        get_all(integer, &c, &char_read, j, i, line_num);
        c = skip_after(c, &char_read);
        while (temp_head != NULL && temp_head->next != NULL)
            temp_head = temp_head->next;
        new_node->n = atoi(integer);
        if (*stack_head == NULL)
        {
            *stack_head = new_node;
        }
        else
        {
            temp_head->next = new_node;
            new_node->prev = temp_head;
        }
}

void pall(stack_t **stack_head, unsigned int line_num)
{
        stack_t *temp;
        int char_read = 1;
        char c = '\0';

        if (stack_head == NULL || *stack_head == NULL || line_num == 1)
        {
            c = skip_after(c, &char_read);
            return;
        }
        temp = *stack_head;
        while (temp->next != NULL)
            temp = temp->next;
        while (temp != NULL)
        {
            printf("%d\n", temp->n);
            temp = temp->prev;
        }
        c = skip_after(c, &char_read);
}

void pint(stack_t **stack_head, unsigned int line_num)
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
            dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_num);
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
}

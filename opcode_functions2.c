#include <stdlib.h>
#include "monty.h"

extern int fd;

void add(stack_t **stack_head, unsigned int line_num)
{
        stack_t *temp;
        int char_read = 1;
        char c = '\0';
        int nodes_num = 0;

        if (stack_head == NULL || *stack_head == NULL)
        {
            c = skip_after(c, &char_read);
            errca(line_num);
        }
        temp = *stack_head;
        while (temp != NULL)
        {
            nodes_num++;
            temp = temp->next;
        }
        if (nodes_num < 2)
        {
            c = skip_after(c, &char_read);
            errca(line_num);
        }
        temp = *stack_head;
        while (temp->next->next != NULL)
            temp = temp->next;
        temp->n += temp->next->n;
        temp = temp->next;
        temp->prev->next = NULL;
        free(temp);
        c = skip_after(c, &char_read);
}

void nop(stack_t **stack_head, unsigned int line_num)
{
        int char_read = 1;
        char c = '\0';

        if (line_num || stack_head)
            skip_after(c, &char_read);
}

void sub(stack_t **stack_head, unsigned int line_num)
{
        int counter = 0;
        stack_t *temp;
        int char_read = 1;
        char c = '\0';

        if (stack_head == NULL || *stack_head == NULL)
            errcsb(line_num);
        temp = *stack_head;
        while (temp != NULL)
        {
            temp = temp->next;
            counter++;
        }
        if (counter < 2)
            errcsb(line_num);
        temp = *stack_head;
        while (temp->next->next != NULL)
            temp = temp->next;
        temp->n -= temp->next->n;
        temp = temp->next;
        temp->prev->next = NULL;
        free(temp);
        skip_after(c, &char_read);
}

void divide(stack_t **stack_head, unsigned int line_num)
{
        char c = '\0';
        int char_read = 1;
        stack_t *temp;
        int counter = 0;

        if (stack_head == NULL || *stack_head == NULL)
            errcd(line_num);
        temp = *stack_head;
        while (temp != NULL)
        {
            temp = temp->next;
            counter++;
        }
        if (counter < 2)
            errcd(line_num);
        temp = *stack_head;
        while (temp->next->next != NULL)
            temp = temp->next;
        if (temp->next->n == 0)
            errcd2(line_num);
        temp->n /= temp->next->n;
        temp = temp->next;
        temp->prev->next = NULL;
        free(temp);
        skip_after(c, &char_read);
}

void mul(stack_t **stack_head, unsigned int line_num)
{
        int counter = 0;
        char c = '\0';
        int char_read = 1;
        stack_t *temp;

        if (stack_head == NULL || *stack_head == NULL)
            errcmu(line_num);
        temp = *stack_head;
        while (temp != NULL)
        {
            temp = temp->next;
            counter++;
        }
        if (counter < 2)
            errcmu(line_num);
        temp = *stack_head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->prev->n *= temp->n;
        temp->prev->next = NULL;
        free(temp);
        skip_after(c, &char_read);
}

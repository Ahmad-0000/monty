#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "monty.h"

extern int fd;

void mod(stack_t  **stack_head, unsigned int line_num)
{
        char c = '\0';
        int char_read = 1;
        int counter = 0;
        stack_t *temp;

        if (stack_head == NULL || *stack_head == NULL)
            errcmo(line_num);
        temp = *stack_head;
        while (temp != NULL)
        {
            temp = temp->next;
            counter++;
        }
        if (counter < 2)
            errcmo(line_num);
        temp = *stack_head;
        while (temp->next != NULL)
            temp = temp->next;
        if (temp->n == 0)
            errcd2(line_num);
        temp->prev->n %= temp->n;
        temp->prev->next = NULL;
        free(temp);
        skip_after(c, &char_read);
}

void pchar(stack_t **stack_head, unsigned int line_num)
{
        stack_t *temp;
        char c = '\0';
        int char_read = 1;

        if (stack_head == NULL || *stack_head == NULL)
            errcpc(line_num);
        temp = *stack_head;
        while (temp->next != NULL)
            temp = temp->next;
        if (temp->n < 0 || temp->n > 127)
            errcpc2(line_num);
        printf("%c\n", temp->n);
        skip_after(c, &char_read);
}

void pstr(stack_t **stack_head, unsigned int line_num)
{
        stack_t *temp;
        int char_read;
        char c = '\0';
        int c_last;

        if (line_num)
            char_read = 1;
        if (stack_head == NULL || *stack_head == NULL)
        {
            skip_after(c, &char_read);
            printf("\n");
            return;
        }
        temp = *stack_head;
        while (temp->next != NULL)
            temp = temp->next;
        c_last = temp->n;
        while (temp != NULL && c_last != 0 && (c_last > 0 || c_last < 127))
        {
            printf("%c", c_last);
            temp = temp->prev;
            c_last = temp->n;
        }
        printf("\n");
        skip_after(c, &char_read);
}

void rotl(stack_t **stack_head, unsigned int line_num)
{
        stack_t *temp;
        int char_read;
        char c = '\0';
        int prev, current, last;

        if (line_num)
            char_read = 1;
        if (stack_head == NULL || *stack_head == NULL)
        {
            skip_after(c, &char_read);
            return;
        }
        temp = *stack_head;
        while (temp->next != NULL)
            temp = temp->next;
        last = temp->n;
        temp = *stack_head;
        temp = temp->next;
        if (temp != NULL)
        {
            prev = temp->prev->n;
            current = temp->n;
        }
        while (temp != NULL)
        {
            temp->n = prev;
            prev = current;
            temp = temp->next;
            if (temp)
                current = temp->n;
        }
        (*stack_head)->n = last;
        skip_after(c, &char_read);
}

void rotr(stack_t **stack_head, unsigned int line_num)
{
        char c = '\0';
        int char_read;
        stack_t *temp;
        int first, next;

        if (line_num)
            char_read = 1;
        if (stack_head == NULL || *stack_head == NULL)
        {
            skip_after(c, &char_read);
            return;
        }
        temp = *stack_head;
        first = temp->n;
        if (temp->next)
            next = temp->next->n;
        while (temp->next != NULL)
        {
            temp->n = next;
            temp = temp->next;
            if (temp->next)
                next = temp->next->n;
        }
        temp->n = first;
        skip_after(c, &char_read);
}

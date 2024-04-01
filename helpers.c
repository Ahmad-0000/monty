#include "monty.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>

extern int fd;

/**
 * execute - to choose the proper opcode function
 * @opcode: the opcode read from the .m file
 * @line_num: the line number where the opcode occurs in the .m file
 * @stack_head: to point to the stack head
 */

void execute(char *opcode, unsigned int line_num, stack_t **stack_head)
{
int i;
instruction_t array[] = {
{"push", push}, {"pall", pall},
{"pint", pint},
                {"pop", pop},
                {"swap", swap},
                {"add", add},
                {"nop", nop},
                {"sub", sub},
                {"div", divide},
                {"mul", mul},
                {"mod", mod},
                {"pchar", pchar},
                {"pstr", pstr},
                {"rotl", rotl},
                {"rotr", rotr}
        };

        for (i = 0; i < 15 ; i++)
        {
            if (!strcmp(opcode, array[i].opcode))
            {
                (array[i]).f(stack_head, line_num);
                return;
            }
        }
        errno(line_num, opcode);
}


/**
 * fill - to fill the opcode array with '\0' to compare and print properly
 * @n: the number of places to be filled with '\0'
 * @opcode: the array to be filled
 */

void fill(int n, char *opcode)
{
        int i;

        i = 0;
        while (i < n)
            opcode[i++] = '\0';
}

/**
 * skip_before - to skip the whitespaces before the opcode in each line
 * @c: the last read character before the opcode
 * @char_read: to determine whether the EOF is reached or not
 * @line_num: the line number where the opcode occures in the .m file
 *
 * Retrun: to return the first read character from the opcode, or, ' ' or
 * '\n' if no opcode.
 */

char skip_before(char c, int *char_read, unsigned int *line_num)
{
        while ((c == ' ' || c == '\n') && *char_read > 0)
        {
            *char_read = read(fd, &c, 1);
            if (c == '\n')
                (*line_num)++;
        }
        while (c == '#')
        {
            c = skip_after(c, char_read);
            *char_read = read(fd, &c, 1);
            c = skip_before(c, char_read, line_num);
        }
        return (c);
}

/**
 * fill_integer - to fill the array of integer.
 * @integer: the array of integer.
 */

void fill_integer(char *integer)
{
        int i = 0;

        while (i < 12)
        {
            integer[i] = i == 0 ? '-' : '\0';
            i++;
        }
}

/**
 * skip_after - to skip the whitespaces after the opcode.
 * @c: the first character read after the opcode.
 * @char_read: to determine whether the EOF has been reached or not
 *
 * Return: to return the first character read after the opcode, or, ' '
 * if the EOF is reached
 */

char skip_after(char c, int *char_read)
{
        while (c != '\n' && *char_read > 0)
            *char_read = read(fd, &c, 1);
        return (c);
}

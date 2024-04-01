#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "monty.h"

extern int fd;

/**
 * errnf - when no file is provided form the CLI
 */

void errnf(void)
{
        dprintf(STDERR_FILENO ,"USAGE: monty file\n");
        exit(EXIT_FAILURE);
}

/**
 * errno - when there is no matching opcode.
 * @line_num: the line whrere no matching opcode.
 * @opcode: unknown opcode
 */

void errno(unsigned int line_num, char opcode[])
{
        dprintf(STDERR_FILENO ,"L%u: unknown instruction %s\n", line_num, opcode);
        close(fd);
        exit(EXIT_FAILURE);
}

/**
 * errco - can't open the file.
 * @filename: file name
 */

void errco(char *filename)
{
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
}

/**
 * errcp - can't push
 */

void errcp(unsigned int line_num)
{
        dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_num);
        close(fd);
        exit(EXIT_FAILURE);
}

/**
 * errcm - can't malloc
 */

void errcm(void)
{
        dprintf(STDERR_FILENO, "Error: malloc failed\n");
        close(fd);
        exit(EXIT_FAILURE);
}

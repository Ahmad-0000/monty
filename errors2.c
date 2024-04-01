#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "monty.h"

extern int fd;

/**
 * errcpi - a function to produce an error message and exit with EXIT_FAILURE
 * @line_num: the line number where the error ocurred
 */

void errcpi(unsigned int line_num)
{
        dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_num);
        close(fd);
        exit(EXIT_FAILURE);
}

/**
 * errcs - a function to produce an error message and exit with EXIT_FILURE
 * @line_num: the line number where the error occured
 */

void errcs(unsigned int line_num)
{
        dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_num);
        close(fd);
        exit(EXIT_FAILURE);
}

/**
 * errca - a function to produce an error message and exit with EXIT_FAILURE
 * @line_num: the line number where the error occured
 */

void errca(unsigned int line_num)
{
        dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_num);
        close(fd);
        exit(EXIT_FAILURE);
}

void errcsb(unsigned int line_num)
{
        dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line_num);
        close(fd);
        exit(EXIT_FAILURE);
}

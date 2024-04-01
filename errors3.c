#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "monty.h"

extern int fd;

void errcd(unsigned int line_num)
{
        fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
        close(fd);
        exit(EXIT_FAILURE);
}

void errcd2(unsigned int line_num)
{
        fprintf(stderr, "L%u: divison by zero\n", line_num);
        close(fd);
        exit(EXIT_FAILURE);
}

void errcmu(unsigned int line_num)
{
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
        close(fd);
        exit(EXIT_FAILURE);
}

void errcmo(unsigned int line_num)
{
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
        close(fd);
        exit(EXIT_FAILURE);
}

void errcpc(unsigned int line_num)
{
        fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
        close(fd);
        exit(EXIT_FAILURE);
}

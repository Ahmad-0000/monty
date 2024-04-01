#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "monty.h"

extern int fd;

void errcpc2(unsigned int line_num)
{
        fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
        close(fd);
        exit(EXIT_FAILURE);
}

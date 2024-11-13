#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "monty.h"

/**
 * errnf - when no file is provided form the CLI
 */

void errnf(void)
{
        fprintf(stderr ,"USAGE: monty file\n");	
        exit(EXIT_FAILURE);
}

/**
 * errno - when there is no matching opcode.
 * @line_num: the line whrere no matching opcode.
 * @opcode: unknown opcode
 */

void errno(unsigned int line_num, char opcode[])
{
        fprintf(stderr ,"L%u: unknown %s\n", line_num, opcode);
        fclose(fd);
        exit(EXIT_FAILURE);
}

/**
 * errco - can't open the file.
 * @filename: file name
 */

void errco(char *filename)
{
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
}

/**
 * errcp - can't push
 */

/*void errcp(unsigned int line_num)
{
        fprintf(stderr, "L%u: usage: push integer\n", line_num);
        fclose(fd);
        exit(EXIT_FAILURE);
}*/

/**
 * errcm - can't malloc
 */

/*void errcm(void)
{
        fprintf(stderr, "Error: malloc failed\n");
        fclose(fd);
        exit(EXIT_FAILURE);
}*/

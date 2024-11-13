#include "monty.h"
#include <stdlib.h>
#include <string.h>

/**
 * execute - to choose the proper opcode function
 * @opcode: the opcode read from the .m file
 * @line_num: the line number where the opcode occurs in the .m file
 * @stack_head: to point to the stack head
 */

void exec(char **linearray, unsigned int linenum, stack_t **rear)
{
	int i;
	instr_t array[] = {
		{"push", push},
	       	{"pall", pall},
		{"pint", pint},
                {"pop", pop},
                {"swap", swap},
                {"add", add},
                {"nop", nop},
                {"sub", sub},
                {"div", divison},
                {"mul", mul},
                /*{"mod", mod},
                {"pchar", pchar},
                {"pstr", pstr},
                {"rotl", rotl},
                {"rotr", rotr}*/
        };

	if (!linearray[0])
		return;
        for (i = 0; i < 10; i++)
       	{
		if (!strcmp(linearray[0], array[i].opcode))
		{
			(array[i]).f(linearray, rear, linenum);
			return;
		}
        }
	freestack(*rear);
        errno(linenum, linearray);
}

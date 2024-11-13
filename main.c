#include <string.h>
#include <stdlib.h>
#include "monty.h"
#include <stdio.h>

FILE *fd;

/**
 * main - Entry point
 * @argc: the number of command line arguments entered
 * @argv: an array of command line arguments entered
 *
 * Return: to return 0 when sucess
 */

int main(int argc, char *argv[])
{
	int i, namelength;
	size_t n = 0;
	unsigned int linenum = 1;
	stack_t *rear = NULL;
	char *line = NULL;
	char **linearray = NULL;

	if (argc != 2)
		errnf();
	namelength = strlen(argv[1]);
	for (i = namelength - 1; i >= 0; i--)
		if (argv[1][i] == '.')
		{
			if (!argv[1][i + 1])
				break;
			else if (argv[1][i + 1] != 'm' || argv[1][i + 2])
				exit(EXIT_FAILURE);
		}
	fd = fopen(argv[1], "r");
	if (!fd)
		errco(argv[1]);
	while (getline(&line, &n, fd) != -1)
	{
		for (i = 0; line[i]; i++)
			if (line[i] == '#')
			{
				line[i] = '\0';
				break;
			}	
		linearray = strtow(line);
		exec(linearray, linenum, &rear);
		freewarray(linearray);
		linenum++;
	}
	free(line);
	freestack(rear);
	fclose(fd);
	return (0);
}

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "monty.h"

int fd;

/**
 * main - Entry point
 * @argc: the number of command line arguments entered
 * @argv: an array of command line arguments entered
 *
 * Return: to return 0 when sucess
 */

int main(int argc, char *argv[])
{
	int i = 0;
	int char_read;
	char opcode[6], c;
	unsigned int line_num = 1;
	stack_t *stack_head;

	stack_head = NULL;
	if (argc != 2)
		errnf();
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		errco(argv[1]);
	fill(6, opcode);
	char_read = read(fd, &c, 1);
	while (char_read > 0)
	{
		fill(6, opcode);
		c = skip_before(c, &char_read, &line_num);
		i = 0;
		opcode[i++] = c;
		line_num += get_opcode(opcode, c, i, &char_read);
		execute(opcode, line_num, &stack_head);
		line_num++;
		char_read = read(fd, &c, 1);
	}
	close(fd);
	return (0);
}

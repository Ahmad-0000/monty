#include "monty.h"
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>

extern int fd;

/**
 * get_opcode - a function to continue getting the opcode after its 1st
 *  character
 * @opcode: an array containing 1st opcode character
 * @c:
 * @i:
 * @char_read:
 *
 * Return: to return a number of new lines encountered inside get_opcode
 */

unsigned int get_opcode(char *opcode, char c, int i, int *char_read)
{
        unsigned int line_num = 0;
        int limit = 4;
        int counter = 0;

        while (c != ' ' && c != '\n' && i < limit && *char_read > 0)
        {
            *char_read = read(fd, &c, 1);
            counter++;
            if (counter == 1)
            {
                    if ((c == 'o' && opcode[0] != 'r') || c == 'd' || c == 'i')
                        limit = 3;
                    else if ((opcode[0] == 's' || opcode[0] == 'm') && c == 'u')
                        limit = 3;
                    else if (c == 'c')
                      limit = 5;
            }
            if (c == '\n')
            {
                line_num++;
                break;
            }
            if (c == ' ')
            {
                break;
            }
            opcode[i++] = c;
        }
        return (line_num);
}

/**
 * get_neg - a function to store negative numbers on the integer array
 */

int get_neg(char *integer, char *c, char *j, unsigned int line_num, int *i)
{
        int char_read = 0;

        char_read = read(fd, c, 1);
        if (*c < '0' || *c > '9' || char_read == 0)
            errcp(line_num);
        integer[(*i)++] = *c;
        char_read = read(fd, c, 1);
        (*j)++;
        return (char_read);
}

int get_pos(char *integer, char *c, char *j, unsigned int line_num, int *i)
{
        int char_read;

        if (*c < '0' || *c > '9')
            errcp(line_num);
        *i = 0;
        integer[(*i)++] = *c;
        char_read = read(fd, c, 1);
        (*j)++;
        return (char_read);
}

void get_all(char *integer, char *c, int *cread, char j,int i, unsigned int ln)
{
        while (*c != ' ' && *c != '\n' && *cread > 0 && j < 10)
        {
            integer[i++] = *c;
            if ((*c < '0' || *c > '9') && (*c != ' ' || *c != '\n'))
            {
                errcp(ln);
            }
            else if (*c == ' ' || *c == '\n')
            {
                integer[--i] = '\0';
                break;
            }
            *cread = read(fd, c, 1);
            j++;
        }
}

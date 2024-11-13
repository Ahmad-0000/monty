#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(char **linearray, stack_t **rear, unsigned int line_number);
} instr_t;
extern FILE *fd;

/*              Opcode Functions                */

void push(char **linearray, stack_t **rear, unsigned int line_num);
void pall(char **linearray, stack_t **rear, unsigned int line_num);
void pint(stack_t **stack_head, unsigned int line_num);
void pop(stack_t **stack_head, unsigned int line_num);
void swap(stack_t **stack_head, unsigned int line_num);
void add(stack_t **stack_head, unsigned int line_num);
void nop(stack_t **stack_head, unsigned int line_num);
void sub(stack_t **stack_head, unsigned int line_num);
void divide(stack_t **stack_head, unsigned int line_num);
void mul(stack_t **stack_head, unsigned int line_num);
void mod(stack_t **stack_head, unsigned int line_num);
void pchar(stack_t **stack_head, unsigned int line_num);
void pstr(stack_t **stack_head, unsigned int line_num);
void rotl(stack_t **stack_head, unsigned int line_num);
void rotr(stack_t **stack_head, unsigned int line_num);

/*              Helping Functions               */

char skip_before(char c, int *char_read, unsigned int *line_num);
char skip_after(char c, int *char_read);
void fill(int n, char *opcode);
void exec(char **linearray, unsigned int linenum, stack_t **rear);
void fill_integer(char *integer);

/*              Helping Functions 2             */
unsigned int get_opcode(char *opcode, char c, int i, int *char_read);
int get_neg(char *integer, char *c, char *j, unsigned int line_num, int *i);
int get_pos(char *integer, char *c, char *j, unsigned int line_num, int *i);
void get_all(char *integer, char *c, int *cread, char j,int i, unsigned int ln);

/*              Error Messages Functions                */

void errno(unsigned int line_num, char opcode[]);
void errnf(void);
void errco(char *filename);
void errcp(unsigned int line_num);
void errcm(void);

/*              Error Messages Functions 2              */

void errcpi(unsigned int line_num);
void errcs(unsigned int line_num);
void errca(unsigned int line_num);
void errcsb(unsigned int line_num);

/*              Error Messages Functions 3               */

void errcd(unsigned int line_num);
void errcd2(unsigned int line_num);
void errcmu(unsigned int line_num);
void errcmo(unsigned int line_num);
void errcpc(unsigned int line_num);

/*              Error Messages Functions 4              */

void errcpc2(unsigned int line_num);

char **strtow(char *);
void freewarray(char **warray);
void freestack(stack_t *head);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#endif

#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* opcodes*/
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);

void _pint(stack_t **doubly, unsigned int cline);
void _pop(stack_t **doubly, unsigned int cline);
void _swap(stack_t **doubly, unsigned int cline);

void _add(stack_t **doubly, unsigned int cline);
void _nop(stack_t **doubly, unsigned int cline);
void _sub(stack_t **doubly, unsigned int cline);
void _div(stack_t **doubly, unsigned int cline);
void _mul(stack_t **doubly, unsigned int cline);
void _mod(stack_t **doubly, unsigned int cline);

void _pchar(stack_t **doubly, unsigned int cline);
void _pstr(stack_t **doubly, unsigned int cline);
void _rotl(stack_t **doubly, unsigned int cline);
void _rotr(stack_t **doubly, unsigned int cline);

void _stack(stack_t **doubly, unsigned int cline);
void _queue(stack_t **doubly, unsigned int cline);

void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/*functions*/
int _strchr(char *str, char chr);
int _strcmp(char *str1, char *str2);
char *_strtokenize(char *str, char *delim);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);


/**
 * struct global_s - global structure to use in the function
 * @lifo: is stack or queue
 * @cline: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: stores the input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_s
{
	int lifo;
	unsigned int cline;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

extern global_t varfile;

/**
 * struct local_s - local structure to use in the function
 * @arg: value of the param
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct local_s
{
	int lifi;
	char *arg;
	FILE *file;
	char *content;
}  local_t;

/* functions to handle doubly linked list*/
stack_t *_doublynode_end(stack_t **head, const int n);
stack_t *_doublynode(stack_t **head, const int n);

void free_list(stack_t *head);
void (*f)(stack_t **stack, unsigned int line_number);
void free_varfile(void);
void start_varfile(FILE *fd);
FILE *check_file(int argc, char *argv[]);
#endif

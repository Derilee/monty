#include "monty.h"
/**
 * _queue - function that sets format of data
 *          to queue(FIFI/LILO)
 * @doubly: head of the linked list
 * @cline: line number
 */
void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	varfile.lifo = 0;
}

/**
 * _stack - function that sets format of data
 *          to stack (LIFO/FILO)
 * @doubly: linked list head
 * @cline: line number
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	varfile.lifo = 1;
}

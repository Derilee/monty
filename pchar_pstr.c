#include "monty.h"
/**
 * _mod - function that computes the division of the second element
 *        by the top element of the stack
 * @doubly: head of the linked list
 * @cline: line number
 */

void _mod(stack_t **doubly, unsigned int cline)
{
	int index = 0;
	stack_t *element = NULL;

	element = *doubly;

	for (; element != NULL; element = element->next, index++)
		;

	if (index < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", cline);
		free_varfile();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_varfile();
		exit(EXIT_FAILURE);
	}
	element = (*doubly)->next;
	element->n %= (*doubly)->n;
	_pop(doubly, cline);
}
/**
 * _pstr - prints the string of the stack
 * @doubly: head of the linked list
 * @cline: line number
 */
void _pstr(stack_t **doubly, unsigned int cline)
{
	stack_t *str;
	(void)cline;

	str = *doubly;

	while (str && str->n > 0 && str->n < 128)
	{
		printf("%c", str->n);
		str = str->next;
	}

	printf("\n");
}
/**
 * _pchar - print the char value of the first element
 * @doubly: head of the linked list
 * @cline: line number
 */
void _pchar(stack_t **doubly, unsigned int cline)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", cline);
		free_varfile();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", cline);
		free_varfile();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}

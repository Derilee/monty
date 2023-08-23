#include "monty.h"
/**
 * _push - pushes an element to the stack
 * @doubly: head of the linked list
 * @cline: line number
 */
void _push(stack_t **doubly, unsigned int cline)
{
	int num, index;

	if (!varfile.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_varfile();
		exit(EXIT_FAILURE);
	}

	for (index = 0; varfile.arg[index] != '\0'; index++)
	{
		if (!isdigit(varfile.arg[index]) && varfile.arg[index] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_varfile();
			exit(EXIT_FAILURE);
		}
	}

	num = atoi(varfile.arg);

	if (varfile.lifo == 1)
		_doublynode(doubly, num);
	else
		_doublynode_end(doubly, num);
}

/**
 * _pall - prints all values on the stack
 * @doubly: head of the linked list
 * @cline: line numbers
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 * @doubly: head of the linked list
 * @cline: line number
 */
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_varfile();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * _pop - removes the top element of the stack
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *index;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_varfile();
		exit(EXIT_FAILURE);
	}
	index = *doubly;
	*doubly = (*doubly)->next;
	free(index);
}


/**
 * _swap - swaps the top two elements of the stack
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _swap(stack_t **doubly, unsigned int cline)
{
	int num = 0;
	stack_t *index = NULL;

	index = *doubly;

	for (; index != NULL; index = index->next, num++)
		;

	if (num < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_varfile();
		exit(EXIT_FAILURE);
	}

	index = *doubly;
	*doubly = (*doubly)->next;
	index->next = (*doubly)->next;
	index->prev = *doubly;
	(*doubly)->next = index;
	(*doubly)->prev = NULL;
}

#include "monty.h"
/**
 *_doublynode_end - add a note at the end of the doubly link list
 *@head: first position of the linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *_doublynode_end(stack_t **head, const int n)
{
	stack_t *temp, *index;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_varfile();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	index = *head;
	while (index->next)
		index = index->next;
	temp->next = index->next;
	temp->prev = index;
	index->next = temp;
	return (index->next);
}

/**
 *_doublynode - add a note at the begining of the doubly link list
 *@head: first position of the linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *_doublynode(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_varfile();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

/**
 * free_list - frees the doubly linked list
 * @head: head of the list
 * Return: nothing
 */
void free_list(stack_t *head)
{
	stack_t *buf;

	while ((buf = head) != NULL)
	{
		head = head->next;
		free(buf);
	}
}

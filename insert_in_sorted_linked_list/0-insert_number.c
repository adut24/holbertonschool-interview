#include "lists.h"

/**
 * insert_node - Inserts a new node into a sorted singly linked list.
 *
 * @head: A pointer to the head of the linked list.
 * @number: The number to insert into the linked list.
 *
 * Return: A pointer to the new node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = NULL, *newNode = NULL;

	if (!head)
		return (NULL);

	node = *head;
	newNode = malloc(sizeof(listint_t));

	if (!newNode)
		return (NULL);
	newNode->n = number;
	if (!node)
	{
		*head = newNode;
		return (newNode);
	}
	while (node)
	{
		if (node->next && number > node->next->n)
			node = node->next;
		else
			break;
	}
	if (node != *head)
	{
		if (node->next)
		{
			newNode->next = node->next;
			node->next = newNode;
		}
		else
			node->next = newNode;
	}
	else
	{
		newNode->next = node;
		*head = newNode;
	}
	return (newNode);
}

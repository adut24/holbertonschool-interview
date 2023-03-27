#include "lists.h"

/**
 * insert_node - insert an element inside a sorted singly linked list
 * @head: start of the linked list
 * @number: number to insert in the linked list
 * Return: the address of the new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	if (!head)
		return (NULL);

	listint_t *node = *head, *newNode = malloc(sizeof(listint_t));
	if (!newNode)
		return (NULL);
	newNode->n = number;
	if (!node)
	{
		node = newNode;
		return newNode;
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

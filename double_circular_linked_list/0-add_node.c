#include "list.h"

/**
 * @brief
 *
 * @list: Double linked list
 * @str: string to copy
 * Return:
 */
List *add_node_end(List **list, char *str)
{
	static List *firstNode = NULL;
	static List *lastNode = NULL;
	List *newNode = NULL, *head = NULL;

	if (!list || !*str)
		return (NULL);

	newNode = create_node(str);
	if (!newNode)
		return (NULL);

	if (!*list)
	{
		*list = newNode;
		firstNode = newNode;
	}
	else
	{
		head = *list;

		while (head != lastNode)
			head = head->next;

		head->next = newNode;
		newNode->prev = head;
		newNode->next = firstNode;
		firstNode->prev = newNode;
	}
	lastNode = newNode;
	return (newNode);
}

List *add_node_begin(List **list, char *str)
{
	static List *startNode = NULL;
	static List *endNode = NULL;
	List *newNode = NULL, *head = NULL;

	if (!list || !*str)
		return (NULL);

	newNode = create_node(str);
	if (!newNode)
		return (NULL);

	if (!*list)
	{
		*list = newNode;
		endNode = newNode;
	}
	else
	{
		head = *list;
		while (head != startNode)
			head = head->prev;
		head->prev = newNode;
		newNode->next = head;
		endNode->next = newNode;
		newNode->prev = endNode;
	}
	startNode = newNode;
	*list = startNode;
	return (newNode);
}

/**
 * create_node - creates a new node in the list
 * @str: string to copy in the node
 * Return: NULL in case of failure or the new node
 */
List *create_node(char *str)
{
	List *node = NULL;

	if (!*str)
		return (NULL);

	node = malloc(sizeof(List));

	if (!node)
		return (NULL);

	node->next = NULL;
	node->prev = NULL;
	node->str = strdup(str);

	return (node);
}

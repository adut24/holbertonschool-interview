#include "lists.h"

/**
 * check_cycle - Check if the linked list contains a loop or not
 * @list: linked list
 * Return: 1 if there's a loop or 0 if not
*/
int check_cycle(listint_t *list)
{
	address_t *nodes_address = NULL;

	if (!list)
		return (0);

	while (list)
	{
		if (!add_address(&nodes_address, list))
			return (1);
		list = list->next;
	}
	return (0);
}

/**
 * add_address - add the address of the node and verify it's not in the list
 * @addresses: linked list of the addresses
 * @list: node to check
 * Return: NULL if the address is in the list or the address of the new node
*/
address_t *add_address(address_t **addresses, listint_t *list)
{
	address_t *node = NULL, *head = *addresses;

	if (!*addresses)
	{
		node = malloc(sizeof(address_t));
		if (!node)
			return (NULL);

		node->address = list;
		node->next = NULL;
		*addresses = node;
		return (node);
	}

	while (head->next)
	{
		if (head->address == list)
			return (NULL);
		head = head->next;
	}
	node = malloc(sizeof(address_t));
	if (!node)
		return (NULL);

	node->address = list;
	node->next = NULL;
	head->next = node;

	return (node);
}

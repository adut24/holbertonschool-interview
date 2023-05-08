#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/**
 * struct address_s - singly linked list
 * @address: pointer to a node of struct listint_s
 * @next: pointer to the next node
 *
 * Description: singly linked list node structure
 * containing the addresses of the node from struct listint_s
 */
typedef struct address_s
{
	struct listint_s *address;
	struct address_s *next;
} address_t;

size_t print_listint(const listint_t *h);
listint_t *add_nodeint(listint_t **head, const int n);
void free_listint(listint_t *head);
int check_cycle(listint_t *list);
address_t *add_address(address_t **addresses, listint_t *list);

#endif /* LISTS_H */

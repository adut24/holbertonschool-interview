#include "lists.h"

/**
 * is_palindrome - checks if a linked list is a palindrome
 * @head: linked list
 * Return: 1 if it's a palindrome or 0 if not.
 */
int is_palindrome(listint_t **head)
{
	return (check_linked_list(head, *head));
}

/**
 * check_linked_list - checks if a linked list is a palindrome
 * @left: linked list
 * @right: pointer to a node
 * Return: 1 if it's a palindrome or 0 if not.
 */
int check_linked_list(listint_t **left, listint_t *right)
{
	int isPal;

	if (!right)
		return (1);

	isPal = check_linked_list(left, right->next);

	if (!isPal)
		return (0);

	if ((*left)->n != right->n)
		return (0);

	*left = (*left)->next;

	return (isPal);
}

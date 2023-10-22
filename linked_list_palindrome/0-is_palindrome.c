#include "lists.h"

/**
 * is_palindrome - checks if a linked list is a palindrome
 *
 * @head: linked list
 *
 * Return: 1 if it is a palindrome, 0 if it is not a palindrome
 */
int is_palindrome(listint_t **head)
{
	return (check_linked_list(head, *head));
}

/**
 * check_linked_list - checks the linked list recursively
 *
 * @left: pointer to the left node
 * @right: pointer to the right node
 *
 * Return: 1 if it is a palindrome, 0 if it is not a palindrome
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

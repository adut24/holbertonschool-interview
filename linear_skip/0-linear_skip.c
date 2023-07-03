#include "search.h"

/***
 * linear_skip - Checks if a value is inside
 * @head: skip list to check
 * @value: value to find
 * Return: the node with the value or NULL if failure
*/
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *fast = head->express, *prev = head;

	if (!head)
		return (NULL);

	while (fast->express)
	{
		printf("Value checked at index [%ld] = [%d]\n", fast->index, fast->n);
		if (fast->n >= value)
			break;
		prev = fast;
		fast = fast->express;
	}
	printf("Value found between indexes [%ld] and [%ld]\n", prev->index,
	fast->index);
	while (prev->next)
	{
		printf("Value checked at index [%ld] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}

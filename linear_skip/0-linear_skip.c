#include "search.h"

/**
 * linear_skip - Checks if a value is inside
 * @head: skip list to check
 * @value: value to find
 * Return: the node with the value or NULL if failure
*/
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *fast = NULL, *prev = head;

	if (!head)
		return (NULL);

	fast = head->express;

	while (fast->next)
	{
		printf("Value checked at index [%ld] = [%d]\n", fast->index, fast->n);
		if (fast->n > value)
			break;
		prev = fast;
		fast = fast->express;
		if (!fast)
		{
			fast = prev;
			while (fast->next)
				fast = fast->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n", prev->index,
	fast->index);

	while (prev)
	{
		printf("Value checked at index [%ld] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}

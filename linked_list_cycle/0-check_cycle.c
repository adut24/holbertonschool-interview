#include "lists.h"

/**
 * check_cycle - Check if the linked list contains a loop or not
 * @list: linked list
 * Return: 1 if there's a loop or 0 if not
*/
int check_cycle(listint_t *list)
{
	listint_t *slow = list, *fast = list;

	if (!list)
		return (0);

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return (1);
	}
	return (0);
}

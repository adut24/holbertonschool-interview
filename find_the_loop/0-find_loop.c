#include "lists.h"

/**
 * find_listint_loop - finds if there's a loop in a Linked List
 * @head: Linked List
 * Return: NULL if no loop or the address of the node where the loop starts
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = NULL, *fast = NULL;

	if (!head)
		return (NULL);

	slow = head;
	fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = head;

			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);
		}
	}
	return (NULL);
}

#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: The address of the pointer to the first element of the list
 *
 * Return: Address of the node where the loop starts, or NULL if no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	if (head == NULL)
		return (NULL);

	while (fast != NULL && fast->next != NULL)
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

#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 *@list: A pointer to the head of the skip list to search in
 *@value: Is the value to search for
 Return: A pointer on the first node where value is located or NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp = list;
	skiplist_t *lastPos = NULL;

	if (!list)
		return (NULL);

	while (temp->express && temp->express->n < value)
	{
		printf("Value checked at index [%zu] = [%d]\n",
			temp->express->index, temp->express->n);
		temp = temp->express;
	}
	lastPos = temp;
	if (temp->express)
	{
		temp = temp->express;
		printf("Value checked at index [%zu] = [%d]\n", temp->index, temp->n);
		printf("Value found between indexes [%zu] and [%zu]\n",
			lastPos->index, temp->index);
	}
	else
	{
		skiplist_t *end = temp;
		while (end->next)
			end = end->next;
		printf("Value found between indexes [%zu] and [%zu]\n",
			lastPos->index, end->index);
		temp = end;
	}
	while (lastPos && lastPos->index <= temp->index)
	{
		printf("Value checked at index [%zu] = [%d]\n",
			lastPos->index, lastPos->n);
		if (lastPos->n == value)
			return (lastPos);
		lastPos = lastPos->next;
	}
	return (NULL);
}

#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers
 * @line: points to an array of integers containing size elements
 * @size: Nomber of elements in the array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t i, pos = 0;
	int temp[size];

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	for (i = 0; i < size; i++)
		temp[i] = 0;

	if (direction == SLIDE_LEFT)
	{
		/* Move values != 0 in temp array */
		for (i = 0; i < size; i++)
			if (line[i] != 0)
				temp[pos++] = line[i];

		/* Merge values */
		for (i = 0; i < size - 1; i++)
		{
			if (temp[i] == temp[i + 1] && temp[i] != 0)
			{
				temp[i] *= 2;
				temp[i + 1] = 0;
			}
		}
		pos = 0;
		for (i = 0; i < size; i++)
			if (temp[i] != 0)
				line[pos++] = temp[i];

		/* Fill remaining with zeros */
		while (pos < size)
			line[pos++] = 0;
	}
	else if (direction == SLIDE_RIGHT)
	{
		pos = size - 1;

		/* Move values != 0 in temp array */
		for (i = size; i > 0; i--)
			if (line[i - 1] != 0)
				temp[pos--] = line[i - 1];

		/* Merge values */
		for (i = size - 1; i > 0; i--)
		{
			if (temp[i] == temp[i - 1] && temp[i] != 0)
			{
				temp[i] *= 2;
				temp[i - 1] = 0;
			}
		}
		pos = size - 1;
		for (i = size; i > 0; i--)
			if (temp[i - 1] != 0)
				line[pos--] = temp[i - 1];

		/* Fill remaining with zeros */
		while ((int)pos >= 0)
			line[pos--] = 0;
	}
	return (1);
}

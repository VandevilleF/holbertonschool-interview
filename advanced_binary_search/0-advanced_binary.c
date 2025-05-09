#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints the current array being searched
 * @array: pointer to the array
 * @start: starting index
 * @end: ending index
 */
void print_array(int *array, int start, int end)
{
	int i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i < end)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search_recursive - Recursive function to find the first occurrence
 * @array: pointer to array
 * @start: starting index
 * @end: ending index
 * @value: value to search
 *
 * Return: index of first occurrence or -1
 */
int binary_search_recursive(int *array, int start, int end, int value)
{
	int mid;

	if (start > end)
		return (-1);

	print_array(array, start, end);

	mid = start + (end - start) / 2;

	if (array[mid] == value)
	{
		if (mid == start || array[mid - 1] != value)
			return (mid);
		else
			return (binary_search_recursive(array, start, mid, value));
	}
	else if (array[mid] < value)
	{
		return (binary_search_recursive(array, mid + 1, end, value));
	}
	else
	{
		return (binary_search_recursive(array, start, mid - 1, value));
	}
}

/**
 * advanced_binary - Searches for the 1st occurrence of a value
 * @array: pointer to array
 * @size: number of elements
 * @value: value to search
 *
 * Return: index of first occurrence or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_search_recursive(array, 0, (int)size - 1, value));
}

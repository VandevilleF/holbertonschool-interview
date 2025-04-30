#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * sift_down - Fixes a heap whose root element might violate heap property
 * @array: The array to be sorted
 * @size: Size of the array
 * @root: Index of the root element of the heap
 * @max_size: Original size of the array (for printing)
 */
void sift_down(int *array, size_t size, size_t root, size_t max_size)
{
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    /* Check if left child is larger than root */
    if (left < size && array[left] > array[largest])
        largest = left;

    /* Check if right child is larger than largest so far */
    if (right < size && array[right] > array[largest])
        largest = right;

    /* If largest is not root, swap and continue sifting down */
    if (largest != root)
    {
        swap(&array[root], &array[largest]);
        print_array(array, max_size);
        sift_down(array, size, largest, max_size);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (array == NULL || size < 2)
        return;

    /* Build max heap */
    for (i = size / 2 - 1; i >= 0; i--)
        sift_down(array, size, i, size);

    /* Extract elements from heap one by one */
    for (i = size - 1; i > 0; i--)
    {
        /* Move current root to the end */
        swap(&array[0], &array[i]);
        print_array(array, size);

        /* Call sift_down on the reduced heap */
        sift_down(array, i, 0, size);
    }
}

#include "sort.h"

/**
 * swap_integers - Swaps two integer values
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_integers(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Fixes the heap property in a subtree
 *
 * @array: Pointer to the array
 * @start: Index of the root of the subtree
 * @end: Index of the last element in the array
 * @size: Size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child = 2 * root + 1;

	while (child <= end)
	{
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;
		if (array[root] < array[child])
		{
			swap_integers(&array[root], &array[child]);
			print_array(array, size);
			root = child;
			child = 2 * root + 1;
		}
		else
			return;
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the Heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end = size - 1;

	if (!array || size < 2)
		return;

	for (int i = (end - 1) / 2; i >= 0; i--)
		sift_down(array, i, end, size);

	while (end > 0)
	{
		swap_integers(&array[end], &array[0]);
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}

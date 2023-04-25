#include "sort.h"
#include <stdlib.h>

/**
 * merge - Merges two sorted subarrays into one sorted array
 * @array: The array containing the subarrays to merge
 * @start: The starting index of the first subarray
 * @mid: The ending index of the first subarray
 * @end: The ending index of the second subarray
 * @size: The size of the array
 */
void merge(int *array, size_t start, size_t mid, size_t end, size_t size)
{
	size_t i = start, j = mid + 1, k = 0;
	int *temp = malloc(sizeof(int) * size);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	while (i <= mid && j <= end)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];

	while (j <= end)
		temp[k++] = array[j++];

	for (i = start, k = 0; i <= end; i++, k++)
		array[i] = temp[k];

	free(temp);

	printf("[Done]: ");
	print_array(array + start, end - start + 1);
}

/**
 * merge_sort_recursive - Recursively divides the array into subarrays and
 *                        sorts them using merge sort
 * @array: The array of integers to sort
 * @start: The starting index of the subarray to sort
 * @end: The ending index of the subarray to sort
 * @size: The size of the array
 */
void merge_sort_recursive(int *array, size_t start, size_t end, size_t size)
{
	if (start < end)
	{
		size_t mid = start + (end - start) / 2;

		merge_sort_recursive(array, start, mid, size);
		merge_sort_recursive(array, mid + 1, end, size);
		merge(array, start, mid, end, size);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              Merge sort algorithm
 * @array: The array of integers to sort
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, 0, size - 1, size);
}

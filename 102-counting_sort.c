#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending
 *                 order using the Counting sort algorithm
 * @array: pointer to the array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max_value = 0, i;
	int *count_array, *sorted_array;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
		if (array[i] > max_value)
			max_value = array[i];

	count_array = malloc(sizeof(int) * (max_value + 1));
	if (count_array == NULL)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
		free(count_array);
		return;
	}

	initialize_count_array(count_array, max_value + 1);

	build_count_array(array, size, count_array, max_value + 1);

	printf("Counting array:");
	print_array(count_array, max_value + 1);

	accumulate_count_array(count_array, max_value + 1);

	fill_sorted_array(array, size, sorted_array, count_array);

	copy_sorted_array(sorted_array, array, size);

	free(count_array);
	free(sorted_array);
}

/**
 * initialize_count_array - initializes the counting array with zeros
 * @count_array: pointer to the counting array
 * @size: size of the counting array
 */
void initialize_count_array(int *count_array, int size)
{
	int i;

	for (i = 0; i < size; i++)
		count_array[i] = 0;
}

/**
 * build_count_array - builds the counting array
 * @array: pointer to the array to be sorted
 * @size: size of the array
 * @count_array: pointer to the counting array
 * @count_size: size of the counting array
 */
void build_count_array(int *array, size_t size, int *count_array, int count_size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;
}

/**
 * accumulate_count_array - accumulates the counting array
 * @count_array: pointer to the counting array
 * @count_size: size of the counting array
 */
void accumulate_count_array(int *count_array, int count_size)
{
	int i;

	for (i = 1; i < count_size; i++)
		count_array[i] += count_array[i - 1];
}

/**
 * fill_sorted_array - fills the sorted array using the counting array
 * @array: pointer to the array to be sorted
 * @size: size of the array
 * @sorted_array: pointer to the sorted array
 * @count_array: pointer to the counting array
 */
void fill_sorted_array(int *array, size_t size, int *sorted_array, int *count_array)
{
	int i;

	for (i = size - 1; i >= 0; i--)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
}

/**
 * copy_sorted_array - copies the sorted array to the input array
 * @sorted_array: pointer to the sorted array
 * @array: pointer to the input array
 * @size: size of the arrays
*/

void copy_sorted_array(int *sorted_array, int *array, size_t size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];
}

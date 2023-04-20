#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using
 *              the Quick sort algorithm.
 *
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	q_sort(array, 0, size - 1, size);
}

/**
 * q_sort - sorts a partition of an array of integers in ascending order
 *          using the Quick sort algorithm.
 *
 * @array: Pointer to the array of integers.
 * @lo: Lower bound of the partition.
 * @hi: Upper bound of the partition.
 * @size: Size of the array.
 *
 * Return: void
 */
void q_sort(int *array, int lo, int hi, size_t size)
{
	int pivot = 0;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		q_sort(array, lo, pivot - 1, size);
		q_sort(array, pivot + 1, hi, size);
	}
}

/**
 * partition - partitions a subarray of an array of integers
 *             in ascending order using the Lomuto scheme.
 *
 * @array: Pointer to the array of integers.
 * @lo: Lower bound of the subarray.
 * @hi: Upper bound of the subarray.
 * @size: Size of the array.
 *
 * Return: The final index of the pivot element.
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi], i = lo, j = lo;

	for (; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > pivot)
	{
		swap(&array[i], &array[hi]);
		print_array(array, size);
	}

	return (i);
}

/**
 * swap - swaps two integers in an array.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

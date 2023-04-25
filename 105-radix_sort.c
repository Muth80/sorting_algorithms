#include "sort.h"
#include <stdlib.h>

/**
 * count_digits - Counts the number of digits in a number
 * @num: The number to count the digits of
 *
 * Return: The number of digits in num
 */
int count_digits(int num)
{
	int count = 0;

	while (num != 0)
	{
		num /= 10;
		++count;
	}

	return count;
}

/**
 * get_digit - Gets the digit at a specified position in a number
 * @num: The number to get the digit from
 * @pos: The position of the digit to get (0 is the rightmost digit)
 *
 * Return: The digit at the specified position
 */
int get_digit(int num, int pos)
{
	int i, digit;

	for (i = 0; i <= pos; i++)
	{
		digit = num % 10;
		num /= 10;
	}

	return digit;
}

/**
 * radix_sort - Sorts an array of integers in ascending
 *              order using the LSD radix sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max_digits = 0, i, j, k, digit;
	int **buckets = NULL, *bucket_sizes = NULL;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
	{
		if (count_digits(array[i]) > max_digits)
			max_digits = count_digits(array[i]);
	}

	buckets = malloc(10 * sizeof(int *));
	bucket_sizes = malloc(10 * sizeof(int));
	if (buckets == NULL || bucket_sizes == NULL)
		return;

	for (i = 0; i < 10; i++)
	{
		buckets[i] = malloc(size * sizeof(int));
		if (buckets[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(buckets[j]);
			free(buckets);
			free(bucket_sizes);
			return;
		}
		bucket_sizes[i] = 0;
	}

	bucket_sizes[i] = 0;
	{
		for (j = 0; j < (int)size; j++)
		{
			digit = get_digit(array[j], i);
			buckets[digit][bucket_sizes[digit]] = array[j];
			bucket_sizes[digit]++;
		}

		k = 0;
		for (j = 0; j < 10; j++)
		{
			for (digit = 0; digit < bucket_sizes[j]; digit++)
			{
				array[k] = buckets[j][digit];
				k++;
			}

			bucket_sizes[j] = 0;
		}

		print_array(array, size);
	}

	for (i = 0; i < 10; i++)
		free(buckets[i]);
	free(buckets);
	free(bucket_sizes);
}

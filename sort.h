#ifndef SORT_H
#define SORT_H

/* Libraries */
#include <stdlib.h>
#include <stdio.h>

/* Data Structures */
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Sorting Algorithms */
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort_list(listint_t **list);
void quick_sort_hoare(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t *node1, listint_t *node2);
int partition(int *array, int lo, int hi, size_t size);
void q_sort(int *array, int lo, int hi, size_t size);
void swap(int *a, int *b);
void copy_sorted_array(int *sorted_array, int *array, size_t size);
void fill_sorted_array(int *array, size_t size, int *sorted_array, int *count_array);
void accumulate_count_array(int *count_array, int count_size);
void build_count_array(int *array, size_t size, int *count_array, int count_size);
void initialize_count_array(int *count_array, int size);


/* Helper Functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif /* SORT_H */


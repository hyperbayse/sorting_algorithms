#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, int size);
void quick_sort(int *array, size_t size);
void sort_array(int *array, size_t low, size_t high, size_t size);
int partition(int array[], size_t low, size_t high, size_t size);
void swap(int *a, int *b);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
listint_t *create_listint(const int *array, size_t size);
void swap_nodes(listint_t *a, listint_t *b);
listint_t *tail_reversal(listint_t *head, listint_t *tail, listint_t *list);
void cocktail_sort_list(listint_t **list);
void *_calloc(unsigned int nmemb, unsigned int size);
void counting_sort(int *array, size_t size);
void merge(int *arr, int *tmp, int start, int mid, int end);
void *_calloc(unsigned int nmemb, unsigned int size);
void mergesort(int *array, int *tmp, int start, int end);
void merge_sort(int *array, size_t size);


#endif

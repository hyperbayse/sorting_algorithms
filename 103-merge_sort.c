#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array and initializes it to 0
 * @nmemb: Number of elements
 * @size: Size of each element
 * Return: Pointer to the allocated memory, or NULL if failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		p[i] = 0;

	return (p);
}

/**
 * merge - Merges two halves of an array
 * @arr: Original array
 * @tmp: Temporary array for merging
 * @start: Start index of the first half
 * @mid: End index of the first half
 * @end: End index of the second half
 **/
void merge(int *arr, int *tmp, int start, int mid, int end)
{
	int size_left = mid - start + 1;
	int size_right = end - mid;
	int *array_left, *array_right;
	int left, right, i = start;

	array_left = &tmp[0];
	array_right = &tmp[size_right];

	for (left = 0; left < size_left; left++)
		array_left[left] = arr[start + left];

	for (right = 0; right < size_right; right++)
		array_right[right] = arr[mid + 1 + right];

	left = 0, right = 0, i = start;

	/* Merging tmp arrays into the main array */
	while (left < size_left && right < size_right)
	{
		if (array_left[left] <= array_right[right])
			arr[i] = array_left[left], left++;
		else
			arr[i] = array_right[right], right++;
		i++;
	}

	/* Merging remaining left array into the main array */
	while (left < size_left)
		arr[i] = array_left[left], left++, i++;

	/* Merging remaining right array into the main array */
	while (right < size_right)
		arr[i] = array_right[right], right++, i++;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_left, left);
	printf("[right]: ");
	print_array(array_right, right);
	printf("[Done]: ");
	print_array(&arr[start], left + right);
}

/**
 * mergesort - Recursive function to perform merge sort
 * @array: Array to be sorted
 * @tmp: Temporary array for merging
 * @start: Start index of the array
 * @end: End index of the array
 **/
void mergesort(int *array, int *tmp, int start, int end)
{
	int mid;

	mid = (start + end) / 2;

	if ((start + end) % 2 == 0)
		mid--;

	if (mid >= start)
	{
		mergesort(array, tmp, start, mid);
		mergesort(array, tmp, mid + 1, end);
		merge(array, tmp, start, mid, end);
	}
}

/**
 * merge_sort - Sorts an array of integers using the Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 **/
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = _calloc(size, sizeof(int));
	mergesort(array, tmp, 0, size - 1);
	free(tmp);
}

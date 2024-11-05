#include "sort.h"

/**
 * quick_sort - sorts a list with quick method
 * @array: array to be soted
 * @size: size of the array to be sorted
 * Return: success
 */

 void quick_sort(int *array, size_t size)
 {
	size_t part;

	if (size > 1)
	{
		part = partition(array, 0, size - 1);
		quick_sort(array, part);
		quick_sort(array + part + 1, size - part - 1);
	}
 }


/**
 * swap - switches two element
 * @a: elemant a
 * @b: element b
 * Return: success
 */
void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

/**
 * partition - that partition the array into sub-arrays
 * @start: pointer to the sub-array start partition
 * @end: point to the sub-array end partition
 * Return: pivot sorted position
 */
size_t partition(int *array, int start, int end)
{
	int i, j;
	int pivot;

	pivot = array[end];

	i = start - 1;

	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[j], &array[i]);
		}
	}
	swap(&array[i + 1], &array[end]);
	print_array(array, sizeof(array) - 1);
	return (i + 1);
}
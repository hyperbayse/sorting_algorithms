#include "sort.h"
#include <stdio.h>

/**
 * _calloc - Allocates memory for an array, setting its contents to 0
 * @nmemb: Number of elements
 * @size: Size of each element
 * Return: Pointer to the allocated memory, or NULL if failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
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
 * counting_sort - Sorts an array of integers using the counting sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int index, maximum = 0, *counter = NULL, *tmp = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum number in the array */
	for (i = 0; i < size; i++)
		if (array[i] > maximum)
			maximum = array[i];

	counter = _calloc(maximum + 1, sizeof(int));
	tmp = _calloc(size + 1, sizeof(int));

	/* Count the occurrences of each element in the array */
	for (i = 0; i < size; i++)
		counter[array[i]]++;

	/* Calculate and print the cumulative values */
	for (index = 1; index <= maximum; index++)
	{
		counter[index] += counter[index - 1];
		printf("%d", counter[index - 1]);
		if (index < maximum)
			printf(", ");
	}
	printf("\n");

	/* Create a new sorted array */
	for (i = 0; i < size; ++i)
	{
		tmp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}

	/* Copy the sorted array back to the original array */
	for (i = 0; i < size; i++)
		array[i] = tmp[i];

	free(tmp);
	free(counter);
}

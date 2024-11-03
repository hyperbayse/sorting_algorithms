#include "sort.h"

/**
 * selection_sort - sort an array with selection method
 * @array: array to be sorted
 * @size: size of array to be sorted
 * Return: success
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int x;

	for (i = 0; i < size; i++)
	{
		x = array[i];
		for (j = i; j < size; j++)
		{
			if (x > array[j])
			{
				x = array[j];
				array[j] = array[i];
				array[i] = x;
				print_array(array, size);
			}
		}
	}
}
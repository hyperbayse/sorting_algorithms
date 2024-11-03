#include "sort.h"

/**
 * bubble_sort - sort an array with bubble method
 * @array: array to be sorted
 * @size: size of array to be soted
 * Return: success
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, x;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if ((array[j] > array[j + 1]) && array[j + 1] != '\n')
			{
				x = array[j];
				array[j] = array[j + 1];
				array[j + 1] = x;
				j++;
				print_array(array, size);
			}
		}
	}
}

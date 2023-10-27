#include "sort.h"

/**
 * bubble_sort - Sorts an array using the bubble sort algorithm
 * @array: An array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing!
 */

void bubble_sort(int *array, size_t size)
{
	int temp, unsortedRange;
	int swapped;
	int i;

	if (size < 2)
		return;

	unsortedRange = size;
	do {
		swapped = 0;
		for (i = 0; i <= unsortedRange - 2; ++i)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped++;
				print_array(array, size);
			}
		}
		--unsortedRange;
	} while (swapped);
}

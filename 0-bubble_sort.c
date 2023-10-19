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
	size_t  i, j;
	int temp;
	int swap;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}

		if (swap == 0)
			break;
	}
}

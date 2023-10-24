#include "sort.h"
void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int high, int low);
void lomuto_sort(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array
 * @a: first interger
 * @b: second integer to be swapped with
 *
 * Return: Nothing!
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - implements the lomuto partition scheme
 * @array: The array of integers
 * @size: size of the array.
 * @high: The starting index
 * @low: The ending index
 *
 * Return: the new pivot index
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot, i, j;

	pivot = array + high;
	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap_ints(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > *pivot)
	{
		swap_ints(array + i, pivot);
		print_array(array, size);
	}
	return (i);
}

/**
 * lomuto_sort - Implement the quicksort algorithm
 * @array: An array of integers to sort
 * @size: The size of the array
 * @low: The starting index of the array
 * @high: The ending index of the array
 *
 * Return: Nothing!
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	int sort;

	if (high - low > 0)
	{
		sort = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, sort - 1);
		lomuto_sort(array, size, sort + 1, high);
	}
}

/**
 * quick_sort - Sort an array using the quick sort algorithm
 * @array: The unsorted array
 * @size: Size of the array
 *
 * Return: Nothing!
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	lomuto_sort(array, size, 0, size - 1);
}

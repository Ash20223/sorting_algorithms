#include "sort.h"

void swap_integers(int *a, int *b);
int lomuto_part(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_integers - swap two ints in an array
 * @a: first int to swap
 * @b: second int to swap
 */
void swap_integers(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_part - Order a subset of an array of ints according to
 *                    the lomuto partition scheme
 * @array: array of ints
 * @size: size of the array
 * @left: starting index of the subset to order
 * @right: ending index of the subset to order
 * Return: final partition index
 */
int lomuto_part(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_integers(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_integers(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - implement quicksort algorithm through recursion
 * @array: array of integers to sort
 * @size: size of the array
 * @left: starting index of the array partition to order
 * @right: ending index of the array partition to order
 * Description: uses Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_part(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - sort array of ints in ascending
 *              order using quicksort algorithm
 * @array: array of ints
 * @size: size of array
 * Description: uses Lomuto partition scheme - prints
 *              the array after each swap of two elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

#include "sort.h"

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
 * selection_sort - Sort array of ints in ascending order
 *                  using the selection sort algorithm
 * @array: array of ints
 * @size: size of the array
 * Description: prints array after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_integers(array + i, min);
			print_array(array, size);
		}
	}
}

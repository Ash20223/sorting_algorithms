#include "sort.h"

/**
 *  * gett_max - get the maximum value in array of the ints
 *   * @array: array of ints
 *    * @size: size of the array
 *     * Return: maximum int in the array
 *      */
int gett_max(int *array, int size)
{
		int max, i;

			for (max = array[0], i = 1; i < size; i++)
					{
								if (array[i] > max)
												max = array[i];
									}

				return (max);
}

/**
 *  * counting_sort - sort array of ints in ascending order
 *   *                 using the counting sort algorithm
 *    * @array: array of the ints
 *     * @size: size of the array
 *      * Description: prints counting array after setting up
 *       */
void counting_sort(int *array, size_t size)
{
		int *count, *sorted, max, i;

			if (array == NULL || size < 2)
						return;

				sorted = malloc(sizeof(int) * size);
					if (sorted == NULL)
								return;
						max = gett_max(array, size);
							count = malloc(sizeof(int) * (max + 1));
								if (count == NULL)
										{
													free(sorted);
															return;
																}

									for (i = 0; i < (max + 1); i++)
												count[i] = 0;
										for (i = 0; i < (int)size; i++)
													count[array[i]] += 1;
											for (i = 0; i < (max + 1); i++)
														count[i] += count[i - 1];
												print_array(count, max + 1);

													for (i = 0; i < (int)size; i++)
															{
																		sorted[count[array[i]] - 1] = array[i];
																				count[array[i]] -= 1;
																					}

														for (i = 0; i < (int)size; i++)
																	array[i] = sorted[i];

															free(sorted);
																free(count);
}

#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @bek: The first integer to swap.
 * @len: The second integer to swap.
 */
void swap_ints(int *bek, int *len)
{
	int tmp;

	tmp = *bek;
	*bek = *len;
	*len = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @bek_array: An array of integers.
 * @bek_size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *bek_array, size_t bek_size)
{
	int *bek_min;
	size_t i, j;

	if (bek_array == NULL || bek_size < 2)
		return;

	for (i = 0; i < bek_size - 1; i++)
	{
		bek_min = array + i;
		for (j = i + 1; j < size; j++)
			bek_min = (bek_array[j] < *bek_min) ? (bek_array + j) : bek_min;

		if ((bek_array + i) != bek_min)
		{
			swap_ints(bek_array + i, bek_min);
			print_array(bek_array, bek_size);
		}
	}
}

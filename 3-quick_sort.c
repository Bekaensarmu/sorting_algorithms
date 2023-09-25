#include "sort.h"

void swap_ints(int *bek, int *len);
int lomuto_partition(int *len_array, size_t len_size, int len_left, int len_right);
void lomuto_sort(int *len_array, size_t len_size, int len_left, int len_right);
void quick_sort(int *len_array, size_t len_size);

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
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @len_array: The array of integers.
 * @len_size: The size of the array.
 * @len_left: The starting index of the subset to order.
 * @len_right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *len_array, size_t len_size, int len_left, int len_right)
{
	int *pivot, above, below;

	pivot = len_array + len_right;
	for (above = below = len_left; below < len_right; below++)
	{
		if (len_array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(len_array + below, array + above);
				print_array(len_array, len_size);
			}
			above++;
		}
	}

	if (len_array[above] > *pivot)
	{
		swap_ints(len_array + above, pivot);
		print_array(len_array, len_size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @len_array: An array of integers to sort.
 * @len_size: The size of the array.
 * @len_left: The starting index of the array partition to order.
 * @len_right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *len_array, size_t len_size, int len_left, int len_right)
{
	int part;

	if (len_right - len_left > 0)
	{
		part = lomuto_partition(len_array, len_size, len_left, len_right);
		lomuto_sort(len_array, len_size, len_left, part - 1);
		lomuto_sort(len_array, len_size, part + 1, len_right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @len_array: An array of integers.
 * @len_size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *len_array, size_t len_size)
{
	if (len_array == NULL || len_size < 2)
		return;

	lomuto_sort(len_array, len_size, 0, len_size - 1);
}

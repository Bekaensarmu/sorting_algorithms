#include "sort.h"

void swap_ints(int *x, int *y);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t bek_left, bek_right, bek_large;

	bek_left = 2 * root + 1;
	bek_right = 2 * root + 2;
	bek_large = root;

	if (bek_left < base && array[bek_left] > array[bek_large])
		bek_large = bek_left;
	if (bek_right < base && array[bek_right] > array[bek_large])
		bek_large = bek_right;

	if (bek_large != root)
	{
		swap_ints(array + root, array + bek_large);
		print_array(array, size);
		max_heapify(array, size, base, bek_large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int a;

	if (array == NULL || size < 2)
		return;

	for (a = (size / 2) - 1; a >= 0; a--)
		max_heapify(array, size, size, a);

	for (a = size - 1; a > 0; a--)
	{
		swap_ints(array, array + a);
		print_array(array, size);
		max_heapify(array, size, a, 0);
	}
}

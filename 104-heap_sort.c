#include "sort.h"
/**
  * BKheap_sort - heap sort algorithm
  * @array: array to sort
  * @size: size of array
  */
void BKheap_sort(int *array, size_t size)
{
	int i, len_tmp;

	for (i = size / 2 - 1; i >= 0; i--)
		BKheapify(array, i, size, size);
	for (i = size -1; i >=0; i--)
	{
		len_tmp = array[0];
		array[0] = array[i];
		array[i] = len_tmp;
		print_array(array, size);
		BKheapify(array, i, 0, size);
	}
}
void BKheapify(int *array, int idx, int idx2, size_t size)
{
	int len_max = idx2;
	int len_left = 2 * idx2 + 1;
	int len_right = 2 * idx2 + 2;
	int len_tmp;

	if (len_left < idx && array[len_left] > array[len_max])
		len_max = len_left;
	if (len_right < idx && array[len_right] > array[len_max])
		len_max = len_right;
	if (len_max != idx2)
	{
		len_tmp = array[idx2];
		array[idx2] = array[len_max];
		array[len_max] = len_tmp;
		print_array(array, size);
		BKheapify(array, idx, len_max, size);
	}
}

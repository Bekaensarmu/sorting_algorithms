#include "sort.h"
/**
  * quick_sort - quicksort algorithm
  * @len_array: array to be sorted
  * @bek_size: size of array
  */
void quick_sort(int *len_array, size_t bek_size)
{
	if (len_array == NULL || bek_size <= 1)
		return;
	sort_alg(len_array, 0, bek_size - 1, bek_size);
}

/**
  * sort_alg - recursive sorting algorithm
  * @arr: array
  * @left: leftmost index
  * @right: rightmost index
  * @size: full size of array
  */
void sort_alg(int *arr, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = split(arr, left, right, size);
		sort_alg(arr, left, pivot - 1, size);
		sort_alg(arr, pivot + 1, right, size);
	}
}

/**
  * split - split array
  * @arr: array
  * @left: leftmost index
  * @right: rightmost index
  * @size: full array size
  * Return: pivot index
  */
int split(int *arr, int left, int right, size_t size)
{
	int a, i2, pivot, tmp;

	pivot = arr[right];
	a = left;

	for (a2 = left; a2 < right; a2++)
	{
		if (arr[a2] < pivot)
		{
			if (a != a2)
			{
				tmp = arr[a2];
				arr[a2] = arr[a];
				arr[a] = tmp;
				print_array(arr, size);
			}
			a++;
		}
	}
	if (arr[a] != arr[right])
	{
		tmp = arr[a];
		arr[a] = arr[right];
		arr[right] = tmp;
		print_array(arr, size);
	}

	return (a);
}

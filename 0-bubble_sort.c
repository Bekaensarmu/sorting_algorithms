#include "sort.h"
/**
 * bubble_sort - sort array lements from min to max value
 * @array: array
 * @bek: array size
 */
void bubble_sort(int *array, size_t bek)
{

	size_t i, index, tmp = 0;

	if (bek < 2)
		return;
	for (i = 0; i < bek; i++)
		for (index = 0; index < bek; index++)
		{
			if (array[index] > array[index + 1] && array[index + 1])
			{
			tmp = array[index];
			array[index] = array[index + 1];
			array[index + 1] = tmp;
			print_array(array, bek);
			}
		}
}

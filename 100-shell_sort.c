#include "sort.h"
/**
  * shell_sort - shell sort, knuth sequence
  * @array: array to be sorted
  * @size: size of array
  */
void shell_sort(int *array, size_t size)
{
	size_t knuth, bek_i, bek_i2;
	int bek_tmp;

	knuth = 1;
	while (knuth < size)
		knuth = (knuth * 3) + 1;
	knuth = (knuth - 1) / 3;
	while (knuth > 0)
	{
		for (bek_i = knuth; bek_i < size; bek_i++)
		{
			bek_tmp = array[bek_i];
			for (bek_i2 = bek_i; bek_i2 >= knuth && array[bek_i2 - knuth] > bek_tmp; bek_i2 -= knuth)
				array[bek_i2] = array[bek_i2 - knuth];
			array[bek_i2] = bek_tmp;
		}
		knuth = (knuth - 1) / 3;
		print_array(array, size);
	}
}

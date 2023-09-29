#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void counting_sort(int *array, size_t size)
{
	int x, y, *count_array, *aux;
	size_t a;

	if (!array || size < 2)
		return;
	x = array[0];
	for (a = 0; a < size; a++)
	{
		if (array[a] > x)
			x = array[a];
	}
	count_array = calloc((x + 1), sizeof(int));
	for (a = 0; a < size; a++)
	{
		count_array[array[a]]++;
	}
	for (y = 1; y < x; y++)
	{
		count_array[y + 1] += count_array[y];
	}
	print_array(count_array, x + 1);
	aux = malloc(sizeof(int) * size);
	for (a = 0; a < size; a++)
	{
		count_array[array[a]]--;
		aux[count_array[array[a]]] = array[a];
	}
	for (a = 0; a < size; a++)
	{
		array[a] = aux[a];
	}
	free(aux);
	free(count_array);
}

#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* BKMerge - sorts and merges the sub arrays
* @start: starting index
* @middle: end index
* @end: end index
* @dest: destination for the data
* @source: source of the data
*
* Return: void
*/
void BKMerge(size_t start, size_t middle, size_t end, int *dest, int *source)
{
	size_t n, m, l;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);
	n = start;
	m = middle;
	for (l = start; l < end; l++)
	{
		if (n < middle && (m >= end || source[n] <= source[m]))
		{
			dest[l] = source[n];
			n++;
		}
		else
		{
			dest[l] = source[m];
			m++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
* BKSplitMerge - recursively splits the array, merge and sort
* @start: starting index (inclusive)
* @end: end index (exclusive)
* @array: the array to sort
* @clone: a clone of the array
*/
void BKSplitMerge(size_t start, size_t end, int *array, int *clone)
{
	size_t middle;

	if (end - start < 2)
		return;
	middle = (start + end) / 2;
	BKSplitMerge(start, middle, array, clone);
	BKSplitMerge(middle, end, array, clone);
	BKMerge(start, middle, end, array, clone);
	for (middle = start; middle < end; middle++)
		clone[middle] = array[middle];
}

/**
* merge_sort - sorts an array of integers
* Merge sort algorithm
* @array: array to sort
* @size: size of the array
*
* Return: void
*/
void merge_sort(int *array, size_t size)
{
	size_t n;
	int *clone;

	if (array == NULL || size < 2)
		return;
	clone = malloc(sizeof(int) * size);
	if (clone == NULL)
		return;
	for (n = 0; n < size; n++)
		clone[n] = array[n];
	BKSplitMerge(0, size, array, clone);
	free(clone);
}

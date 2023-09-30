#include "sort.h"

int len_get_max(int *len_array, int len_size);
void len_radix_counting_sort(int *len_array, size_t len_size, int len_sig, int *len_buff);
void len_radix_sort(int *len_array, size_t len_size);

/**
 * len_get_max - Get the maximum value in an array of integers.
 * @len_array: An array of integers.
 * @len_size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int len_get_max(int *len_array, int len_size)
{
    int len_max, i;

    for (len_max = len_array[0], i = 1; i < len_size; i++)
    {
        if (len_array[i] > len_max)
            len_max = len_array[i];
    }

    return (len_max);
}

/**
 * len_radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @len_array: An array of integers.
 * @len_size: The size of the array.
 * @len_sig: The significant digit to sort on.
 * @len_buff: A buffer to store the sorted array.
 */
void len_radix_counting_sort(int *len_array, size_t len_size, int len_sig, int *len_buff)
{
    int len_count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    size_t i;

    for (i = 0; i < len_size; i++)
        len_count[(len_array[i] / len_sig) % 10] += 1;

    for (i = 0; i < 10; i++)
        len_count[i] += len_count[i - 1];

    for (i = len_size - 1; (int)i >= 0; i--)
    {
        len_buff[len_count[(len_array[i] / len_sig) % 10] - 1] = len_array[i];
        len_count[(len_array[i] / len_sig) % 10] -= 1;
    }

    for (i = 0; i < len_size; i++)
        len_array[i] = len_buff[i];
}

/**
 * len_radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @len_array: An array of integers.
 * @len_size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void len_radix_sort(int *len_array, size_t len_size)
{
    int len_max, len_sig, *len_buff;

    if (len_array == NULL || len_size < 2)
        return;

    len_buff = malloc(sizeof(int) * len_size);
    if (len_buff == NULL)
        return;

    len_max = len_get_max(len_array, len_size);
    for (len_sig = 1; len_max / len_sig > 0; len_sig *= 10)
    {
        len_radix_counting_sort(len_array, len_size, len_sig, len_buff);
        print_array(len_array, len_size);
    }

    free(len_buff);
}

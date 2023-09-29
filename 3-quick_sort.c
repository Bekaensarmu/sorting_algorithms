#include "sort.h"


/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int lomuto_partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
            printf("Swap: %d <--> %d\n", array[i], array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    printf("Swap: %d <--> %d\n", array[i + 1], array[high]);

    return i + 1;
}


/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 * 
 * Description: Uses the Lomuto partition scheme.
 */

void quick_sort_recursive(int *array, int low, int high) {
    if (low < high) {
        int pivot_index = lomuto_partition(array, low, high);
        quick_sort_recursive(array, low, pivot_index - 1);
        quick_sort_recursive(array, pivot_index + 1, high);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
 
void quick_sort(int *array, size_t size) {
    if (size <= 1) {
        return; // Nothing to sort
    }
    quick_sort_recursive(array, 0, size - 1);
}

int main() {
    int arr[] = {8, 3, 1, 7, 0, 10, 2};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    quick_sort(arr, size);

    printf("\nSorted Array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using a bubble
 * sort algorithm
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *array, size_t size) {
    int swapped;
    for (size_t i = 0; i < size - 1; i++) {
        swapped = 0;
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }
        printf("Pass %zu: ", i + 1);
        for (size_t k = 0; k < size; k++) {
            printf("%d ", array[k]);
        }
        printf("\n");

        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bubble_sort(arr, size);
    
    printf("Sorted array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}



#include "minunit.h"
#include "sort.h"
#include "utils.h"
#include <stdio.h>


// arr[l...r)
int partition(int* arr, int p, int r)
{
        // assert p < r
        int pivot = arr[r - 1];
        int i = p - 1;
        for (int j = p; j < r - 1; j++) {
                if (arr[j] <pivot) {
                        i++;
                        swap(&arr[i], &arr[j]);
                }
        }
        swap(&arr[i + 1], &arr[r - 1]);
        return (i + 1);
}

// arr[l, r]
int partition_v2(int *arr, int l, int r) {
    int i = l, j = r;
    int pivot = arr[l];
    while (i < j) {
        while (i < j && pivot < arr[j]) j--;
        while (i < j && pivot >= arr[i]) i++;
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[i], &arr[l]);
    return i;
}

// arr[l...r)
void quick_sort(int* arr, int p, int r)
{
        if (p < r) {
                int q = partition(arr, p, r);
                quick_sort(arr, p, q);
                quick_sort(arr, q + 1, r);
        }
}


#include "sort.h"
#include <assert.h>


// arr[l...r)
void insertion_sort(int* arr, int l, int r)
{
        assert(l < r);
        for (int i = l + 1; i < r; i++) {
                int key = arr[i];
                int j = i - 1;
                while (j >= l && key < arr[j]) {
                        arr[j + 1] = arr[j];
                        j--;
                }
                arr[j + 1] = key;
        }
}


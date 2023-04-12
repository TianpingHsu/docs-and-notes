#include "minunit.h"
#include "sort.h"
#include "kata_consts.h"
#include "utils.h"
#include <stdbool.h>

typedef void (*sort_func)(int*, int, int);

void init_arr(int* arr, int size)
{
        for (int i = 0; i < size; i++) {
                arr[i] = rand_int();
                //printf("%d ", arr[i]);
        }
        //newline();
}

bool test_sort(sort_func sf)
{
        int arr[MAX_SIZE];
        //int arr[10];
        init_arr(arr, sizeof(arr) / sizeof(int));
        sf(arr, 0, sizeof(arr)/sizeof(int));
        return is_sorted(arr, 0, sizeof(arr)/sizeof(int));
}

bool test_insertion_sort()
{
        return test_sort(insertion_sort);
}

bool test_quick_sort()
{
        return test_sort(quick_sort);
}

void module_sort_test()
{
        //RUN_TEST(test_insertion_sort);
        for (int i = 0; i < 10; i++) {
                RUN_TEST(test_quick_sort);
                //RUN_TEST(test_insertion_sort);
        }
}


#include "../../include/search.h"
#include "../../include/minunit.h"
#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE (0x1 << 10)
int arr[MAX_SIZE];

static void init_arr() 
{
        for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
                arr[i] = i * 10 + i;
}

static bool test_bs_case1()
{
        init_arr();
        return bs(arr, 0, sizeof(arr) / sizeof(int) , 56) == \
               linear_search(arr, 0, sizeof(arr) / sizeof(int), 56);
}

static bool test_bs_case2()
{
        init_arr();
        return bs(arr, 0, sizeof(arr) / sizeof(int) , 55) == \
               linear_search(arr, 0, sizeof(arr) / sizeof(int), 55);
}

static bool test_bs_case3()
{
        init_arr();
        return bs(arr, 0, 0 , 55) == \
               linear_search(arr, 0, 0, 55);
}

static bool test_bs_case4()
{
        init_arr();
        return bs(arr, 0, 1 , 55) == \
               linear_search(arr, 0, 1, 55);
}

static bool test_bs_case5()
{
        init_arr();
        return bs(arr, 0, 1 , 0) == \
               linear_search(arr, 0, 1, 0);
}

void module_search_test()
{
        RUN_TEST(test_bs_case1);
        RUN_TEST(test_bs_case2);
        RUN_TEST(test_bs_case3);
        RUN_TEST(test_bs_case4);
        RUN_TEST(test_bs_case5);
}


#include "../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

void newline() { printf("\n"); }

void init_srand()
{
        srand((unsigned)time(NULL));
}

int rand_int()
{
        return rand() % INT_MAX;
}

bool is_sorted(const int *arr, int l, int r)
{
        for (int i = l + 1; i < r; i++) {
                if (arr[i] < arr[i - 1]) return false;
        }
        return true;
}

void swap(int* p, int *q)
{
        int tmp = *p;
        *p = *q;
        *q = tmp;
}

void print_byte(void* q, int size)
{
        char* p = (char*)q;
        for (int i = 0; i < size; i++) {
                printf("%hhx ", p[i]);
        }
        newline();
}

// reverse a[l...r)
void reverse(int* a, int l, int r)
{
        int i = l, j = r - 1;
        while (i < j) {
                swap(&a[i++], &a[j--]);
        }
}

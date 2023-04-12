#ifndef __UTILS_H__
#define __UTILS_H__

#include <time.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define ELAPSED_TIME(f, times) \
        do { \
                clock_t start_t, end_t; \
                start_t = clock(); \
                for (int i = 0; i < times; i++) { \
                        f(); \
                } \
                end_t = clock(); \
                return ((end_t - start_t) / CLOCKS_PER_SEC) * 1000.0; \
        } while(0)

#define MSG(msg) \
        do { \
                if (msg) printf("%s\n", msg); \
        } while (0)

void newline();

void init_srand();

int rand_int();

void swap(int*, int*);

void print_byte(void* q, int size);

/*
 * arr[l...r)
 * arr[l] <= arr[l + 1] <= ... arr[r - 1]
 */
bool is_sorted(const int* arr, int l, int r);

// reverse a[l...r)
void reverse(int *a, int l, int r);

#endif

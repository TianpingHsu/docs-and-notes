#ifndef __SEARCH_H__
#define __SEARCH_H__

typedef int DataType;

// arr[l...r)
int bs(const DataType* arr, int l, int r, DataType target);

// arr[l...r)
int linear_search(const DataType* arr, int l, int r, DataType target);

#endif

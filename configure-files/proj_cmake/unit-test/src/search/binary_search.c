
#include "../../include/search.h"

/*
 * if target is in arr, then return the position
 * else return -1
 * make sure arr is sorted.
 */
int bs(const DataType* arr, int l, int r, DataType target)
{
        while (l < r)
        {
                int m = l + (r - l) / 2;
                if (arr[m] == target) return m;
                if (arr[m] > target) r = m - 1;
                if (arr[m] < target) l = m + 1;
        }
        return -1;
}

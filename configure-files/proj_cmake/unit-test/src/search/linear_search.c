
#include "../../include/search.h"

int linear_search(const DataType* arr, int l, int r, DataType target)
{
        for (int i = l; i < r; i++)
        {
                if (target == arr[i]) return i;
        }
        return -1;
}

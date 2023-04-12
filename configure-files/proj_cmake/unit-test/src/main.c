#include "../include/utils.h"
#include "../include/minunit.h"
#include "../include/search.h"
#include "../include/sort.h"
#include "../include/tests.h"

int main()
{
        MSG("*Start Testing");
        module_search_test();
        newline();
        module_sort_test();
        MSG("*End Testing");
        return 0;
}

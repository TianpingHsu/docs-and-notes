cmake_minimum_required (VERSION 3.10.2)

project (test)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall")
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")
#set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
#link_directories (third_lib)

include_directories (./include/)

set (SRC

        # search
        ./src/search/binary_search.c
        ./src/search/linear_search.c
        ./src/search/test_search.c

        # sort
        ./src/sort/insertion_sort.c
        ./src/sort/quick_sort.c
        ./src/sort/test_sort.c


        # utils
        ./src/utils/utils.c

        # main
        ./src/main.c)

add_executable (test ${SRC})



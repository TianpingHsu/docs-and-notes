

## `copy-and-swap` idiom
https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom  
https://stackoverflow.com/questions/5695548/public-friend-swap-member-function  


## The Rule of Three
https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three


## memcpy and memmove
memcpy: copy contents from low address to high one, ignoring whether `src` and `dst` may overlap:  
```C
void* memcpy(void* dst, const void* src, size_t n) {
    char *d = dst, 
    const char* s = src;
    while (n--) {
        *d++ = *s++;
    }
    return dst;
}
```
https://github.com/gcc-mirror/gcc/blob/master/libgcc/memcpy.c  
whilst memmove will test whether they are overlaped:  
```C
void* memmove(void* dst, const void* src, size_t n) {
    char *d = dst;
    const char *s = src;
    if (d < s) {
        while(n--) 
            *d++ = *s++;
    } else {
        char *lasts = src + (n - 1);
        char *lastd = dst + (n - 1);
        while (n--) 
            *lastd-- = *lasts--;
    }
    return dst;
}
```
https://github.com/gcc-mirror/gcc/blob/master/libgcc/memmove.c  



## implement your own shared ptr
https://github.com/SRombauts/shared_ptr  
https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/bits/shared_ptr.h  
https://cplusplus.com/reference/memory/shared_ptr/  
https://en.cppreference.com/w/cpp/memory/shared_ptr  
https://cplusplus.com/reference/memory/unique_ptr/  
https://medium.com/swlh/c-smart-pointers-and-how-to-write-your-own-c0adcbdce04f   


## RAII
https://en.cppreference.com/w/cpp/language/raii  
https://stackoverflow.com/questions/2321511/what-is-meant-by-resource-acquisition-is-initialization-raii  

## pImpl
https://en.wikibooks.org/wiki/C%2B%2B_Programming/Idioms#Pointer_To_Implementation_(pImpl)  

## std::move and std::exchange
https://en.cppreference.com/w/cpp/language/move_constructor  
https://en.cppreference.com/w/cpp/utility/exchange  
https://www.educative.io/answers/what-is-a-move-constructor-in-cpp


## volatile
https://zhuanlan.zhihu.com/p/62060524


## C operator precedence
https://en.cppreference.com/w/c/language/operator_precedence  


## malloc, calloc, realloc


## lvalue and rvalue
https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c


## garbage collection


## memory management: buddy system, linked list
https://developer.ibm.com/tutorials/l-memory/
https://stackoverflow.com/questions/3920453/custom-memory-allocator-manager-in-c-which-approach?noredirect=1&lq=1
https://github.com/evanw/buddy-malloc
https://github.com/evanw/buddy-malloc
https://github.com/Vatsalsoni13/Buddy-System-Memory-Allocation-1
https://github.com/Akashi96/Buddy-Memory-Allocator
https://github.com/danieldrucker/Buddy-System-Malloc
https://github.com/sebastiankliem/eos2017_memory-management-demo
https://www.c-sharpcorner.com/article/writing-our-own-memory-manager-in-ccpp/
https://developer.ibm.com/tutorials/au-memorymanager/
https://developer.ibm.com/tutorials/au-memorymanager/


## spinlock
https://rigtorp.se/spinlock/


## multithreading

## pthread


## web server


## order of construction and destruction


## sizeof(EmptyStruct) in C++
```C++
struct EmptyStruct {

};

sizeof(EmptyStruct) => 1
```

https://stackoverflow.com/questions/3849334/sizeof-empty-structure-is-0-in-c-and-1-in-c-why
https://stackoverflow.com/questions/2362097/why-is-the-size-of-an-empty-class-in-c-not-zero


## refs
https://www.stroustrup.com/bs_faq2.html



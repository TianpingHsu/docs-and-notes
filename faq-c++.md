

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


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void swap(void* a, void* b, size_t size)
{

}

void parsort(void* _arr, void* _brr, size_t _count, size_t _sizeA, size_t _sizeB, int(*cmp)(void* a, void* b))
{
    void* pin = _arr + _count - 1llu;
    size_t end = _count - 1llu;
    for (uint64_t i = 0; i < end, i++)
    {
        if (cmp(_arr + _sizeA * i, pin))
            
    }
}

int main()
{
    return EXIT_SUCCESS;
}
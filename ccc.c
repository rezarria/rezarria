#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

size_t partition(void* _a, void* _b, size_t _sizeA, size_t _sizeB, size_t _low, size_t _high, bool (*cmp)(const void*, const void*), void (*swap)(void*, void*, size_t _size))
{
    void* pivot = (size_t)_a + _sizeA * _high;
    size_t i = _low - 1llu;
    size_t m = _high - 1llu;
    for (size_t j = _low; j < m; j++)
        if (cmp(pivot, (size_t)_a + _sizeA * j))
        {
            i++;
            swap((size_t)_a + _sizeA * i, (size_t)_a + _sizeA * j, _sizeA);
            swap((size_t)_b + _sizeB * i, (size_t)_b + _sizeB * j, _sizeB);
        }
    swap((size_t)_a + _sizeA * (i + 1llu), (size_t)_a + _sizeA * _high, _sizeA);
    swap((size_t)_b + _sizeB * (i + 1llu), (size_t)_b + _sizeB * _high, _sizeB);
    return i;
}

void mQsort(void* _a, void* _b, size_t _sizeA, size_t _sizeB, size_t _low, size_t _high, bool (*cmp)(const void* _a, const void* _b), void (*swap)(void* _a, void* _b, size_t _size))
{
    if (_low < _high)
    {
        size_t pined = partition(_a, _b, _sizeA, _sizeB, _low, _high, cmp, swap);
        mQsort(_a, _b, _sizeA, _sizeB, _low, pined - 1llu, cmp, swap);
        mQsort(_a, _b, _sizeA, _sizeB, pined + 1llu, _high, cmp, swap);
    }
}

int _cmp(const void* _a, const void* _b)
{
    return *(int*)_a - *(int*)_b;
}

void _swap(void* _a, void* _b, size_t _size)
{
    void* _tmp = malloc(_size);
    memcpy(_tmp, _a, _size);
    memcpy(_a, _b, _size);
    memcpy(_b, _tmp, _size);
}

int main()
{
    int a[] = { 1,7,2,3,5,8,3,7,35,34,2,7,2 };
    int b[] = { 1,7,2,3,5,8,3,7,35,34,2,7,2 };
    size_t n = sizeof(a) / sizeof(int);
    mQsort((void*)a, (void*)b, sizeof(int), sizeof(int), 0llu, n - 1llu, _cmp, _swap);
    for (size_t i = 0; i < n; i++)
        printf("%5d", a[i]);
    printf("\n");
    for (size_t i = 0; i < n; i++)
        printf("%5d", b[i]);
    return 0;
}
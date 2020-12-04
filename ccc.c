#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

void swap(uintptr_t _a, uintptr_t _b, size_t _size)
{
    uintptr_t tmp = (uintptr_t)malloc(_size);
    memcpy((void*)tmp, (void*)_a, _size);
    memcpy((void*)_a, (void*)_b, _size);
    memcpy((void*)_b, (void*)tmp, _size);
}

int main()
{
    int a = 5;
    int b = 6;
    swap((uintptr_t)&a, (uintptr_t)&b, sizeof(int));
    printf("%5d%5d\n", a, b);
    return 0;
}
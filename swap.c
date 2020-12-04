#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

void swap(void* _a, void* _b, size_t _size)
{
    void* tmp = (uintptr_t)malloc(_size);
    memcpy(tmp, _a, _size);
    memmove(_a, _b, _size);
    memmove(_b, tmp, _size);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

float   importFloat();
void    swap(void* _a, void* _b, size_t _size);

int main()
{
    printf("Nhap lan luat a va b\n");
    float a = importFloat();
    float b = importFloat();
    swap(&a, &b, sizeof(float));
    printf("a = %6.2f\nb = %6.2f\n", a, b);
    return EXIT_SUCCESS;
}

void swap(void* _a, void* _b, size_t _size)
{
    void* tmp = (uintptr_t)malloc(_size);
    memmove(tmp, _a, _size);
    memmove(_a, _b, _size);
    memmove(_b, tmp, _size);
}

float importFloat()
{
    float n;
    printf("float> ");
    scanf("%f", &n);
    return n;
}
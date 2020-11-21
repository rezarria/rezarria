#include <stdio.h>
#include <stdint.h>

void swap(float *a, float *b)
{
    *(uint32_t *)a = *(uint32_t *)a ^ *(uint32_t *)b;
    *(uint32_t *)b = *(uint32_t *)a ^ *(uint32_t *)b;
    *(uint32_t *)a = *(uint32_t *)a ^ *(uint32_t *)b;
}

float nhapFloat(char c)
{
    float n;
    printf("Nhap so thuc %c : ", c);
    scanf("%f", &n);
    return n;
}

int main()
{
    float a = nhapFloat('a');
    float b = nhapFloat('b');
    swap(&a, &b);
    printf("a = %f\nb = %05f\n", a, b);
    return 0;
}
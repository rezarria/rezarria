#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t fibonacci(uint32_t n);

uint32_t nhapUi32();

int main()
{
    uint32_t n = nhapUi32();
    printf("fibonacci(%u)\t\t=\t%u\n", n, fibonacci(n));
    return  EXIT_SUCCESS;
}

uint32_t fibonacci(uint32_t n)
{
    return (n > 2u) ? (fibonacci(n - 1u) + fibonacci(n - 2u)) : 1u;
}

uint32_t nhapUi32()
{
    uint32_t n = 0u;
    printf("Nhap so nguyen duong\t:\t");
    scanf("%u", &n);
    return n;
}
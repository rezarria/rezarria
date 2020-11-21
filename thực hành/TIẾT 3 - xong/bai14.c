#include <stdio.h>
#include <stdint.h>

uint32_t fibonacci(uint32_t n)
{
    return (n > 2U) ? (fibonacci(n - 1U) + fibonacci(n - 2U)) : 1U;
}

uint32_t nhapUi32()
{
    uint32_t n = 0U;
    printf("Nhap so nguyen duong\t:\t");
    scanf("%u", &n);
    return n;
}

int main()
{
    uint32_t n = nhapUi32();
    printf("fibonacci(%u)\t\t=\t%u\n", n, fibonacci(n));
    return 0;
}
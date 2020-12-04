#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t fibonacci(uint32_t n);
uint32_t importUi32();

int32_t main()
{
    printf("Nhap n\n");
    uint32_t n = importUi32();
    printf("fibonacci(%u) = %u\n", n, fibonacci(n));
    return  EXIT_SUCCESS;
}

uint32_t fibonacci(uint32_t n)
{
    return (n > 2u) ? (fibonacci(n - 1u) + fibonacci(n - 2u)) : 1u;
}

uint32_t importUi32()
{
    uint32_t n;
    printf("uint32> ");
    scanf("%u", &n);
    return n;
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char *nhiPhan(unsigned int n)
{
    size_t size = log(n) / log(2);
    char *bin = (char *)calloc(size + 2, 1ull);
    char *c = bin + size;
    do
        *(c--) = '0' + n % 2;
    while (n /= 2);
    return bin;
}

int main()
{
    unsigned int n;
    printf("Nhap n : ");
    scanf("%u", &n);
    printf("-> %s\n", nhiPhan(n));
    return 0;
}
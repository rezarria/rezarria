#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char *HEX(unsigned int n)
{
    size_t size = log(n) / log(16);
    char *hex = (char *)calloc(size + 2, 1ull);
    sprintf(hex, "%X", n);
    return hex;
}

int main()
{
    unsigned int n;
    printf("Nhap n : ");
    scanf("%u", &n);
    printf("-> %s\n", HEX(n));
    return 0;
}
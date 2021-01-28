#include <stdio.h>

void uoc(unsigned int n)
{
    printf("%6u", n);
    for (unsigned int i = n / 2; i > 0; i--)
        if (!(n % i))
            printf("%6u", i);
}

int main()
{
    unsigned int n = 0;
    printf("Nhap n : ");
    scanf("%u", &n);
    uoc(n);
    return 0;
}
#include <stdio.h>

void HEX(unsigned int n)
{
    if (n)
    {
        HEX(n / 16);
        unsigned so_du = n % 16;
        if (so_du > 9)
            printf("%c", 'A' + so_du - 10);
        else
            printf("%u", so_du);
    }
}

int main()
{
    unsigned int n;
    printf("Nhap n : ");
    scanf("%u", &n);
    HEX(n);
    return 0;
}
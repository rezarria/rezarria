#include <stdio.h>

unsigned int giaiThua(unsigned int n)
{
    unsigned int gt = 1;
    for (; n > 1; n--)
        gt *= n;
    return gt;
}

int main()
{
    unsigned int n;
    printf("Nhap so nguyen duong n : ");
    scanf("%u", &n);
    printf("Gia thua cua %u la %u\n", n, giaiThua(n));
    return 0;
}
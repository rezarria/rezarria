#include <stdio.h>

unsigned int tongSo(unsigned int n)
{
    return n ? n % 10 + tongSo(n / 10) : 0;
}

int main()
{
    unsigned int n;
    printf("Nhap n : ");
    scanf("%u", &n);
    printf("%u\n", tongSo(n));
    return 0;
}
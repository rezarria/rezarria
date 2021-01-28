#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool hoanThien(unsigned int n)
{
    if(n == 1)
        return false;
    unsigned int t = 1;
    unsigned int moc = sqrt(n);
    for (; moc > 1; moc--)
        if (!(n % moc))
            t += moc + n / moc;
    return n == t;
}

int main()
{
    unsigned int n;
    printf("Nhap so : ");
    scanf("%u", &n);
    if (hoanThien(n))
        printf("La so hoan thien");
    else
        printf("Khong phai la so khong hoan thien");
    return 0;
}
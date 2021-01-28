// nghỉ 11 giờ rồi

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(unsigned int n)
{
    bool kq = false;
    switch (n)
    {
    case 1:
        break;
    case 2:
        kq = true;
    default:
        if (n % 2)
        {
            for (unsigned int i = sqrt(n); i > 2; i--)
                if (!(n % i))
                    break;
            kq = true;
        }
        else
            break;
    }
}

int main()
{
    unsigned int n;
    printf("Nhap so : ");
    scanf("%u", &n);
    if (isPrime(n))
        printf("la so nguyen to\n");
    else
        printf("khong phai la so nguyen to\n");
}
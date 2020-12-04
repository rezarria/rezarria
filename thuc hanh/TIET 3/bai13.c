#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool tamGiac(float a, float b, float c);

int main()
{
    float a, b, c;
    printf("Nhap cac so a, b, c : ");
    scanf("%f%f%f", &a, &b, &c);
    if (tamGiac(a, b, c))
        printf("Lam tam giac\n");
    else
        printf("Khong phai la tam giac\n");
    return 0;
}

bool tamGiac(float a, float b, float c)
{
    return a > fabsf(b - c);
}
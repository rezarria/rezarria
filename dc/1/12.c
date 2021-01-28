#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool laTamGiac(float a, float b, float c)
{
    return c > fabsf(b - a);
}

int main()
{
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);
    if (laTamGiac(a, b, c))
        printf("La tam giac\n");
    else
        printf("Khong phai la tam giac\n");
    return 0;
}
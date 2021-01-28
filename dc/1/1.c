#include <stdio.h>

float max(float a, float b)
{
    return (a > b) ? a : b;
}

float max3(float a, float b, float c)
{
    return max(a, max(b, c));
}

int main()
{
    float a, b, c;
    printf("nhap a, b ,c : ");
    scanf("%f%f%f", &a, &b, &c);
    printf("So lon nhat trong 3 so : %f\n", max3(a, b, c));
    return 0;
}
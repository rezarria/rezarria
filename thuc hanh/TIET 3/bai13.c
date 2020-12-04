#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

float   importFloat();
float*  importFloatN(uint64_t n);
bool    isTriAngle(float a, float b, float c);
void    display(bool dieuKien);

int32_t main()
{
    printf("Nhap lan luot cac so a, b, c\n");
    float* canh = importFloatN(3llu);
    display(isTriAngle(canh[0], canh[1], canh[2]));
    return EXIT_SUCCESS;
}

float importFloat()
{
    float f;
    printf("float> ");
    scanf("%f", &f);
    return f;
}

float* importFloatN(uint64_t n)
{
    float* f = (float*)malloc(sizeof(float) * n);
    for (uint64_t i = 0llu; i < n; i++)
        f[i] = importFloat();
    return f;
}

bool isTriAngle(float a, float b, float c)
{
    return a > fabsf(b - c);
}

void display(bool dieuKien)
{
    if (dieuKien)
        printf("La tam giac!\n");
    else
        printf("Khong phai la tam giac!\n");
}
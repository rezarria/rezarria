#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

float nhapFloat();
float* nhapFloatN(uint64_t n);
bool laCanhTamGiac(float a, float b, float c);
void thongBao(bool dieuKien);

int main()
{
    printf("Nhap lan luot cac so a, b, c\n");
    float* canh = nhapFloatN(3llu);
    thongBao(laCanhTamGiac(canh[0], canh[1], canh[2]));
    return EXIT_SUCCESS;
}

float nhapFloat()
{
    float f;
    printf("float> ");
    scanf("%f", &f);
    return f;
}

float* nhapFloatN(uint64_t n)
{
    float* f = (float*)malloc(sizeof(float) * n);
    for (uint64_t i = 0llu; i < n; i++)
        f[i] = nhapFloat();
    return f;
}

bool laCanhTamGiac(float a, float b, float c)
{
    return a > fabsf(b - c);
}

void thongBao(bool dieuKien)
{
    if (dieuKien)
        printf("La tam giac!\n");
    else
        printf("Khong phai la tam giac!\n");
}
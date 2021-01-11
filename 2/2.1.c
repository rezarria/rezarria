#include <stdio.h>

int nhapGiaTri();
void nhapMang(float mang[], int n);
float tbc(float mang[], int n);

int main()
{
    printf("Nhap so luong phan tu\n");
    int n;
    float mang[n = nhapGiaTri()];
    nhapMang(mang, n);
    printf("Trung binh cong %3.2f\n", tbc(mang, n));
    return 0;
}

int nhapGiaTri()
{
    int n;
    do
    {
        printf("Nhap n : ");
        scanf("%d", &n);
    } while (n < 1);

    return n;
}

void nhapMang(float mang[], int n)
{
    int i = 0;
    for (; i < n; i++)
    {
        printf("[%d] : ", i);
        scanf("%f", &mang[i]);
    }
}

float tbc(float mang[], int n)
{
    float t = 0.0f;
    int i = 0;
    for (; i < n; i++)
        t += mang[i];
    return t / n;
}
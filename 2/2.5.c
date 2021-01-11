#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nhapGiaTri();
void nhapMang(float mang[], int n);
int soPhanTuDuong(float mang[], int n);


int main()
{
    printf("Nhap so luong phan tu\n");
    int n;
    float mang[n = nhapGiaTri()];
    nhapMang(mang, n);
    printf("So phan tu duong trong mang la %d\n", soPhanTuDuong(mang, n));
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

int soPhanTuDuong(float mang[], int n)
{
    int i = 0;
    int dem = 0;
    for (; i < n; i++)
        if (mang[i] > 0.0f)
            dem++;
    return dem;
}
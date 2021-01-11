#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nhapGiaTri();
void nhapMang(float mang[], int n);
int timGiaTriLonNhat(float mang[], int n);


int main()
{
    printf("Nhap so luong phan tu\n");
    int n;
    float mang[n = nhapGiaTri()];
    nhapMang(mang, n);
    printf("Gia tri lon nhat trong mang la %d\n", timGiaTriLonNhat(mang, n));
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

int timGiaTriLonNhat(float mang[], int n)
{
    int p = 0;
    int i = 1;
    for (; i < n; i++)
        if (mang[p] < mang[i])
            p = i;
    return mang[p];
}
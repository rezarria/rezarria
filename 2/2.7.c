#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nhapGiaTri();
void nhapMang(int mang[], int n);
int tinhTong(int mang[], int n);



int main()
{
    printf("Nhap so luong phan tu\n");
    int n;
    int mang[n = nhapGiaTri()];
    nhapMang(mang, n);
    printf("Tong gia tri cua cac phan tu trong mang la %d\n", tinhTong(mang, n));
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

void nhapMang(int mang[], int n)
{
    int i = 0;
    for (; i < n; i++)
    {
        printf("[%d] : ", i);
        scanf("%d", &mang[i]);
    }
}

int tinhTong(int mang[], int n)
{
    int i = 0;
    int t = 0;
    for (; i < n; i++)
        t += mang[i];
    return t;
}

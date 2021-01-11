#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nhapGiaTri();
void nhapMang(int mang[], int n);
int tinhTongLe(int mang[], int n);


int main()
{
    printf("Nhap so luong phan tu\n");
    int n;
    int mang[n = nhapGiaTri()];
    nhapMang(mang, n);
    printf("Tong cac phan tu chan trong mang la %d\n", tinhTongLe(mang, n));
    return 0;
}

int nhapGiaTri()
{
    int n;
    do
    {
        putc('>', stdin);
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
        mang[i] = nhapGiaTri();
    }
}

int tinhTongLe(int mang[], int n)
{
    int i = 0;
    int t = 0;
    for (; i < n; i++)
        if (!(mang[i] % 2))
            t += mang[i];
    return t;
}
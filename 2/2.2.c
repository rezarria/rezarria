#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nhapGiaTri();
void nhapMang(int mang[], int n);
void xepMang(int mang[], int n);
void swap(void* a, void* b, size_t size);
void hienMang(int mang[], int n);


int main()
{
    printf("Nhap so luong phan tu\n");
    int n;
    int mang[n = nhapGiaTri()];
    nhapMang(mang, n);
    xepMang(mang, n);
    hienMang(mang, n);
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

void xepMang(int mang[], int n)
{
    int k = n - 1;
    int i = 0;
    int j = 0;
    size_t size = sizeof(int);
    for (; i < k; i++)
        for (j = i + 1; j < n; j++)
            if (mang[i] > mang[j])
                swap((void*)&mang[i], (void*)&mang[j], size);
}

void swap(void* a, void* b, size_t size)
{
    void* c = malloc(size);
    memcpy(c, a, size);
    memcpy(a, b, size);
    memcpy(b, c, size);
    free(c);
}

void hienMang(int mang[], int n)
{
    printf("-----------------------------\n");
    int i = 0;
    for (; i < n; i++)
        printf("[%d] : %d\n", i, mang[i]);
}
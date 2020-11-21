#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int n;
    int *arr;
} arrT;

int nhapN();
arrT *taoMang(int n);
void napMang(arrT *arr, int n);
arrT *nhapMang(arrT *arr);
arrT *loc(arrT *arr);
int tong(arrT *arr);
void inKetQua(int n);

int main()
{
    inKetQua(tong(loc(nhapMang(taoMang(nhapN())))));
    return 0;
}

int nhapN()
{
    int n;
    printf("Nhap n : ");
    scanf("%d", &n);
    return n;
}

arrT *taoMang(int n)
{
    arrT *arr = (arrT *)malloc(sizeof(arrT));
    arr->n = n;
    arr->arr = (int *)calloc(n, sizeof(int));
    return arr;
}

void napMang(arrT *arr, int n)
{
    arr->n++;
    arr->arr = (int *)realloc(arr->arr, arr->n * sizeof(int));
    arr->arr[arr->n - 1] = n;
}

arrT *nhapMang(arrT *arr)
{
    for (int i = 0; i < arr->n; i++)
        do
        {
            printf("Nhap phan tu thu %d : ", i);
            scanf("%d", &arr->arr[i]);
        } while (arr->arr[i] < 1);
    return arr;
}

arrT *loc(arrT *arr)
{
    arrT *rArr = taoMang(0);
    for (int i = 0; i < arr->n; i++)
    {
        if (arr->arr[i] % 2)
            napMang(rArr, arr->arr[i]);
    }
    return rArr;
}

int tong(arrT *arr)
{
    int t = 0;
    for (int i = 0; i < arr->n; i++)
        t += arr->arr[i];
    free(arr->arr);
    free(arr);
    return t;
}

void inKetQua(int n)
{
    printf("T = %d\n", n);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
    int32_t n;
    int32_t* arr;
} arrT;

uint64_t importN();
arrT* taoMang(uint64_t n);
void napMang(arrT* arr, uint64_t n);
arrT* nhapMang(arrT* arr);
arrT* loc(arrT* arr);
int32_t tong(arrT* arr);
void printfResult(int32_t n);

int32_t main()
{
    printfResult(tong(loc(nhapMang(taoMang(importN())))));
    return 0;
}

uint64_t importN()
{
    int64_t n;
    printf("Nhap n : ");
    scanf("%llu", &n);
    return n;
}

arrT* taoMang(uint64_t n)
{
    arrT* arr = (arrT*)malloc(sizeof(arrT));
    arr->n = n;
    arr->arr = (int32_t*)calloc(n, sizeof(int32_t));
    return arr;
}

void napMang(arrT* arr, uint64_t n)
{
    arr->n++;
    arr->arr = (int32_t*)realloc(arr->arr, arr->n * sizeof(int32_t));
    arr->arr[arr->n - 1llu] = n;
}

arrT* nhapMang(arrT* arr)
{
    for (uint64_t i = 0llu; i < arr->n; i++)
        do
        {
            printf("Nhap phan tu thu %3llu : ", i);
            scanf("%d", &arr->arr[i]);
        } while (arr->arr[i] < 1);
        return arr;
}

arrT* loc(arrT* arr)
{
    arrT* rArr = taoMang(0);
    for (uint64_t i = 0llu; i < arr->n; i++)
    {
        if (arr->arr[i] % 2)
            napMang(rArr, arr->arr[i]);
    }
    return rArr;
}

int32_t tong(arrT* arr)
{
    int32_t t = 0;
    for (uint64_t i = 0llu; i < arr->n; i++)
        t += arr->arr[i];
    free(arr->arr);
    free(arr);
    return t;
}

void printfResult(int32_t n)
{
    printf("T = %d\n", n);
}
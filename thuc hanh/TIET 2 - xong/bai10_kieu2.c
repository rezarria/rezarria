#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

uint64_t nhapN();
void trao(int32_t* a, int32_t* b);
int32_t* taoMang(uint64_t n);
int32_t* nhapMang(int32_t* arr, uint32_t n);
int32_t* func(int32_t* arr, uint64_t n, uint64_t* r);
void hienMang(int32_t* arr, uint64_t n);

int main()
{
    uint64_t n = nhapN();
    int32_t* arr = nhapMang(taoMang(n), n);
    uint64_t m;
    int32_t* brr = func(arr, n, &m);
    hienMang(brr, m);
    return EXIT_SUCCESS;
}

uint64_t nhapN()
{
    uint32_t n;
    fputc('>', stdout);
    scanf("%d", &n);
    return n;
}

int32_t* taoMang(uint64_t n)
{
    return (int32_t*)calloc(n, sizeof(int32_t));
}

int32_t* nhapMang(int32_t* arr, uint32_t n)
{
    for (uint64_t i = 0; i < n; i++)
    {
        printf("[%llu]\t", i);
        scanf("%d", &arr[i]);
    }
    return arr;
}

int32_t* func(int32_t* arr, uint64_t n, uint64_t* r)
{
    int32_t* brr = (int32_t*)calloc(n, sizeof(int32_t));
    *r = 1llu;
    brr[0llu] = arr[0llu];
    bool exist;
    for (uint64_t i = 1llu; i < n; i++)
    {
        exist = false;
        for (uint64_t j = 0; j < *r; j++)
            if (arr[i] == brr[j])
            {
                exist = true;
                break;
            }
        if (!exist)
        {
            brr[*r] = arr[i];
            (*r)++;
        }
    }
    return brr;
}

void trao(int32_t* a, int32_t* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void hienMang(int32_t* arr, uint64_t n)
{
    for (uint64_t i = 0; i < n; i++)
        printf("%5d", arr[i]);
}


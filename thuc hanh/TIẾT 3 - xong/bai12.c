#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    size_t n;
    uint32_t *arr;
} uint32_arr_t;

void nap(uint32_arr_t *arr, uint32_t n);
uint32_arr_t *uoc(uint32_t n);
uint32_t tongMang(uint32_arr_t *arr);
bool soHoanHao(uint32_t n);


int main()
{
    uint32_t n;
    printf("Nhap so nguyen duong n : ");
    scanf("%u", &n);
    printf("%u\n", n);
    if (soHoanHao(n))
        printf("La so hoan hao\n");
    else
    {
        printf("Khong phai la so hoan hao\n");
    }
    return 0;
}

void nap(uint32_arr_t *arr, uint32_t n)
{
    arr->n++;
    arr->arr = (uint32_t *)realloc(arr->arr, 4llu * arr->n);
    arr->arr[arr->n - 1llu] = n;
}

uint32_arr_t *uoc(uint32_t n)
{
    uint32_arr_t *arr = (uint32_arr_t *)malloc(sizeof(uint32_arr_t));
    arr->n = 0;
    arr->arr = NULL;
    nap(arr, 1U);
    uint32_t moc = sqrt(n);
    for (uint32_t i = moc; i > 1U; i--)
        if (n % i == 0)
        {
            nap(arr, i);
            nap(arr, n / i);
        }
    return arr;
}

uint32_t tongMang(uint32_arr_t *arr)
{
    uint32_t t = 0;
    for (size_t i = 0; i < arr->n; i++)
        t += arr->arr[i];
    return t;
}

bool soHoanHao(uint32_t n)
{
    return (tongMang(uoc(n)) == n);
}
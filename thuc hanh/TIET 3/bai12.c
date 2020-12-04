#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

typedef struct uint32_arr
{
    size_t n;
    uint32_t* arr;
} uint32_arr_t;


uint32_t        nhapUi32();
void            napMang(uint32_arr_t* arr, uint32_t n);
uint32_arr_t* timUoc(uint32_t n);
uint32_t        tinhTongMang(uint32_arr_t* arr);
bool            laSoHoanHao(uint32_t n);
void            thongBao(uint32_t n);


int32_t main()
{
    printf("Nhap so nguyen duong n : ");
    uint32_t n = nhapUi32();
    thongBao(n);
    return EXIT_SUCCESS;
}

uint32_t nhapUi32()
{
    uint32_t n;
    fputs("uint32> ", stdout);
    scanf("%u", &n);
    return n;
}

void napMang(uint32_arr_t* arr, uint32_t n)
{
    arr->n++;
    arr->arr = (uint32_t*)realloc(arr->arr, 4llu * arr->n);
    arr->arr[arr->n - 1llu] = n;
}

uint32_arr_t* timUoc(uint32_t n)
{
    uint32_arr_t* arr = (uint32_arr_t*)malloc(sizeof(uint32_arr_t));
    arr->n = 0llu;
    arr->arr = NULL;
    napMang(arr, 1u);
    uint32_t moc = sqrt(n);
    for (uint32_t i = moc; i > 1u; i--)
        if (n % i == 0u)
        {
            napMang(arr, i);
            napMang(arr, n / i);
        }
    return arr;
}

uint32_t tinhTongMang(uint32_arr_t* arr)
{
    uint32_t t = 0u;
    for (size_t i = 0llu; i < arr->n; i++)
        t += arr->arr[i];
    return t;
}

bool laSoHoanHao(uint32_t n)
{
    return (tinhTongMang(timUoc(n)) == n);
}


void thongBao(uint32_t n)
{
    if (laSoHoanHao(n))
        printf("La so hoan hao\n");
    else
    {
        printf("Khong phai la so hoan hao\n");
    }
}
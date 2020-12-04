#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

typedef struct __Uint32Arr
{
    size_t n;
    uint32_t* arr;
} Uint32Arr;


uint32_t        importUi32();
void            importArrayUi32(Uint32Arr* arr, uint32_t n);
Uint32Arr*      findDivisor(uint32_t n);
uint32_t        calcuSumOfArry(Uint32Arr* arr);
bool            isPerfect(uint32_t n);
void            display(uint32_t n);


int32_t main()
{
    printf("Nhap so nguyen duong n : ");
    uint32_t n = importUi32();
    display(n);
    return EXIT_SUCCESS;
}

uint32_t importUi32()
{
    uint32_t n;
    fputs("uint32> ", stdout);
    scanf("%u", &n);
    return n;
}

void importArrayUi32(Uint32Arr* arr, uint32_t n)
{
    arr->n++;
    arr->arr = (uint32_t*)realloc(arr->arr, 4llu * arr->n);
    arr->arr[arr->n - 1llu] = n;
}

Uint32Arr* findDivisor(uint32_t n)
{
    Uint32Arr* arr = (Uint32Arr*)calloc(1llu, sizeof(Uint32Arr));
    importArrayUi32(arr, 1u);
    uint32_t moc = sqrt(n);
    for (uint32_t i = moc; i > 1u; i--)
        if (n % i == 0u)
        {
            importArrayUi32(arr, i);
            importArrayUi32(arr, n / i);
        }
    return arr;
}

uint32_t calcuSumOfArry(Uint32Arr* arr)
{
    uint32_t t = 0u;
    for (size_t i = 0llu; i < arr->n; i++)
        t += arr->arr[i];
    return t;
}

bool isPerfect(uint32_t n)
{
    return (calcuSumOfArry(findDivisor(n)) == n);
}


void display(uint32_t n)
{
    if (isPerfect(n))
        printf("La so hoan hao\n");
    else
    {
        printf("Khong phai la so hoan hao\n");
    }
}
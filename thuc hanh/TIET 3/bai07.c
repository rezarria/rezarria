#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct ARR_S
{
    int32_t n;
    int32_t* arr;
} ARR;

uint64_t importUI64();
uint64_t importUI64_f(FILE* in);
int32_t importI32();
int32_t importI32_f(FILE* in);
ARR* createI32Arr(uint64_t n);
void pushI32Arr(ARR* arr, uint64_t n);
ARR* importI32Arr(ARR* arr);
ARR* importI32Arr_f(ARR* arr, FILE* in);
ARR* fillerI32Arr(ARR* arr);
int32_t sumOfI32Arr(ARR* arr);
void printfResult(int32_t n);
void printfResult_f(int32_t n, FILE* out);

int32_t main()
{
    FILE* file = fopen("bai07.inp", "r");
    int32_t arr = createI32Arr(importUI64_f(file));
    importI32Arr(arr);
    fclose(file);
    int32_t t = sumOfI32Arr(arr);
    file = fopen("bai07.inp", "w");
    printfResult_f(t, file);
    printfResult(t);
    fclose(file);
    return EXIT_SUCCESS;
}

uint64_t importUI64()
{
    return importUI64_f(stdin);
}

uint64_t importUI64_f(FILE* in)
{
    int64_t n;
    if (in == stdin)
        printf("uint64> ");
    fscanf(in, "%llu", &n);
    return n;
}

int32_t importI32()
{
    return importI32_f(stdin);
}

int32_t importI32_f(FILE* in)
{
    int32_t n;
    if (in == stdin)
        printf("int32> ");
    fscanf(in, "%d", &n);
    return n;
}

ARR* createI32Arr(uint64_t n)
{
    ARR* arr = (ARR*)malloc(sizeof(ARR));
    arr->n = n;
    arr->arr = (int32_t*)calloc(n, sizeof(int32_t));
    return arr;
}

void pushI32Arr(ARR* arr, uint64_t n)
{
    arr->n++;
    arr->arr = (int32_t*)realloc(arr->arr, arr->n * sizeof(int32_t));
    arr->arr[arr->n - 1llu] = n;
}

ARR* importI32Arr(ARR* arr)
{
    return importI32Arr_f(arr, stdin);
}

ARR* importI32Arr_f(ARR* arr, FILE* in)
{
    for (uint64_t i = 0llu; i < arr->n; i++)
        do
        {
            if (in = stdin)
                printf("Nhap phan tu thu %3llu : ", i);
            arr->arr[i] = importI32_f(in);
        } while (arr->arr[i] < 1);
        return arr;
}

ARR* fillerI32Arr(ARR* arr)
{
    ARR* rArr = createI32Arr(0);
    for (uint64_t i = 0llu; i < arr->n; i++)
    {
        if (arr->arr[i] % 2)
            pushI32Arr(rArr, arr->arr[i]);
    }
    return rArr;
}

int32_t sumOfI32Arr(ARR* arr)
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
    printfResult_f(n, stdout);
}

void printfResult_f(int32_t n, FILE* out)
{
    fprintf(out, "%d", n);
    if (out = stdout)
        printf("T = %d\n", n);
}

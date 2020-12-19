#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

void swap(uintptr_t _a, uintptr_t _b, size_t _size)
{
    uintptr_t tmp = (uintptr_t)malloc(_size);
    memcpy((void*)tmp, (void*)_a, _size);
    memcpy((void*)_a, (void*)_b, _size);
    memcpy((void*)_b, (void*)tmp, _size);
}

bool isMaxI32(int32_t a, int32_t b)
{
    return a > b;
}

bool isMinI32(int32_t a, int32_t b)
{
    return b < a;
}

int32_t importI32()
{
    return importI32_f(stdin);
}

int32_t importI32_f(FILE* in)
{
    int32_t n;
    if (in == stdin)
        fprintf(stdout, "int32> ");
    fscanf(in, "%d", &n);
    return n;
}

uint32_t importUI32()
{
    return importUI32(stdin);
}

uint32_t importUI32_f(FILE* in)
{
    int32_t n;
    if (in == stdin)
        printf("uint32> ");
    fscanf(in, "%u", &n);
    return n;
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

float importFloat()
{
    return importFloat_f(stdin);
}

float importFloat_f(FILE* in)
{
    float f;
    if (in == stdin)
        printf("float> ");
    fscanf(in, "%f", &f);
    return f;
}

float* importFloatArry(uint64_t n)
{
    return importFloatArry_f(n, stdin);
}

float* importFloatArry_f(uint64_t n, FILE* in)
{
    float* f = (float*)calloc(n, sizeof(float));
    for (uint64_t i = 0; i < n; i++)
        f[i] = importFloat_f(in);
    return f;
}

bool isPrime(uint32_t n)
{
    bool check = true;
    switch (n)
    {
    case 2:
    case 3:
    case 5:
    case 7:
    case 11:
        break;
    default:
        if (n % 2)
        {
            for (uint32_t i = sqrt(n); i > 2u; i--)
                if ((n % i) == 0)
                {
                    check = false;
                    break;
                }
        }
        else check = false;
    }
    return check;
}

char* getLine(FILE* input)
{
    int32_t length = 0llu;
    do
        length++;
    while (fgetc(input));
    char* str = (char*)malloc(sizeof(char) * length);
    fseek(input, SEEK_CUR, -length);
    for (int i = 0; i < length; i++)
        str[i] = (char)fgetc(input);
    return str;
}

int32_t** createI32Matrix(size_t n, size_t m)
{
    int32_t** matrix = (int32_t**)malloc(n * sizeof(int32_t*));
    for (size_t i = 0llu; i < n; i++)
        matrix[i] = (int32_t*)calloc(m, sizeof(int32_t));
    return matrix;
}

int32_t** getI32Matrix_f(FILE* input, size_t* n, size_t* m)
{
    int32_t** matrix;
    *n = importUI64_f(input);
    *m = importUI64_f(input);
    matrix = createI32Matrix(*n, *m);
    for (size_t i = 0llu; i < *n; i++)
        for (size_t j = 0llu; j < *m; j++)
            matrix[i][j] = importI32(input);
    return matrix;
}

void importI32Arr_f(FILE* input, int32_t** arr, uint64_t n, uint64_t m)
{
    for (uint64_t i = 0llu; i < n; i++)
        for (uint64_t j = 0llu; j < m; j++)
            arr[i][j] = importUi32_f(input);
}



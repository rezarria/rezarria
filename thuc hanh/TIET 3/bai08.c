//VÕ TÁ NAM
//205748010310003

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define _IN_FILE    "bai08.inp"
#define _OUT_FILE   "bai08.out"

typedef struct OBSERVER_S
{
    int64_t n, m;
    int32_t* min;
    int32_t* max;
    int32_t** matrix;
} OBSERVER;

OBSERVER* OBcreate();
OBSERVER* OBimportNM(OBSERVER* observer);
OBSERVER* OBcreateArray(OBSERVER* observer);
OBSERVER* OBimportArray(OBSERVER* observer);
OBSERVER* printfResult(OBSERVER* oberver);
OBSERVER* OBimportNM_f(OBSERVER* observer, FILE* in);
OBSERVER* OBimportArray_f(OBSERVER* observer, FILE* in);
OBSERVER* printfResult_f(OBSERVER* observer, FILE* out);
void clean(OBSERVER* observerT);
int32_t importI32();
int32_t importI32_f(FILE* in);
uint64_t importUI64();
uint64_t importUI64_f(FILE* in);
bool isMaxI32(int32_t a, int32_t b);
bool isMinI32(int32_t a, int32_t b);

int32_t main()
{
    FILE* in = fopen(_IN_FILE, "r");
    FILE* out = fopen(_OUT_FILE, "w");

    OBSERVER* observer = OBcreate();
    OBimportNM_f(observer, in);
    OBcreateArray(observer);
    OBimportArray_f(observer, in);
    printfResult_f(observer, out);

    fclose(in);
    fclose(out);
    return EXIT_SUCCESS;
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

bool isMaxI32(int32_t a, int32_t b)
{
    return a > b;
}

bool isMinI32(int32_t a, int32_t b)
{
    return b < a;
}

OBSERVER* OBcreate()
{
    return (OBSERVER*)malloc(sizeof(OBSERVER));
}

OBSERVER* OBimportNM_f(OBSERVER* observer, FILE* in)
{
    if (in == stdin)
        printf("n = ");
    observer->n = importUI64_f(in);
    if (in == stdin)
        printf("n = ");
    observer->m = importUI64_f(in);
    if (in != stdin)
    {
        printf("n =%llu\n", observer->n);
        printf("m =%llu\n", observer->m);
    }
    return observer;
}

OBSERVER* printfResult_f(OBSERVER* observer, FILE* out)
{

    if (out != stdout)
    {
        fprintf(out, "%d", *observer->max);
        fprintf(out, "%d", *observer->min);
    }
    printf("Gia tri lon nhat trong mang la %d\n", *observer->max);
    printf("Gia tri nho nhat trong mang la %d\n", *observer->min);
    return observer;
}

OBSERVER* OBimportArray_f(OBSERVER* observer, FILE* in)
{
    observer->min = &observer->matrix[0][0];
    observer->max = observer->min;
    for (uint64_t i = 0llu; i < observer->n; i++)
        for (uint64_t j = 0llu; j < observer->m; j++)
        {
            if (in == stdin)
                fprintf(stdout, "Nhap phan tu [%2llu,%2llu] : ", i, j);
            observer->matrix[i][j] = importI32_f(in);
            if (isMaxI32(*observer->max, observer->matrix[i][j]))
                observer->max = &observer->matrix[i][j];
            if (isMinI32(*observer->min, observer->matrix[i][j]))
                observer->min = &observer->matrix[i][j];
        }
    return observer;
}

OBSERVER* OBimportNM(OBSERVER* observer)
{
    return OBimportNM_f(observer, stdin);
}

OBSERVER* OBcreateArray(OBSERVER* observer)
{
    observer->matrix = (int32_t**)malloc(observer->n * sizeof(int32_t*));
    for (uint64_t i = 0llu; i < observer->n; i++)
        observer->matrix[i] = (int32_t*)calloc(observer->m, sizeof(int32_t));
    return observer;
}

OBSERVER* OBimportArray(OBSERVER* observer)
{
    return OBimportArray_f(observer, stdin);
}

OBSERVER* printfResult(OBSERVER* observer)
{
    return printfResult_f(observer, stdout);
}

void clean(OBSERVER* observer)
{
    for (uint64_t i = 0llu; i < observer->n; i++)
        free(observer->matrix[i]);
    free(observer->matrix);
    free(observer);
}
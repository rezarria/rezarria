//VÕ TÁ NAM
//205748010310003
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

uint32_t importUI32();
uint32_t importUI32_f(FILE* in);
size_t rowSizeOf(FILE* in);
size_t columnSizeOf(FILE* in);
void matrixSizeOf(FILE* input, size_t* n, size_t* m);
uint32_t** getUI32Matrix_f_auto(FILE* input, size_t* n, size_t* m);
void importUI32Arr_f(FILE* input, uint32_t* arr, uint64_t n);
void displayUI32Matrix(FILE* out, uint32_t** matrix, size_t n, size_t m);
uint32_t gcd(size_t a, size_t b);
uint32_t lcm(size_t a, size_t b);
void THE_REQUEST(FILE* out, uint32_t** matrix, size_t n);

int32_t main()
{
    FILE* f = fopen("bai09.inp", "r");
    size_t n, m;
    uint32_t** matrix = getUI32Matrix_f_auto(f, &n, &m);
    fclose(f);

    f = fopen("bai09.out", "w");
    THE_REQUEST(f, matrix, n);
    fclose(f);
    return EXIT_SUCCESS;
}

void THE_REQUEST(FILE* out, uint32_t** matrix, size_t n)
{
    fprintf(out, "%10s%10s%10s%10s\n", "a", "b", "ucnn", "bcln");
    fprintf(out, "----------------------------------------\n");
    for (size_t i = 0llu; i < n; i++)
        fprintf(out, "%10llu%10llu%10llu%10llu\n", matrix[i][0llu], matrix[i][1llu], gcd(matrix[i][0llu], matrix[i][1llu]), lcm(matrix[i][0llu], matrix[i][1llu]));
}

uint32_t importUI32()
{
    return importUI32_f(stdin);
}

uint32_t importUI32_f(FILE* in)
{
    int32_t n;
    if (in == stdin)
        printf("uint32> ");
    fscanf(in, "%u", &n);
    return n;
}

uint32_t** createUI32Matrix(size_t n, size_t m)
{
    uint32_t** matrix = (uint32_t**)malloc(n * sizeof(uint32_t*));
    for (size_t i = 0llu; i < n; i++)
        matrix[i] = (uint32_t*)calloc(m, sizeof(uint32_t));
    return matrix;
}

size_t rowSizeOf(FILE* in)
{
    fseek(in, 0l, SEEK_SET);
    char c;
    bool r = false;
    size_t row = 0llu;
    do
    {
        c = fgetc(in);
        switch (c)
        {
        case ' ':
        case '\n':
        {
            if (r)
            {
                r = false;
                row++;
            }
            break;
        }
        default:
            if (!r)
                r = true;
        }
    } while (c != '\n');
    if (r) row++;
    return row;
}

size_t columnSizeOf(FILE* in)
{
    fseek(in, 0l, SEEK_SET);
    size_t column = 0llu;
    char c;
    bool r = true;
    do
    {
        c = fgetc(in);
        if (c == '\n')
        {
            column++;
            r = false;
        }
        if (!r)
            r = true;
    } while (!feof(in));
    if (r) column++;
    return column;
}

void matrixSizeOf(FILE* input, size_t* n, size_t* m)
{
    *m = rowSizeOf(input);
    *n = columnSizeOf(input);
    fseek(input, 0l, SEEK_SET);
}

void importUI32Matrix_f(FILE* input, uint32_t** matrix, size_t n, size_t m)
{
    for (size_t i = 0llu; i < n; i++)
        importUI32Arr_f(input, matrix[i], m);
}

uint32_t** getUI32Matrix_f_auto(FILE* input, size_t* n, size_t* m)
{
    matrixSizeOf(input, n, m);
    uint32_t** matrix = createUI32Matrix(*n, *m);
    importUI32Matrix_f(input, matrix, *n, *m);
    return matrix;
}

void importUI32Arr_f(FILE* input, uint32_t* arr, uint64_t n)
{
    for (uint64_t i = 0llu; i < n; i++)
        arr[i] = importUI32_f(input);
}

void displayUI32Matrix(FILE* out, uint32_t** matrix, size_t n, size_t m)
{
    fprintf(out, "%llu\t%llu\n", n, m);
    size_t p = m - 1llu;
    for (size_t i = 0llu; i < n; i++)
    {
        for (size_t j = 0llu; j < m; j++)
        {
            fprintf(out, "%llu", matrix[i][j]);
            fputc((j == p) ? '\n' : '\t', out);
        }
    }
}

uint32_t gcd(size_t a, size_t b)
{
    while (a != b)
        if (a > b)
            a -= b;
        else
            b -= a;
    return a;
}

uint32_t lcm(size_t a, size_t b)
{
    return (a * b) / gcd(a, b);
}
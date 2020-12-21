//VÕ TÁ NAM
//205748010310003

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int32_t importI32();
int32_t importI32_f(FILE* in);
uint64_t importUI64();
uint64_t importUI64_f(FILE* in);
int32_t** createI32Matrix(size_t n, size_t m);
void importI32Matrix(int32_t** matrix, size_t n, size_t m);
void displayUI32Matrix(FILE* out, int32_t** matrix, size_t n, size_t m);

int32_t main()
{
    printf("Nhap hang : ");
    size_t n = importUI64();
    printf("Nhap cot : ");
    size_t m = importUI64();
    int32_t** matrix = createI32Matrix(n, m);
    importI32Matrix(matrix, n, m);
    FILE* f = fopen("bai06.out", "w");
    displayUI32Matrix(f, matrix, n, m);
    fclose(f);
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

int32_t** createI32Matrix(size_t n, size_t m)
{
    int32_t** matrix = (int32_t**)malloc(n * sizeof(int32_t*));
    for (size_t i = 0llu; i < n; i++)
        matrix[i] = (int32_t*)calloc(m, sizeof(int32_t));
    return matrix;
}

void importI32Matrix(int32_t** matrix, size_t n, size_t m)
{
    for (size_t i = 0llu; i < n; i++)
        for (size_t j = 0llu; j < m; j++)
        {
            printf("[%llu][%llu] ", i, j);
            matrix[i][j] = importI32();
        }
}

void displayUI32Matrix(FILE* out, int32_t** matrix, size_t n, size_t m)
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

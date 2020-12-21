//VÕ TÁ NAM
//205748010310003
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

int32_t importI32();
int32_t importI32_f(FILE* in);
uint64_t importUI64();
uint64_t importUI64_f(FILE* in);
int32_t** createI32Matrix(size_t n, size_t m);
int32_t** getI32Matrix_f(FILE* input, size_t* n, size_t* m);
bool isPrime(uint32_t n);
void fillerI32(int32_t** matrix, size_t n, size_t m);


int32_t main()
{
    FILE* f = fopen("bai08.inp", "r");
    size_t n, m;
    int32_t** matrix = getI32Matrix_f(f, &n, &m);
    fclose(f);
    fillerI32(matrix, n, m);
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

int32_t** getI32Matrix_f(FILE* input, size_t* n, size_t* m)
{
    int32_t** matrix;
    *n = importUI64_f(input);
    *m = importUI64_f(input);
    matrix = createI32Matrix(*n, *m);
    for (size_t i = 0llu; i < *n; i++)
        for (size_t j = 0llu; j < *m; j++)
            matrix[i][j] = importI32_f(input);
    return matrix;
}

bool isPrime(uint32_t n)
{
    bool check = true;
    switch (n)
    {
    case 1:
        check = false;
        break;
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

void fillerI32(int32_t** matrix, size_t n, size_t m)
{
    size_t count = 0llu;
    for (size_t i = 0llu; i < n; i++)
        for (size_t j = 0llu; j < m; j++)
            if (isPrime(matrix[i][j]))
            {
                count++;
                printf("%d", matrix[i][j]);
                fputc((count == 10llu) ? '\n' : '\t', stdout);
            }
    fputc('\n', stdout);
}
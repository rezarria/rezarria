//VÕ TÁ NAM
//205748010310003
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t importUI64();
uint64_t importUI64_f(FILE* in);
float importFloat();
float importFloat_f(FILE* in);
float** createFloatMatrix(size_t n, size_t m);
float** getFloatMatrix_f(FILE* input, size_t* n, size_t* m);
void displayFloatMatrix(float** matrix, size_t n, size_t m);

int32_t main()
{
    FILE* f = fopen("bai07.inp", "r");
    size_t n, m;
    float** matrix = getFloatMatrix_f(f, &n, &m);
    fclose(f);
    displayFloatMatrix(matrix, n, m);
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

float** createFloatMatrix(size_t n, size_t m)
{
    float** matrix = (float**)malloc(n * sizeof(float*));
    for (size_t i = 0llu; i < n; i++)
        matrix[i] = (float*)calloc(m, sizeof(float));
    return matrix;
}

float** getFloatMatrix_f(FILE* input, size_t* n, size_t* m)
{
    float** matrix;
    *n = importUI64_f(input);
    *m = importUI64_f(input);
    matrix = createFloatMatrix(*n, *m);
    for (size_t i = 0llu; i < *n; i++)
        for (size_t j = 0llu; j < *m; j++)
            matrix[i][j] = importFloat_f(input);
    return matrix;
}

void displayFloatMatrix(float** matrix, size_t n, size_t m)
{
    printf("Ma tran %llu x %llu \n", n, m);
    printf("-------------------------------------------\n");
    size_t p = m - 1llu;
    for (size_t i = 0llu; i < n; i++)
    {
        for (size_t j = 0llu; j < m; j++)
        {
            fprintf(stdout, "%5.2f", matrix[i][j]);
            fputc((j == p) ? '\n' : '\t', stdout);
        }
    }
}

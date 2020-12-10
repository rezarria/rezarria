#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t importI32();
int32_t importI32_f(FILE* in);
float sumDivine(int32_t n);
void printSumOfDivine(float n);
void printSumOfDivine_f(float n, FILE* out);

int32_t main()
{
    FILE* file = fopen("bai02.inp", "r");
    int32_t n = importI32_f(file);
    printf("n = %d\n", n);
    fclose(file);
    file = fopen("bai02.out", "w");
    float t = sumDivine(n);
    printSumOfDivine(t);
    printSumOfDivine_f(t, file);
    fclose(file);
    return EXIT_SUCCESS;
}

//---------------------------------

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

float sumDivine(int32_t n)
{
    float s = 1.0f;
    n++;
    for (int32_t i = 2; i < n; i++)
        s += 1.0f / i;
    return s;
}

void printSumOfDivine_f(float n, FILE* out)
{
    if (out == stdout)
        printf("T cua 1 + ... +1/n = ");
    fprintf(out, "%f", n);
}

void printSumOfDivine(float n)
{
    printSumOfDivine_f(n, stdout);
}


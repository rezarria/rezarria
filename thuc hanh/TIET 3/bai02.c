#include <stdio.h>

int importI32();
int importI32_f(FILE* in);
int sumOdd(int n);
void printSum_f(int n, FILE* out);
void printSum(int n);

int main()
{
    FILE* file = fopen("bai02.inp", "r");
    int n = importI32_f(file);
    printf("n\t=\t%d\n", n);
    fclose(file);
    n = sumOdd(n);
    printSum(n);
    file = fopen("bai02.out", "w");
    printSum_f(n, file);
    return 0;
}

//----------------------------

int importI32_f(FILE* in)
{
    int n;
    if (in == stdin)
        printf("int32> ");
    fscanf(in, "%d", &n);
    return n;
}

int importI32()
{
    return importI32(stdin);
}

int sumOdd(int n)
{
    int i, s = 0;
    n++;
    for (i = 1; i < n; i++)
        s += 2 * i;
    return s;
}

void printSum_f(int n, FILE* out)
{
    if (out == stdout)
        printf("T cua 1 + ... + (2*n) = ");
    fprintf(out, "%d", n);
}

void printSum(int n)
{
    printSum_f(n, stdout);
}



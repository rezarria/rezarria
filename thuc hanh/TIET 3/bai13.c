#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

float   importFloat();
float   importFloat_f(FILE* in);
float* importFloatArry(uint64_t n);
float* importFloatArry_f(uint64_t n, FILE* in);
bool    isTriAngle(float a, float b, float c);
void    display(bool cons);
void    display_f(bool cons, FILE* out);

int32_t main()
{
    FILE* input = fopen("bai13.inp", "r");
    FILE* output = fopen("Bai13.out", "w");
    float* canh = importFloatArry_f(3llu, input);
    display_f(isTriAngle(canh[0], canh[1], canh[2]), output);
    fclose(input);
    fclose(output);
    return EXIT_SUCCESS;
}

float importFloat()
{
    return importFloat_f(stdin);
}

float   importFloat_f(FILE* in)
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

bool isTriAngle(float a, float b, float c)
{
    return a > fabsf(b - c);
}

void display(bool cons)
{
    display_f(cons, stdout);
}

void    display_f(bool cons, FILE* out)
{
    if (cons)
    {
        printf("La tam giac!\n");
        if (out == stdout)
            fprintf(out, "La tam giac!\n");
    }
    else
    {
        printf("Khong phai la tam giac!\n");
        if (out == stdout)
            fprintf(out, "Khong phai la tam giac!\n");
    }
}

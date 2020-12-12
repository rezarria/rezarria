#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

float   importFloat();
float   importFloat_f(FILE* in);
void    swap(void* _a, void* _b, size_t _size);

int main()
{
    FILE* input = fopen("bai5.inp", "r");
    FILE* output = fopen("bai15.out", "w");
    float a = importFloat_f(input);
    float b = importFloat_f(input);
    swap(&a, &b, sizeof(float));
    printf("a = %6.2f\nb = %6.2f\n", a, b);
    fprintf(output, "%f%f", a, b);
    fclose(input);
    fclose(output);
    return EXIT_SUCCESS;
}

void swap(void* _a, void* _b, size_t _size)
{
    void* tmp = (uintptr_t)malloc(_size);
    memmove(tmp, _a, _size);
    memmove(_a, _b, _size);
    memmove(_b, tmp, _size);
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

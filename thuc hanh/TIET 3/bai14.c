#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t fibonacci(uint32_t n);
uint32_t importUi32();
uint32_t importUI32_f(FILE* in);

int32_t main()
{
    FILE* input = fopen("bai14.inp", "r");
    FILE* output = fopen("bai14.out", "w");
    uint32_t f = fibonacci(importUI32_f(input));
    fprintf(output, "%u", f);
    fclose(input);
    fclose(output);
    return  EXIT_SUCCESS;
}

uint32_t fibonacci(uint32_t n)
{
    return (n > 2u) ? (fibonacci(n - 1u) + fibonacci(n - 2u)) : 1u;
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

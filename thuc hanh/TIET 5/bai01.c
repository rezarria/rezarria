//VÕ TÁ NAM
//205748010310003
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

int32_t importI32();
int32_t importI32_f(FILE* in);
void    exportI32(FILE* out, size_t n);

int32_t main()
{
    printf("Nhap n so can nhap: ");
    size_t n;
    FILE* output = fopen("bai01.out", "w");
    scanf("%llu", &n);
    exportI32(output, n);
    fclose(output);
    return EXIT_SUCCESS;
}

void exportI32(FILE* out, size_t n)
{
    for (size_t i = 0llu; i < n; i++)
        fprintf(out, "%d ", importI32());
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
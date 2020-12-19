//VÕ TÁ NAM
//205748010310003
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

uint64_t importUI64();
uint64_t importUI64_f(FILE* in);
uint32_t importUI32();
uint32_t importUI32_f(FILE* in);
char* decToBin(uint32_t n);
char* decToHex(uint32_t n);
void exportUi32Arr_f(FILE* out);
uint32_t* importUi32Arr_f(FILE* in, size_t* n);
void displayUi32Arr(uint32_t* arr, size_t n);
void run(FILE* out, uint32_t* arr, int n);

int32_t main()
{
    FILE* f = fopen("bai05.inp", "w");
    exportUi32Arr_f(f);
    fclose(f);

    f = fopen("bai05.inp", "r");
    size_t n;
    uint32_t* arr = importUi32Arr_f(f, &n);
    fclose(f);

    displayUi32Arr(arr, n);

    f = fopen("bai05.out", "w");
    run(f, arr, n);
    fclose(f);

    return EXIT_SUCCESS;
}

void exportUi32Arr_f(FILE* out)
{
    printf("Nhap n so can nhap :\n");
    uint64_t n = importUI64();
    fprintf(out, "%u ", n);
    for (size_t i = 0llu; i < n; i++)
    {
        printf("[%llu]= ", i);
        fprintf(out, "%u ", importUI32());
    }
}

uint32_t* importUi32Arr_f(FILE* in, size_t* n)
{
    *n = importUI64_f(in);
    uint32_t* arr = (uint32_t*)calloc(*n, sizeof(uint32_t));
    for (size_t i = 0llu; i < *n; i++)
        arr[i] = importUI32_f(in);
    return arr;
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


char* decToBin(uint32_t n)
{
    char* bin = (char*)calloc(33llu, sizeof(char));
    size_t i = 32llu;
    while (i)
    {
        i--;
        bin[i] = '0' + n % 2u;
        n /= 2u;
    }
    return bin;
}

char* decToHex(uint32_t n)
{
    char* hex = (char*)calloc(9llu, sizeof(char));
    size_t i = 8llu;
    while (i)
    {
        i--;
        hex[i] = '0' + n % 16u;
        if (hex[i] > '9')
            hex[i] += 7llu;
        n /= 16u;
    }
    return hex;
}

void displayUi32Arr(uint32_t* arr, size_t n)
{
    for (size_t i = 0llu; i < n; i++)
        printf("[%llu]= %u\n", i, arr[i]);
}

void run(FILE* out, uint32_t* arr, int n)
{
    for (size_t i = 0llu; i < n; i++)
    {
        fprintf(out, "%llu\t%s\t%s\n", i, decToBin(arr[i]), decToHex(arr[i]));
    }
}
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

uint32_t    importUi32();
uint32_t    importUI32_f(FILE* in);
char*       convertDexToBin(uint32_t n);
void        displayResult(char* bin);

int32_t main()
{
    FILE* file = fopen("bai10.inp", "r");
    uint32_t n = importUi32_f(file);
    fclose(file);
    char* bin = convertDexToBin(n);
    displayResult(bin);
    return EXIT_SUCCESS;
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

char* convertDexToBin(uint32_t n)
{
    char* bin = (char*)malloc(sizeof(char) * 33llu);
    bin[32] = '\0';
    for (int8_t i = 31; i > -1; i--)
    {
        bin[i] = '0';
        if (n)
        {
            bin[i] += n % 2;
            n /= 2;
        }
    }
    return bin;
}

void displayResult(char* bin)
{
    printf("> %s", bin);
}
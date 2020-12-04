#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

uint32_t importUi32();
char* convertDexToBin(uint32_t n);
void displayResult(char* bin);

int32_t main()
{
    uint32_t n = importUi32();
    char* bin = convertDexToBin(n);
    displayResult(bin);
    return EXIT_SUCCESS;
}

uint32_t importUi32()
{
    uint32_t n;
    fputs("> ", stdout);
    scanf("%u", &n);
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
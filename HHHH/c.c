#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *intTOBin(int n)
{
    char *bin = (char *)malloc(33ull);
    bin[32] = '\0';
    unsigned int *o = (unsigned int *)&n;
    for (char i = 31; i != EOF; i--, *o /= 2u)
        bin[i] = '0' + *o % 2u;
    return bin;
}

int binToInt(char *bin)
{
    int i = -1;
    int step = 1;
    while (*bin)
    {
        if (!(*bin - '0'))
            i -= step;
        step <<= 1;
        bin++;
    }
    return i;
}

int main(int argc, char **argv)
{
    int n = 1;
    for (int i = 0; i < 32; i++)
    {
        printf("%s %d\n", intTOBin(n), n);
        printf("%d\n", binToInt(intTOBin(n)));
        n <<= 1;
    }
    return 0;
}
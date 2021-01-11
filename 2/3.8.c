#include <stdio.h>

void docXauTuFile(FILE* file);

int main()
{
    FILE* file = fopen("input.txt", "r");
    docXauTuFile(file);
    return 0;
}

void docXauTuFile(FILE* file)
{
    int c;
    while ((c = fgetc(file)) != EOF)
        putc(c, stdout);
}
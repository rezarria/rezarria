#include <stdio.h>
#include <stdarg.h>

void GhiVaoBien(char type, char* size, ...);
void GhiVaoTep(FILE* file, size_t size, ...);

int main()
{
    int a, b, c;
    GhiVaoBien('d', "abc", &a, &b, &c);
    FILE* file = fopen("output.txt", "w");
    GhiVaoTep(file, 3, a, b, c);
    fclose(file);
    return 0;
}

void GhiVaoBien(char type, char* size, ...)
{
    va_list argv;
    va_start(argv, size);
    char format[3] = "%x";
    format[1] = type;
    do
    {
        printf("%c : ", *size);
        scanf(format, va_arg(argv, size_t));
    } while (*(++size));
}

void GhiVaoTep(FILE* file, size_t size, ...)
{
    va_list argv;
    va_start(argv, size);
    for (; 0ull < size; size--)
        fprintf(file, "%d ", va_arg(argv, int));
}
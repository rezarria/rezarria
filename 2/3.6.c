#include <stdio.h>
#include <stdarg.h>

void GhiVaoTep(FILE* file, const char type, size_t size, ...);
void thongBao(char* argc, ...);

int main()
{
    int a, b, c;
    FILE* file = fopen("input.txt", "r");
    GhiVaoTep(file, 'd', 3, &a, &b, &c);
    fclose(file);
    thongBao("abc", a, b, c);
}

void GhiVaoTep(FILE* file, const char type, size_t size, ...)
{
    va_list argv;
    va_start(argv, size);
    char format[] = "%x";
    format[1] = type;
    for (; 0ull < size; size--)
        fscanf(file, format, va_arg(argv, size_t));
}

void thongBao(char* argc, ...)
{
    va_list argv;
    va_start(argv, argc);
    do
        printf("%c : %d\n", *argc, va_arg(argv, int));
    while (*(++argc));

}
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void cut(char* strC, char* strS, size_t begin, size_t end)
{

}

char** cutStr(char* str)
{
    char** list = (char**)calloc(256llu, sizeof(char*));
    char* pos = NULL;
    size_t n = 0llu;
    bool cut = false;
    do
        switch (*str)
        {
        case '\n':
        case '\0':
        case ' ':
            if (cut)
            {
                cut = false;
                list[n] = (char*)calloc(str - pos + 1llu, sizeof(char));
                strncpy(list[n], pos, str - pos);
                n++;
            }
            break;
        default:
            if (!cut)
            {
                cut = true;
                pos = str;
            }
            break;
        }
    while (*(str++));
    return (char**)realloc(list, sizeof(char*) * (n + 1llu));
}

void show(char** list)
{
    for (;*list; list++)
        puts(*list);
}

int main()
{
    char a[] = "mot hai ba";
    char** b = cutStr(a);
    printf("%d\n", strlen(a));
    show(b);
    return EXIT_SUCCESS;
}
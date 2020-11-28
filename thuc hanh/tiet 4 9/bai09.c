#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void cut(char* strC, char* strS, size_t begin, size_t end)
{

}

char** cutStr(char* str, size_t* _n);
char*** cutStrList(char** list, size_t** _n);


void show(char** list)
{
    for (;*list; list++)
        puts(*list);
}

int main()
{
    char a[] = "mot hai ba";
    char b[] = "bon nam sau";
    char* c[] = { a, b, NULL };
    char*** d = cutStrList(c, NULL);
    show(d[0]);
    show(d[1]);
    return EXIT_SUCCESS;
}

char** cutStr(char* str, size_t* _n)
{
    char** list = (char**)calloc(256llu, sizeof(char*));
    char* pos = NULL;
    size_t n = 0llu;
    if (_n)*_n = n;
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
                strncpy(list[n++], pos, str - pos);
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

char*** cutStrList(char** list, size_t** _n)
{
    char*** _list = (char***)calloc(256llu, sizeof(char**));
    size_t* n = (size_t*)calloc(256llu, sizeof(size_t));
    if (_n) *_n = n;
    size_t i = 0llu;
    do
    {
        _list[i++] = cutStr(*list, n++);
    } while (*++list);

    return (char***)realloc(_list, sizeof(char**) * (i + 1llu));
}

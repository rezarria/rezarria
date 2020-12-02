#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

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
    size_t i = 0llu;
    do
    {
        _list[i++] = cutStr(*list, n++);
    } while (*++list);
    n = (size_t*)realloc(n, sizeof(size_t) * i);
    if (_n) *_n = n;
    return (char***)realloc(_list, sizeof(char**) * (i + 1llu));
}
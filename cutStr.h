#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char** cutStr(char* str)
{
    char** list = (char**)calloc(256llu, sizeof(char*));
    char* pos = NULL;
    size_t n = 0llu;
    bool cut = false;
    for (;*str; str++)
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
    return (char**)realloc(list, sizeof(char*) * (n + 1llu));
}
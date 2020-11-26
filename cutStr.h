#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

int32_t strDecrea(const void *a, const void *b)
{
    return -strcmp(*(const char **)a, *(const char **)b);
}

char **cutStr(char *str)
{
    printf("!!!!!\n");
    char **list = (char **)calloc(255llu, sizeof(char *));
    bool cut = false;
    size_t n = 0;
    size_t begin, end;
    size_t length = strlen(str);
    for (size_t i = 0; i < length; i++)
        switch (str[i])
        {
        case '\0':
        case ' ':
        case '\n':
            if (cut)
            {
                cut = false;
                end = i;
                list[i] = (char *)calloc(end - begin + 1llu, 1llu);
                memcpy((void *)list[i], (const void *)&str[begin], begin - end);
                n++;
            }
            break;
        default:
            if (!cut)
            {
                cut = true;
                begin = i;
            }
            break;
        }
    qsort((void *)list, n, sizeof(char *), strDecrea);
    return (char **)realloc((void *)list, sizeof(char *) * (n + 1llu));
}

char ***cutStrList(char **listStr)
{
    char ***list = (char ***)calloc(256llu, sizeof(char **));
    size_t n = 0;
    for (; listStr[n]; n++)
        list[n] = cutStr(listStr[n]);
    return (char ***)realloc((void *)list, sizeof(char **) * (n + 1llu));
}
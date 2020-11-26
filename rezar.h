#pragma once
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char **importListString()
{
    printf("Nhap n: ");
    size_t n;
    scanf("%llu", &n);
    char **list = (char **)calloc(n + 1llu, sizeof(char *));
    size_t length;
    char str[256];
    for (uint64_t i = 0llu; i < n; i++)
    {
        fputc('>', stdout);
        fseek(stdin, 0l, SEEK_SET);
        fgets(str, 256, stdin);
        length = strlen(str);
        list[i] = (char *)calloc(length + 1llu, 1llu);
        memcpy((void *)list[i], (void *)str, length);
    }
    return (char **)realloc(list, sizeof(char *) * (n + 1llu));
}

void countList(char ***list)
{
    for (uint64_t i = 0; list[i]; i++)
    {
        uint64_t j = 0;
        while (list[i][j])
            j++;
    }
}
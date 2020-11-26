#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#define __max_length_of_string 256

char** importStrList()
{
    char** list = (char**)calloc(__max_length_of_string, sizeof(char*));
    size_t n;
    printf("Nhap so n : ");
    scanf("%llu", &n);
    char* tmp = (char*)calloc(__max_length_of_string, sizeof(char));
    size_t length;
    for (size_t i = 0llu; i < n; i++)
    {
        fputc('>', stdout);
        fseek(stdin, 0l, SEEK_SET);
        fgets(tmp, __max_length_of_string, stdin);
        length = strlen(tmp);
        list[i] = (char*)calloc(length + 1llu, sizeof(char));
        memcpy((void*)list[i], (void*)tmp, length);
    }
    //free(tmp);
    realloc(list, sizeof(char*) * (n + 1llu));
    return list;
}

char** cutStr(char* str)
{
    char** list = (char**)calloc(__max_length_of_string, sizeof(char*));
    size_t n = 0;
    size_t begin, end;
    bool cut = false;
    for (uint64_t i = 0; str[i]; i++)
        switch (str[i])
        {
        case ' ':
        case '\0':
        case '\n':
            if (cut)
            {
                cut = false;
                end = i;
                list[n] = (char*)calloc(end - begin + 1llu, sizeof(char));
                memcpy((void*)list[n], (void*)&str[begin], end - begin);
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
    realloc(list, sizeof(char**) * (n + 1llu));
    return list;
}

char*** cutStrList(char** strList)
{
    char*** list = (char***)calloc(__max_length_of_string, sizeof(char**));
    size_t n = 0llu;
    for (; strList[n]; n++)
    {
        list[n] = cutStr(strList[n]);
    }
    realloc(list, sizeof(char**) * (n + 1llu));
    return list;
}

void coutStrList(char*** list)
{
    for (size_t i = 0; list[i]; i++)
    {
        size_t count = 0;
        while (list[i][count])
            count++;
        printf(">%llu\n", count);

    }
}

int main()
{
    char** list = importStrList();
    coutStrList(cutStrList(list));
    return EXIT_SUCCESS;
}
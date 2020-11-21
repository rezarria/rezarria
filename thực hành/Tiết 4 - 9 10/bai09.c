#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define __MAX_LENGTH_OF_NAME 256

typedef struct INFO_S INFO;
typedef INFO* INFO_P;
typedef struct RECORD_S RECORD;
typedef RECORD* RECORD_P;

struct INFO_S
{
    char name[__MAX_LENGTH_OF_NAME];
    //
    char sex[__MAX_LENGTH_OF_NAME];
    char class[__MAX_LENGTH_OF_NAME];
};
struct RECORD_S
{};


char** cutStr(char* str);
void showSTRa(char** list);

int main()
{
    char string[256];
    gets(string);
    showSTRa(cutStr(string));
    return EXIT_SUCCESS;
}

char** cutStr(char* str)
{
    char** list = NULL;
    bool cut = false;
    uint64_t b = 0llu, e = 0llu;
    uint64_t i = -1llu, n = 0llu;
    do
    {
        i++;
        switch (str[i])
        {
        case '\0':
        case ' ':
        {
            if (cut)
            {
                cut = false;
                e = i;
                n++;
                list = (char**)realloc(list, n * sizeof(char*));
                list[n - 1llu] = calloc(e - b + 1llu, 1llu);
                memcpy(list[n - 1llu], str + b, e - b);
            }
            break;
        }
        case '\n':
            break;
        default:
        {
            if (!cut)
            {
                cut = true;
                b = i;
            }
            break;
        }
        }
    } while (str[i] != '\0');
    list = realloc(list, sizeof(char*) * (n + 1));
    list[n] = NULL;
    return list;
}

void showSTRa(char** list)
{
    uint64_t i = 0;
    while (list[i])
    {
        uint64_t j = 0;
        while (list[i][j])
        {
            putc(list[i][j], stdout);
            j++;
        }
        putc('\n', stdout);
        i++;
    }
}


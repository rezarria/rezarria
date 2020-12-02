#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct INFO_S INFO;
typedef INFO* INFO_P;

typedef struct LIST_S LIST;
typedef LIST* LIST_P;

typedef struct STRLIST_S STRLIST;
typedef STRLIST* STRLIST_P;


void swap(void* a, void* b);
char* importString();
uint64_t importUI64();

INFO_P createInfo();
INFO_P importInfo(INFO_P info);

LIST_P createList();
LIST_P createInfoInList(LIST_P list);
LIST_P importInfoInList(LIST_P list);
LIST_P displayInfoInList(LIST_P list);
LIST_P sortList(LIST_P list);

STRLIST_P cutStr(char* str);

STRLIST_P* cutStrList(LIST_P list);

int32_t main()
{
    return EXIT_SUCCESS;
}

char* importString()
{
    printf("> ");
    char* str = (char*)calloc(256llu, sizeof(char));
    fseek(stdin, 0l, SEEK_CUR);
    fgets(str, 256, stdin);
    return str;
}

uint64_t importUI64()
{
    uint64_t n;
    printf("> ");
    scanf("%llu", &n);
    return n;
}

INFO_P createInfo()
{
    return (INFO_P)calloc(1llu, sizeof(INFO));
}

INFO_P importInfo(INFO_P info)
{
    printf("Ten\t:\t");
    info->nameStr = importString();
    printf("Lop\t:\t");
    info->classStr = importString();
    printf("Ngay sinh\n");
    info->dob = (size_t)calloc(3llu, sizeof(size_t));
    printf("Ngay\t:\t");
    info->dob[0] = importUI64();
    printf("Thang\t:\t");
    info->dob[0] = importUI64();
    printf("Nam\t:\t");
    info->dob[0] = importUI64();
    return info;
}

LIST_P createList()
{
    return (LIST_P)calloc(1llu, sizeof(LIST));
}

LIST_P createInfoInList(LIST_P list)
{
    list->n = importUI64();
    list->list = (INFO_P*)calloc(list->n, sizeof(INFO_P));
    return list;
}

LIST_P importInfoInList(LIST_P list)
{
    for (size_t i = 0llu; i < list->n; i++)
        list->list[i] = importInfo(createInfo());
    return list;
}

LIST_P displayInfoInList(LIST_P list)
{
    for (size_t i = 0llu; i < list->n; i++)
    {
        printf("--------------------------------------------\n");
        printf("Ten\t:\t%s", list->list[i]->nameStr);
        printf("Lop\t:\t%s", list->list[i]->classStr);
        printf("Ngay sinh\t:\t%2llu/%2llu/%4llu\n", list->list[i][0], list->list[i][1], list->list[i][3]);
    }
    return list;
}

STRLIST_P cutStr(char* str)
{
    STRLIST_P list = (STRLIST_P)calloc(1llu, sizeof(STRLIST));
    list->list = (char**)calloc(256llu, sizeof(char*));
    list->length = (size_t*)calloc(256llu, sizeof(size_t));
    char* begin = NULL, * end = NULL;
    bool cut = false;
    do
        switch (*str)
        {
        case ' ':
        case '\0':
        case '\n':
            if (cut)
            {
                cut = false;
                end = str;
                list->list[list->n] = (char*)calloc(end - begin + 2llu, sizeof(char));
                strncpy(list->list[list->n], begin, end - begin + 1llu);
                list->length[list->n] = strlen(list->list[list->n]);
                list->n++;
            }
            break;
        default:
            if (!cut)
            {
                cut = true;
                begin = str;
            }
            break;
        }
    while (*(++str));


    list->list = realloc((void*)list->list, sizeof(char*) * list->n);
    list->length = realloc((void*)list->length, sizeof(size_t) * list->n);
    return list;
}

STRLIST_P* cutStrList(LIST_P list)
{
    STRLIST_P* listStr = (STRLIST_P*)calloc(list->n, sizeof(STRLIST_P));
    for (size_t i = 0llu; i < list->n; i++)
        listStr[i] = cutStr(list->list[i]->nameStr);
    return listStr;
}

LIST_P sortList(LIST_P list)
{
    STRLIST_P* listStr = cutStrList(list);
    size_t m = list->n - 1llu;
    for (size_t i = 0llu; i < m; i++)
        for (size_t j = i + 1llu; j < list->n; j++)
            if (strcmp(listStr[i]->list[listStr[i]->n - 1llu], listStr[j]->list[listStr[j]->n - 1llu]) > 0)
            {
                swap((void*)&listStr[i], (void*)&listStr[j]);
                swap((void*)&list->list[i], (void*)&list->list[j]);
            }
    size_t begin = 0llu;
    for (size_t i = 1llu; i < m; i++)
    {
        if (strcmp(listStr[begin]->list[listStr[begin]->n - 1llu], listStr[i]->list[listStr[i]->n - 1llu]) != 0)
        {
            m = i - 1llu;
            for (size_t j = begin; j < m; j++)
            {
                for (size_t z = j + 1llu; z < i; z++)
                    if (listStr[j]->n > listStr[z]->length)
                    {
                        swap((void*)&listStr[j], (void*)&listStr[z]);
                        swap((void*)&list[j], (void*)&list[z]);
                    }
            }
            begin = i;
        }
    }
    return list;
}

struct INFO_S
{
    char* nameStr;
    char* classStr;
    uint64_t* dob;
};

struct LIST_S
{
    INFO_P* list;
    size_t n;
};

struct STRLIST_S
{
    char** list;
    size_t* length;
    size_t n;
};

void swap(void* a, void* b)
{
    *(size_t*)a = *(size_t*)a ^ *(size_t*)b;
    *(size_t*)b = *(size_t*)a ^ *(size_t*)b;
    *(size_t*)a = *(size_t*)a ^ *(size_t*)b;
}

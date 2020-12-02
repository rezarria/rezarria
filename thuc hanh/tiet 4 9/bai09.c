#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct INFO_S
{
    char* nameStr;
    uint32_t dob[3llu];
    char* classStr;
} INFO;
typedef INFO* INFO_P;

typedef struct RECORD_S
{
    uint64_t n;
    INFO_P info;
} RECORD;
typedef RECORD* RECORD_P;

typedef struct STRLIST_S
{
    char** list;
    size_t* length;
    size_t n;
} STRLIST;
typedef STRLIST* STRLIST_P;



INFO_P createInfo(uint64_t n);
INFO_P importInfo(INFO_P info);
INFO_P deleteInfo(INFO_P info);
INFO_P displayInfo(INFO_P info);
RECORD_P createRecord(uint64_t n);
RECORD_P createInfoToRecord(RECORD_P record, uint64_t n);
RECORD_P importInfoOfRecord(RECORD_P record);
RECORD_P deleteRecord(RECORD_P record);
RECORD_P deleteRecordWithAllData(RECORD_P record);
RECORD_P displayInfoOfRecord(RECORD_P record);
RECORD_P sortInfoOfREcord(RECORD_P record);



STRLIST_P cutStr(char* str);
char** createStrList(RECORD_P record);
STRLIST_P* cutStrList(char** listStr, size_t n);

uint64_t importUint64();
uint32_t importUint32();
char* importString();


void show(char** list)
{
    for (;*list; list++)
        puts(*list);
}

int main()
{
    RECORD_P record = createRecord(1llu);
    createInfoToRecord(record, importUint64());
    importInfoOfRecord(record);
    displayInfoOfRecord(record);
    return EXIT_SUCCESS;
}

INFO_P createInfo(uint64_t n)
{
    return (INFO_P)calloc(n, sizeof(INFO));
}

INFO_P importInfo(INFO_P info)
{
    char str[256];
    printf("Ho va ten\t:\t");
    info->nameStr = importString();
    printf("Lop\t:\t");
    info->classStr = importString();
    printf("Ngay sinh\n");
    printf("Ngay\t:\t");
    info->dob[0] = importUint32();
    printf("Thang\t:\t");
    info->dob[1] = importUint32();
    printf("Nam\t:\t");
    info->dob[2] = importUint32();
    return info;
}

INFO_P deleteInfo(INFO_P info)
{
    free((void*)info->nameStr);
    free((void*)info->nameStr);
    free(info);
    return info;
}

INFO_P displayInfo(INFO_P info)
{
    printf("---------------------------------------------------------\n");
    printf("Ho va ten\t:\t%s\n", info->nameStr);
    printf("Lop\t:\t%s\n", info->classStr);
    printf("Ngay sinh\t:\t%2u%2u/%4u\n", info->dob[0], info->dob[1], info->dob[2]);
}

RECORD_P createRecord(uint64_t n)
{
    return (RECORD_P)calloc(n, sizeof(RECORD));
}

RECORD_P createInfoToRecord(RECORD_P record, uint64_t n)
{
    record->info = createInfo(n);
    record->n = n;
    return record;
}

RECORD_P importInfoOfRecord(RECORD_P record)
{
    for (uint64_t i = 0; i < record->n; i++)
        importInfo(&record->info[i]);
    return record;
}

RECORD_P deleteRecord(RECORD_P record)
{
    free((void*)record->info);
    free((void*)record->n);
    return record;
}

RECORD_P deleteRecordWithAllData(RECORD_P record)
{
    for (uint64_t i = 0llu; i < record->n; i++)
        deleteInfo(&record->info[i]);
    free((void*)record->info);
    free((void*)record);
    return record;
}

RECORD_P displayInfoOfRecord(RECORD_P record)
{
    for (uint64_t i = 0llu; i < record->n; i++)
        displayInfo(&record->info[i]);
    return record;
}

RECORD_P sortInfoOfREcord(RECORD_P record)
{
    char** listStr = createStrList(record);
    STRLIST_P* list = cutStrList(listStr, record->n);
    size_t m = record->n - 1llu;
    for (size_t i = 0llu; i < m; i++)
        for (size_t j = i + 1llu; j < record->n; j++)
            if (strcmp(list[i]->list[list[i]->n], list[j]->list[list[j]->n]) > 0)
            {
                
            }
    return record;
}

char* importString()
{
    char* str = (char*)calloc(256llu, sizeof(char));
    fflush(stdin);
    fgets(str, 256, stdin);
    return (char*)realloc(str, sizeof(char) * (strlen(str) + 1llu));
}

uint64_t importUint64()
{
    printf("uint64>");
    uint64_t n;
    scanf("%llu", &n);
    return n;
}

uint32_t importUint32()
{
    printf("uint32>");
    uint64_t n;
    scanf("%u", &n);
    return n;
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
            break;
            if (cut)
            {
                cut = false;
                end = cut;
                list->list[list->n] = (char*)calloc(end - begin + 2llu, sizeof(char));
                strncpy(list->list[list->n], &begin, end - begin + 1llu);
                list->length[list->n] = strlen(list->list[list->n]);
                list->n++;
            }
        default:
            if (!cut)
            {
                cut = true;
                begin = str;
            }
            break;
        }
    while (++str);
    list->list = (char**)realloc(list->list, sizeof(char*) * list->n);
    list->length = (size_t*)realloc(list->length, sizeof(size_t) * list->n);
    return list;
}

STRLIST_P* cutStrList(char** listStr, size_t n)
{
    STRLIST_P* list = (STRLIST_P)calloc(n, sizeof(STRLIST_P));
    for (size_t i = 0llu; i < n; i++)
        list[i] = cutStr(listStr[i]);
    return list;
}

char** createStrList(RECORD_P record)
{
    char** list = (char*)calloc(record->n, sizeof(char*));
    for (size_t i = 0llu; i < record->n; i++)
        list[i] = record->info->nameStr;
    return list;
}

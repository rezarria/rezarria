#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#define InDiaChi(x) printf("0x%016x\n", &x)
#define COLLECT(x). ((COLLECT_P)x)->

typedef struct LIST_S
{
    size_t n;
    char** list;
} LIST;
typedef LIST* LIST_P;

typedef struct STRLIST_S
{
    LIST_P* strList;
    uint64_t n;
} STRLIST;
typedef STRLIST* STRLIST_P;


typedef struct INFO_S
{
    char* nameStr;
    char* classStr;
    uint64_t* dob[3];
} INFO;
typedef INFO* INFO_P;

typedef struct RECORD_S
{
    INFO_P* info;
    uint64_t n;
} RECORD;
typedef RECORD* RECORD_P;

typedef struct COLLECT_S
{
    RECORD_P record;
    STRLIST_P strList;
} COLLECT;
typedef COLLECT* COLLECT_P;


INFO_P taoInfo();
INFO_P nhapInfo(INFO_P info);
INFO_P hienInfo(INFO_P info);
INFO_P xoaInfo(INFO_P info);

RECORD_P taoRecord();
RECORD_P taoInfoTrongRecord(RECORD_P record, size_t n);
RECORD_P nhapInfoTrongRecord(RECORD_P record);
RECORD_P hienInfoTrongRecord(RECORD_P record);
RECORD_P xepInfoTheoTenTrongRecord(RECORD_P record);

STRLIST_P taoStrList(RECORD_P record);




LIST_P cutStr(char* str);

char* nhapString();
uint64_t importUi64();



int main()
{
    RECORD_P record = taoRecord();
    taoInfoTrongRecord(record, importUi64());
    nhapInfoTrongRecord(record);
    hienInfoTrongRecord(record);
    return 0;
}

LIST_P cutStr(char* str)
{
    LIST_P list = (LIST_P)calloc(1llu, sizeof(LIST));
    list->list = (char**)calloc(256llu, sizeof(char*));

    char* begin = NULL, * end = NULL;
    bool cut = false;
    do
        switch (*str)
        {
        case  ' ':
        case '\n':
        case '\0':
            if (cut)
            {
                end = str;
                list->list[list->n] = (char*)calloc(end - begin + 1llu, sizeof(char));
                strncpy(list->list[list->n], begin, end - begin);
                cut = false;
                ///////////////////////////////////////////////
                printf("end\t=\t");
                InDiaChi(*str);
                printf("length\t=\t%llu\n", end - begin);
                printf(">>>>\t\t%s\n", list->list[list->n]);
                printf("-------------------------------------\n");
                ///////////////////////////////////////////////
                list->n++;
            }
            break;
        default:
            if (!cut)
            {
                cut = true;
                begin = str;
                printf("begin\t=\t");
                InDiaChi(*str);
            }
            break;
        }
    while (*(str++));
    list->list = (char**)realloc((void*)list->list, sizeof(char*) * list->n);
    ///////////////////////////////////////////////
    printf("list\t=\t");
    InDiaChi(*list);
    printf("list.n\t=\t%llu\n", list->n);
    printf("-------------------------------------\n");
    ///////////////////////////////////////////////
    return list;
}

INFO_P taoInfo()
{
    return (INFO_P)calloc(1llu, sizeof(INFO));
}

INFO_P nhapInfo(INFO_P info)
{
    printf("Ho va ten\t:\t");
    info->nameStr = nhapString();
    printf("Lop\t\t:\t");
    info->classStr = nhapString();
    printf("Ngay sinh\n");
    printf("Ngay\t\t:\t");
    info->dob[0] = importUi64();
    printf("Thang\t\t:\t");
    info->dob[1] = importUi64();
    printf("Nam\t\t:\t");
    info->dob[2] = importUi64();
    return info;
}

INFO_P hienInfo(INFO_P info)
{
    printf("Ho va ten\t:\t%s", info->nameStr);
    printf("Lop\t\t:\t%s", info->classStr);
    printf("Ngay sinh\t:\t%02llu/%02llu/%04llu\n", info->dob[0], info->dob[1], info->dob[2]);
    printf("-------------------------------------\n");
    return info;
}

INFO_P xoaInfo(INFO_P info)
{
    free((void*)info->classStr);
    free((void*)info->nameStr);
    free((void*)info);
    return info;
}

RECORD_P taoRecord()
{
    return (RECORD_P)calloc(1llu, sizeof(RECORD));
}

RECORD_P taoInfoTrongRecord(RECORD_P record, size_t n)
{
    record->info = (INFO_P*)calloc(n, sizeof(INFO_P));
    record->n = n;
    return record;
}

RECORD_P nhapInfoTrongRecord(RECORD_P record)
{
    for (size_t i = 0llu; i < record->n; i++)
        record->info[i] = nhapInfo(taoInfo());
    return record;
}

RECORD_P hienInfoTrongRecord(RECORD_P record)
{
    for (size_t i = 0llu; i < record->n; i++)
        hienInfo(record->info[i]);
    return record;
}

RECORD_P xepInfoTheoTenTrongRecord(RECORD_P record)
{
    STRLIST_P StrList = taoStrList(record);
    //Xep theo ten
    return record;
}

STRLIST_P taoStrList(RECORD_P record)
{
    STRLIST_P StrList = (STRLIST_P)calloc(1llu, sizeof(STRLIST));
    StrList->strList = (LIST_P*)calloc(record->n, sizeof(LIST_P));
    for (size_t i = 0llu; i < record->n; i++)
        StrList->strList[i] = cutStr(record->info[i]->nameStr);
    return StrList;
}

char* nhapString()
{
    char* str = (char*)calloc(256llu, sizeof(char));
    fseek(stdin, 0l, SEEK_SET);
    fgets(str, 256, stdin);
    return (char*)realloc((void*)str, sizeof(char) * (1llu + strlen(str)));
}

uint64_t importUi64()
{
    uint64_t n;
    scanf("%llu", &n);
    return n;
}

size_t partition(void* _a, void* _b, size_t _sizeA, size_t _sizeB, size_t _low, size_t _high, bool (*cmp)(const void*, const void*), void (*swap)(void*, void*))
{
    void* pivot = (size_t)_a + _sizeA * _high;
    size_t i = _low - 1llu;
    size_t m = _high - 1llu;
    for (size_t j = _low; j < m; j++)
        if (cmp(pivot, (size_t)_a + _sizeA * j))
        {
            i++;
            swap((size_t)_a + _sizeA * i, (size_t)_a + _sizeA * j);
            swap((size_t)_b + _sizeB * i, (size_t)_b + _sizeB * j);
        }
    swap((size_t)_a + _sizeA * (i + 1llu), (size_t)_a + _sizeA * _high);
    swap((size_t)_b + _sizeB * (i + 1llu), (size_t)_b + _sizeB * _high);
    return i;
}

void mQsort(void* _a, void* _b, size_t _sizeA, size_t _sizeB, size_t _low, size_t _high, bool (*cmp)(const void* _a, const void* _b), void (*swap)(void* _a, void* _b))
{
    if (_low < _high)
    {
        size_t pined = partition(_a, _b, _sizeA, _sizeB, _low, _high, cmp, swap);
        mQsort(_a, _b, _sizeA, _sizeB, _low, pined - 1llu, cmp, swap);
        mQsort(_a, _b, _sizeA, _sizeB, pined + 1llu, _high, cmp, swap);
    }
}

void swapF(void* a, void* b, size_t size)
{
    void* tmp = malloc(size);
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
    free(tmp);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#define InDiaChi(x) printf("0x%016x\n", &x)

typedef struct LIST_S
{
    size_t n;
    char** list;
} LIST;
typedef LIST* LIST_P;

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

INFO_P taoInfo();
INFO_P nhapInfo(INFO_P info);
INFO_P hienInfo(INFO_P info);
INFO_P xoaInfo(INFO_P info);

RECORD_P taoRecord();
RECORD_P taoInfoTrongRecord(RECORD_P record, size_t n);
RECORD_P nhapInfoTrongRecord(RECORD_P record);
RECORD_P hienInfoTrongRecord(RECORD_P record);

LIST_P cutStr(char* str);

char* nhapString();

uint64_t nhapUi64();

int main()
{
    RECORD_P record = taoRecord();
    taoInfoTrongRecord(record, nhapUi64());
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
    info->dob[0] = nhapUi64();
    printf("Thang\t\t:\t");
    info->dob[1] = nhapUi64();
    printf("Nam\t\t:\t");
    info->dob[2] = nhapUi64();
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
        nhapInfo(record->info[i]);
    return record;
}

RECORD_P hienInfoTrongRecord(RECORD_P record)
{
    for (size_t i = 0llu; i < record->n; i++)
        hienInfo(record->info[i]);
    return record;
}

char* nhapString()
{
    char* str = (char*)calloc(256llu, sizeof(char));
    fseek(stdin, 0l, SEEK_SET);
    fgets(str, 256, stdin);
    return (char*)realloc((void*)str, sizeof(char) * (1llu + strlen(str)));
}


uint64_t nhapUi64()
{
    uint64_t n;
    scanf("%llu", &n);
    return n;
}

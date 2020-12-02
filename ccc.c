#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct INFO_S INFO;
typedef INFO* INFO_P;

typedef struct LIST_S LIST;
typedef LIST* LIST_P;

char* importString();
uint64_t importUI64();

INFO_P createInfo();
INFO_P importInfo(INFO_P info);

LIST_P createList();


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

struct INFO_S
{
    char* nameStr;
    char* classStr;
    uint64_t* dob;
};

struct LIST_S
{
    INFO_P list;
    size_t n;
};
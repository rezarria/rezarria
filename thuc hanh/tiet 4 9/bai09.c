#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#define __max_length_of_name 256

typedef struct INFO INFO_T;
typedef INFO_T* INFO_P;

typedef struct LIST LIST_T;
typedef LIST_T* LIST_P;

typedef struct LINKSORT_S LINKSORT;
typedef LINKSORT* LINKSORT_P;

INFO_P  createInfo();
void    importInfo(INFO_P info);
void    deleteInfo(INFO_P info);

LIST_P  createList();
void    settingList(LIST_P list);
void    importList(LIST_P list);
void    sortList(LIST_P list);
void    displayList(LIST_P list);
void    deleteInfo(INFO_P info);

char** cutName(char* name);
int cmpStr(const void* a, const void* b);

LINKSORT_P createLinkList(char*** listStrCut, LIST_P list);
LINKSORT_P sortLinkList(LINKSORT_P linkList);


int32_t main(int32_t argc, char** arg)
{

    LIST_P danhSachHocSinh = createList();
    settingList(danhSachHocSinh);
    importInfo(danhSachHocSinh);
    sortList(danhSachHocSinh);
    displayList(danhSachHocSinh);
    deleteInfo(danhSachHocSinh);

    return EXIT_SUCCESS;
}

INFO_P  createInfo()
{
    return (INFO_P)calloc(1llu, sizeof(INFO_T));
}
void importInfo(INFO_P info)
{
    printf("Ho va ten\t:\t");
    fgets(info->name, __max_length_of_name, stdin);
    printf("Ngay sinh\n");
    printf("Ngay\t:\t");
    scanf("%llu", &info->dob[0]);
    printf("Thang\t:\t");
    scanf("%llu", &info->dob[1]);
    printf("Nam\t:\t");
    scanf("%llu", &info->dob[2]);
    printf("Lop\t:\t");
    fgets(info->class, __max_length_of_name, stdin);
}
void deleteInfo(INFO_P info)
{
    free((void*)info);
}

LIST_P createList()
{
    return (LIST_P)calloc(1llu, sizeof(LIST_T));
}
void settingList(LIST_P list)
{
    printf("Nhap so hoc sinh\t:\t");
    scanf("%llu", &list->n);
    list->list = (INFO_P*)calloc(list->n, sizeof(INFO_P));
    for (uint64_t i = 0; i < list->n; i++)
        list->list[i] = createList();
}
void importList(LIST_P list)
{
    for (uint64_t i = 0; i < list->n; i++)
    {
        printf("Hoc sinh thu %3llu\n");
        importInfo(list->list[i]);
    }
}
void sortList(LIST_P list)
{
    char*** nameList = (char***)calloc(list->n, sizeof(char**));
    for (uint64_t i = 0; i < list->n; i++)
        nameList[i] = cutName(list->list[i]->name);
    qsort(nameList, list->n, sizeof(char**), cmpStr);
}



int cmpStr(const void* a, const void* b)
{
    return strcmp(**(char***)a, **(char***)b);
}


LINKSORT_P createLinkList(char*** listStrCut, LIST_P list)
{
    LINKSORT_P listLink = (LINKSORT_P)calloc(1llu, sizeof(LINKSORT));
    listLink->list = list;
    listLink->listStrCut = listStrCut;
    return listLink;
}

LINKSORT_P sortLinkList(LINKSORT_P linkList)
{
    return linkList;
}

struct INFO {
    char name[__max_length_of_name];
    uint64_t dob[3];
    char class[__max_length_of_name];
};

struct LIST
{
    uint64_t n;
    INFO_P* list;
    void* tmp;
};

struct LINKSORT_S
{
    char*** listStrCut;
    LIST_P list;
};
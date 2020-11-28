#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
<<<<<<< Updated upstream
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
=======
#include <stdlib.h>
#include <string.h>
#define __max_length 256llu

typedef struct INFO_S INFO;
typedef INFO* INFO_P;
typedef INFO_P* INFO_L;

char** cutStr(char* str);
char*** cutStrList(char** listStr);
void shows(char** list)
{
    for (uint64_t i = 0; list[i]; i++)
        printf("%s\n", list[i]);
}
INFO_P createInfo();
INFO_L createInfoList(uint64_t n);
INFO_P importInfo(INFO_P info);
INFO_L importInfoList(INFO_L list);
INFO_P displayInfo(INFO_P info);
INFO_L displayInfoList(INFO_L list);
INFO_L sortInfoList(INFO_L list);
uint64_t importN();
uint32_t cmpStr(const void* a, const void* b);
int main()
{
    INFO_L list = createInfoList(importN());
    importInfoList(list);
    displayInfoList(list);
    return EXIT_SUCCESS;
}
>>>>>>> Stashed changes

INFO_P  createInfo();
void    importInfo(INFO_P info);
void    deleteInfo(INFO_P info);

<<<<<<< Updated upstream
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
=======
struct INFO_S
{
    char strName[__max_length];
    uint64_t uint64Dob[3llu];
    char strClass[__max_length];
};

char** cutStr(char* str)
{
    char** list = (char**)calloc(__max_length, sizeof(char*));
    uint64_t n = 0llu;
    uint64_t begin = 0llu, end = 0llu;
    bool cut = false;
    uint64_t i = 0llu;
    do
        switch (str[i])
        {
        case ' ':
        case '\0':
        case '\n':
            if (cut)
            {
                end = i;
                cut = false;
                list[n] = (char*)calloc(end - begin + 1llu, sizeof(char));
                strncpy(list[n], &str[begin], end - begin);
                n++;
            }
            break;
        default:
            if (!cut)
            {
                begin = i;
                cut = true;
            }
            break;
        }
    while (str[i++]);
    return (char**)realloc(list, sizeof(char*) * (n + 1llu));
}

char*** cutStrList(char** listStr)
{
    char*** list = (char***)calloc(__max_length, sizeof(char**));
    uint64_t n = 0llu;
    for (uint64_t i = 0llu; listStr[i]; i++)
    {
        list[n] = cutStr(listStr[i]);
        n++;
    }
    return (char***)realloc(list, sizeof(char**) * (n + 1llu));
}
>>>>>>> Stashed changes

INFO_P createInfo()
{
    return (INFO_P)calloc(1llu, sizeof(INFO));
}

<<<<<<< Updated upstream
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
=======
INFO_L createInfoList(uint64_t n)
{
    INFO_L list = (INFO_L)calloc(n + 1llu, sizeof(INFO_P));
    for (uint64_t i = 0; i < n; i++)
        list[i] = createInfo();
    return list;
}

INFO_P importInfo(INFO_P info)
{
    printf("Ho va ten\t:\t");
    fseek(stdin, 0ll, SEEK_SET);
    fgets(info->strName, __max_length, stdin);
    printf("Nhay sinh\n");
    printf("Ngay\t:\t");
    scanf("%llu", &info->uint64Dob[0]);
    printf("Thang\t:\t");
    scanf("%llu", &info->uint64Dob[1]);
    printf("Nam\t:\t");
    scanf("%llu", &info->uint64Dob[2]);
    printf("Lop\t:\t");
    fseek(stdin, 0ll, SEEK_SET);
    fgets(info->strClass, __max_length, stdin);
    return info;
}

INFO_L importInfoList(INFO_L list)
{
    for (uint64_t i = 0; list[i]; i++)
    {
        printf("\n---------------------------\n");
        importInfo(list[i]);
    }
    return list;
}

INFO_L displayInfoList(INFO_L list)
{
    for (uint64_t i = 0; list[i]; i++)
    {
        printf("---------------------------\n");
        displayInfo(list[i]);
    }
    return list;
}

INFO_P displayInfo(INFO_P info)
{
    printf("Ho va ten\t:\t%s", info->strName);
    printf("Ngay sinh\t:\t%02llu/%02llu/%04llu\n", info->uint64Dob[0], info->uint64Dob[1], info->uint64Dob[2]);
    printf("Lop\t\t:\t%s\n", info->strClass);
    return info;
}

INFO_L sortInfoList(INFO_L list)
{
    uint64_t length = 0;
    while (list[length])
        length++;
    qsort(list, length, sizeof(INFO_P), cmpStr);
    return list;
}

uint64_t importN()
{
    uint64_t n;
    fputc('>', stdout);
    scanf("%llu", &n);
    return n;
}

uint32_t cmpStr(const void* a, const void* b)
{
}

>>>>>>> Stashed changes

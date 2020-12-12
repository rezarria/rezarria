#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct INFO_S INFO;
typedef INFO* pINFO;

typedef struct LIST_S LIST;
typedef LIST* pLIST;

pINFO createInfo();
pINFO importInfo(pINFO info);
pINFO importInfo_f(pINFO info, FILE* input);

pLIST createList();
pLIST createList_f(FILE input);
pLIST importList(FILE input);



int32_t main()
{
    return EXIT_SUCCESS;
}

pINFO createInfo()
{
    return (pINFO)calloc(1llu, sizeof(INFO));
}

pINFO importInfo(pINFO info)
{
    return importInfo_f(info, NULL);
}

pINFO importInfo_f(pINFO info, FILE* input)
{
    if (input)
    {
    }
    return info;
}

struct INFO_S
{
    char* nameStudent;
    char* sexStudent;
    char* birthStudent;
};

struct LIST_S
{
    pINFO list;
    uint64_t size;
};
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct INFO_S INFO;
typedef struct NODE_S NODE;

uint32_t importUI32();
uint32_t importUI32_f(FILE* in);
uint64_t importUI64();
uint64_t importUI64_f(FILE* in);

NODE* createNODE(size_t size);
NODE* slectNODE(NODE* node, size_t pos);
NODE* lastNODE(NODE* node);
NODE* pushNODE(NODE* node, NODE* last);

NODE* createINFO();
NODE* importINFO(NODE* info);

NODE* importList(NODE* list);

int32_t main()
{
    printf("So hoc sinh can nhap :\n");
    size_t n = importUI64();
    NODE* list = importList(createNODE(1llu));
    return EXIT_FAILURE;
}

struct INFO_S
{
    char* nameStudent;
    char* sexStudent;
    char* classStudent;
    uint32_t dob[3];
};

struct NODE_S
{
    void* node;
    NODE* next;
};

NODE* slectNODE(NODE* node, size_t pos)
{
    return pos ? slectNODE(node->next, pos - 1llu) : node;
}

NODE* lastNODE(NODE* node)
{
    return (node->next) ? lastNODE(node->next) : node;
}

NODE* pushNODE(NODE* node, NODE* last)
{
    (*lastNODE(node)) = last;
    return node;
}

NODE* createNODE(size_t size)
{
    NODE* node = (NODE*)calloc(1llu, sizeof(NODE));
    node->node = calloc(1llu, size);
    return node;
}

uint32_t importUI32()
{
    return importUI32_f(stdin);
}

uint32_t importUI32_f(FILE* in)
{
    int32_t n;
    if (in == stdin)
        printf("uint32> ");
    fscanf(in, "%u", &n);
    return n;
}


uint64_t importUI64()
{
    return importUI64_f(stdin);
}

uint64_t importUI64_f(FILE* in)
{
    int64_t n;
    if (in == stdin)
        printf("uint64> ");
    fscanf(in, "%llu", &n);
    return n;
}


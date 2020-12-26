#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct NODE_S NODE;
NODE* createNODE(size_t size);
NODE* lastNODE(NODE* node);
NODE* pushNODE(NODE* node, NODE* last);
NODE* selectNODE(NODE* node, size_t pos);
NODE* deleteNODE(NODE* node, size_t pos);
NODE* displayNODE(NODE* node);
NODE* insertNODE(NODE* node, size_t pos, NODE* inserter);

typedef struct  INFO_S INFO;
INFO* Info(NODE* node);
INFO* createINFO();
INFO* importINFO(INFO* info);
INFO* displayINFO(INFO* info);

NODE* displayINFOList(NODE* node);

char* importString();
char* importString_f(FILE* in, char* str);
size_t lengthString_f(FILE* in, char end);
void resetStdin();

uint64_t importUI64();
uint64_t importUI64_f(FILE* in);

struct NODE_S
{
    void* ptr;
    NODE* next;
};

struct INFO_S
{
    char* nameStudent;
    char* classStudent;
    char* sexStudent;
    size_t ageStudent;
};


int32_t main()
{
    NODE* node = createNODE(sizeof(INFO));
    importINFO(Info(node));
    displayINFO(Info(node));
    return EXIT_SUCCESS;
}

NODE* createNODE(size_t size)
{
    NODE* node = (NODE*)calloc(1llu, sizeof(NODE));
    node->ptr = calloc(1llu, size);
    return node;
}

NODE* lastNODE(NODE* node)
{
    return node->next ? lastNODE(node->next) : node;
}

NODE* pushNODE(NODE* node, NODE* last)
{
    lastNODE(node)->next = last;
    return node;
}

NODE* selectNODE(NODE* node, size_t pos)
{
    return pos ? (pos || node->next ? selectNODE(node->next, pos - 1llu) : NULL) : node;
}

NODE* deleteNODE(NODE* node, size_t pos)
{
    if (node)
    {
        NODE* p = pos ? selectNODE(node, pos - 1llu) : node->next;
        NODE* d = pos ? p->next : node;
        if (pos)
            p->next = d->next;
        else
            node = p;
        free(d->ptr);
        free(d);
    }
    return node;
}

NODE* displayNODE(NODE* node)
{
    if (node)
    {
        printf("0x%x016\t0x%x016\n", node, node->ptr);
        displayNODE(node->next);
    }
    return node;
}

NODE* insertNODE(NODE* node, size_t pos, NODE* inserter)
{
    if (pos)
    {
        NODE* t = selectNODE(node, pos - 1llu);
        if (t)
            inserter->next = t->next;
        else
            t = selectNODE(node, pos - 2llu);
        if (t)
            t->next = inserter;
    }
    else
    {
        inserter->next = node;
        node = inserter;
    }
    return node;
}

INFO* Info(NODE* node)
{
    return (INFO*)node->ptr;
}

INFO* createINFO()
{
    return (INFO*)calloc(1llu, sizeof(INFO));
}

INFO* importINFO(INFO* info)
{
    info->nameStudent = importString();
    info->sexStudent = importString();
    info->classStudent = importString();
    info->ageStudent = importUI64();
    return info;
}

INFO* displayINFO(INFO* info)
{
    printf("%s\n", info->nameStudent);
    printf("%s\n", info->sexStudent);
    printf("%s\n", info->classStudent);
    printf("%llu\n", info->ageStudent);
    return info;
}



NODE* displayINFOList(NODE* node)
{
    NODE* p = node;
    do
    {
        displayINFO(Info(p));
        p = p->next;
    } while (p);
    return node;
}



void resetStdin()
{
#if __WINDOWS__
    if (stdin->_base)
        fflush(stdin);
#else
    if (stdin->_IO_buf_base)
    {
        free(stdin->_IO_buf_base);
        stdin->_IO_buf_base = NULL;
        stdin->_IO_buf_end = NULL;
        stdin->_IO_read_base = NULL;
        stdin->_IO_write_base = NULL;
        stdin->_IO_read_ptr = NULL;
        stdin->_IO_write_ptr = NULL;
        stdin->_IO_read_end = NULL;
        stdin->_IO_write_end = NULL;
    }
#endif
}

size_t lengthString_f(FILE* in, char end)
{
    size_t length = 0llu;

#if __WINDOWS__
    length = strchr(in->_base, (int)end) - in->_base;
#else
    length = strchr(in->_IO_buf_base, (int)end) - in->_IO_buf_base;
#endif
    return length;
}

char* importString_f(FILE* in, char* str)
{
    if (in)
    {
        size_t length;
        if (in == stdin)
        {
            printf("string> ");
            resetStdin();
            fgetc(in);
        }
        length = lengthString_f(in, '\n');
        str = (char*)realloc((void*)str, length + 1llu);
        str[length] = '\0';
        if (in == stdin)
#if __WINDOWS__
            memcpy(str, in->_base, length);
#else
            memcpy(str, in->_IO_read_base, length);
#endif
        else
            fgets(str, length, in);
        resetStdin();
    }
    return str;
}

char* importString()
{
    return importString_f(stdin, NULL);
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

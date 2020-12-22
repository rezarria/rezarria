#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define __WINDOWS__ 0

typedef struct NODE_S NODE;

NODE* createNODE(size_t size);
NODE* createI32NODE(int32_t value);
NODE* createDateNODE(int32_t day, int32_t month, int32_t year);
NODE* slectNODE(NODE* node, size_t pos);
int32_t* slectI32(NODE* n, size_t pos);
NODE* pushNODE(NODE* node, NODE* last);

void importDate(NODE* date, int32_t day, int32_t month, int32_t year);
NODE* importDateArray();
void displayDate(NODE* date);
NODE* nearestDate(NODE* datas);

int32_t importI32();
int32_t importI32_f(FILE* in);
void resetStdin();
char importChar();
char importChar_f(FILE* in);

int32_t main()
{
    NODE* dates = importDateArray();
    displayDate(nearestDate(dates));
    return EXIT_SUCCESS;
}

struct NODE_S
{
    void* node;
    NODE* next;
};

NODE* createNODE(size_t size)
{
    NODE* node = (NODE*)calloc(1llu, sizeof(NODE));
    node->node = calloc(1llu, size);
    return node;
}

NODE* createI32NODE(int32_t value)
{
    NODE* node = createNODE(sizeof(int32_t));
    *(int32_t*)node->node = value;
    return node;
}

NODE* createDateNODE(int32_t day, int32_t month, int32_t year)
{
    return pushNODE(createI32NODE(year), pushNODE(createI32NODE(month), createI32NODE(day)));
}

NODE* slectNODE(NODE* node, size_t pos)
{
    return pos ? slectNODE(node->next, pos - 1llu) : node;
}

int32_t* slectI32(NODE* ui64s, size_t pos)
{
    return (int32_t*)slectNODE(ui64s, pos);
}

NODE* pushNODE(NODE* node, NODE* last)
{
    if (node->next)
        pushNODE(node->next, last);
    else
        node->next = last;
    return node;
}

void importDate(NODE* date, int32_t day, int32_t month, int32_t year)
{
    *slectI32(date, 0llu) = year;
    *slectI32(date, 1llu) = month;
    *slectI32(date, 2llu) = day;
}

NODE* importDateArray()
{
    NODE* node = createNODE(0llu);
    char key;
    do
    {
        switch (key = importChar())
        {
        case 'n':
        {
            printf("----------------------------------------------\n");
            printf("Nhap ngay thang nam\n");
            pushNODE(node, createDateNODE(importI32(), importI32(), importI32()));
            break;
        }
        case '\\':
            printf("Thoat\n");
        }
    } while (key == 'n');
    return node;
}

void displayDate(NODE* node)
{
    printf("%02llu/%02llu%llu\n", *slectI32(node, 0llu), *slectI32(node, 1llu), *slectI32(node, 2llu));
}

NODE* nearestDate(NODE* dates)
{
    NODE* nearest = dates;
    dates = dates->next;
    time_t t = time(NULL);
    struct tm* d = localtime(&t);
    while (dates)
    {
        if (
            (abs(*slectI32(dates->node, 0llu) - d->tm_wday) > abs(*slectI32(nearest, 0llu) - d->tm_wday)) &&
            (abs(*slectI32(dates->node, 1llu) - d->tm_mon) > abs(*slectI32(nearest, 1llu) - d->tm_mon)) &&
            (abs(*slectI32(dates->node, 2llu) - d->tm_year) > abs(*slectI32(nearest, 2llu) - d->tm_year))
            )
            nearest = dates;
        dates = dates->next;
    }
    return nearest;
}

int32_t importI32()
{
    return importI32_f(stdin);
}

int32_t importI32_f(FILE* in)
{
    int32_t n;
    if (in == stdin)
        printf("int32> ");
    fscanf(in, "%d", &n);
    return n;
}

char importChar()
{
    return importChar_f(stdin);
}

char importChar_f(FILE* in)
{
    if (in == stdin)
        printf("char> ");
    resetStdin();
    char c = fgetc(stdin);
    resetStdin();
    return c;
}

void resetStdin()
{
#if __WINDOWS__
    if (stdin->_base)
        fflush(stdin);
#else
    if (stdin->_IO_read_ptr)
        stdin->_IO_read_ptr = stdin->_IO_buf_end - 1llu;
#endif
}
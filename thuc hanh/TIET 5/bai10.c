//VÕ TÁ NAM
//205748010310003
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define LENGTH_OF_NAME 256
#define SIZE_DEFAULT 20

typedef struct INFO_STUDENT_S
{
    char* nameStudent;
    size_t ageStudent;
    float score[3];
} INFO_STUDENT;

typedef struct LIST_S
{
    INFO_STUDENT** info;
    size_t size;
} LIST;

INFO_STUDENT* createInfo();
INFO_STUDENT* importInfo(INFO_STUDENT* info);
INFO_STUDENT* importInfo_f(FILE* input, INFO_STUDENT* info);
LIST* createList(size_t n);
LIST* importList(LIST* list);
LIST* reSizeList(LIST* list, size_t size);

void pushInfo(LIST* list, INFO_STUDENT* info);

char* importString_f(FILE* in, char* str);
uint64_t importUI64_f(FILE* in);
float importFloat_f(FILE* in);

int32_t main()
{
    importList(NULL);
    return EXIT_SUCCESS;
}

INFO_STUDENT* createInfo()
{
    return (INFO_STUDENT*)calloc(1llu, sizeof(INFO_STUDENT));
}

INFO_STUDENT* importInfo(INFO_STUDENT* info)
{
    return importInfo_f(stdin, info);
}

INFO_STUDENT* importInfo_f(FILE* input, INFO_STUDENT* info)
{
    if (input == stdin)
        printf("---------------------------------------------\n");
    if (input == stdin)
        printf("Ho va ten\t:\t");
    info->nameStudent = importString_f(input, info->nameStudent);
    if (input == stdin)
        printf("Tuoi\t:\t");
    info->ageStudent = importUI64_f(input);
    for (size_t i = 0llu; i < 3llu; i++)
    {
        if (input == stdin)
            printf("Diem %2llu\t:\t", i);
        info->score[i] = importFloat_f(input);
    }
    return info;
}

LIST* createList(size_t n)
{
    LIST* list = (LIST*)calloc(1llu, sizeof(LIST));
    list->size = n;
    list->info = (INFO_STUDENT**)calloc(n, sizeof(__ptr_t));
    return list;
}

LIST* importList(LIST* list)
{
    printf("Nhap 'n' de tao them thong tin hoc sinh\n");
    printf("Nhap '\\' de thoat\n");
    char key = 0xA;
    bool run = true;
    do
    {
        key = fgetc(stdin);
        switch (key)
        {
        case 'n':
        {
            printf("---------------------------------------\n");
            pushInfo(list, importInfo(createInfo()));
            break;
        }
        case '\\':
            printf("THOAT\n");
            run = false;
        }
    } while (run);

    return list;
}

LIST* importList_f(FILE* input, LIST* list)
{
    reSizeList(list, importUI64_f(input));
    for (size_t i = 0llu; i < list->size; i++)
        list->info[i] = importInfo_f(input, createInfo());
    return list;
}

LIST* reSizeList(LIST* list, size_t size)
{
    list->size = size;
    list->info = (INFO_STUDENT**)realloc((void*)list->info, sizeof(__ptr_t));
    return list;
}

void pushInfo(LIST* list, INFO_STUDENT* info)
{
    reSizeList(list, list->size + 1llu);
    list->info[list->size - 1llu] = info;
}

char* importString_f(FILE* in, char* str)
{
    char line[256];
    if (in == stdin)
    {
        if (strncmp(stdin->_IO_write_ptr, "n\n", 2llu));
        do
            fgetc(stdin);
        while (strncmp(stdin->_IO_write_ptr, "n\n", 2llu));
        printf("string> ");
    }
    fgets(line, 256, in);
    size_t length = strlen(line) + 1llu;
    str = (char*)realloc((void*)str, sizeof(char) * length);
    memcpy((void*)str, (void*)line, length);
    return str;
}

uint64_t importUI64_f(FILE* in)
{
    int64_t n;
    if (in == stdin)
        printf("uint64> ");
    fscanf(in, "%llu", &n);
    return n;
}

float importFloat_f(FILE* in)
{
    float f;
    if (in == stdin)
        printf("float> ");
    fscanf(in, "%f", &f);
    return f;
}

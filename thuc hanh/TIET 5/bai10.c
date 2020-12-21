//VÕ TÁ NAM
//205748010310003
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

typedef struct INFO_STUDENT_S
{
    char* nameStudent;
    size_t ageStudent;
    float score[4];
} INFO_STUDENT;

typedef struct LIST_S
{
    INFO_STUDENT** info;
    size_t size;
    size_t max;
} LIST;

INFO_STUDENT* createInfo();
INFO_STUDENT* importInfo(INFO_STUDENT* info);
INFO_STUDENT* importInfo_f(FILE* input, INFO_STUDENT* info);
void displayInfo(INFO_STUDENT* info);
void exportInfo(FILE* out, INFO_STUDENT* info);

LIST* createList(size_t n);
LIST* importList(LIST* list);
LIST* reSizeList(LIST* list, size_t size);
LIST* fixSizeList(LIST* list);
void exportList(FILE* out, LIST* list);
size_t whoIsBest(LIST* list);


void pushInfo(LIST* list, INFO_STUDENT* info);

char* importString_f(FILE* in, char* str);
uint64_t importUI64_f(FILE* in);
float importFloat_f(FILE* in);
char importChar();
char importChar_f(FILE* in);
void resetStdin();
size_t lengthString_f(FILE* in);


int32_t main()
{
    LIST* list = importList(createList(1llu));
    FILE* f = fopen("bai10.out", "w");
    exportList(f, list);
    fclose(f);
    displayInfo(list->info[whoIsBest(list)]);
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
        printf("Tuoi\t\t:\t");
    info->ageStudent = importUI64_f(input);
    for (size_t i = 1llu; i < 4llu; i++)
    {
        if (input == stdin)
            printf("Diem %2llu\t\t:\t", i);
        info->score[i] = importFloat_f(input);
    }
    info->score[0] = (info->score[1] + info->score[2] * 2.0f) / 3.0f;
    return info;
}

void displayInfo(INFO_STUDENT* info)
{
    printf("-------------------------------------------------------\n");
    printf("Ho va ten\t:\t%30s\n", info->nameStudent);
    printf("Tuoi\t\t:\t%30llu\n", info->ageStudent);
    for (size_t i = 1llu; i < 4llu; i++)
        printf("Diem :%2llu\t:\t%30.2f\n", i, info->score[i]);
    printf("Diem TBC\t:\t%30.2f\n", info->score[3]);
}

void exportInfo(FILE* out, INFO_STUDENT* info)
{
    fprintf(out, "%s\n", info->nameStudent);
    fprintf(out, "%llu\n", info->ageStudent);
    for (size_t i = 1llu; i < 4; i++)
        fprintf(out, "%f\n", info->score[i]);
    fprintf(out, "%f\n", info->score[0]);

}

LIST* createList(size_t n)
{
    LIST* list = (LIST*)calloc(1llu, sizeof(LIST));
    list->max = n;
    list->info = (INFO_STUDENT**)calloc(list->max, sizeof(__ptr_t));
    return list;
}

LIST* importList(LIST* list)
{
    if (list)
    {
        printf("Nhap 'n' de tao them thong tin hoc sinh\n");
        printf("Nhap '\\' de thoat\n");
        char key = 0xA;
        bool run = true;
        char key;
        do
            switch (key = importChar())
            {
            case 'n':
            {
                pushInfo(list, importInfo(createInfo()));
                break;
            }
            case '\\':
                printf("THOAT\n");
        } while (key == 'n');
    }
    fixSizeList(list);
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
    list->max = size;
    list->info = (INFO_STUDENT**)realloc((void*)list->info, sizeof(__ptr_t) * list->size * 2llu);
    return list;
}

LIST* fixSizeList(LIST* list)
{
    list->info = (INFO_STUDENT**)realloc((void*)list->info, sizeof(__ptr_t) * list->size);
    list->max = list->size;
    return list;
}

void exportList(FILE* out, LIST* list)
{
    fprintf(out, "%llu\n", list->size);
    for (size_t i = 0llu; i < list->size; i++)
        exportInfo(out, list->info[i]);
}

size_t whoIsBest(LIST* list)
{
    size_t pos = 0llu;
    for (size_t i = 1llu; i < list->size; i++)
        if (list->info[pos]->score[3] < list->info[i]->score[3])
            pos = i;
    return pos;
}

void pushInfo(LIST* list, INFO_STUDENT* info)
{
    list->size++;
    if (list->size > list->max)
reSizeList(list, list->max + 1llu);
    list->info[list->size - 1llu] = info;
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
        length = lengthString_f(in);
        str = (char*)realloc((void*)str, length + 1llu);
        str[length] = '\0';
        if (in == stdin)
            memcpy(str, in->_IO_read_base, length);
        else
            fgets(str, length, in);
        resetStdin();
    }
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
    if (stdin->_IO_read_ptr)
        stdin->_IO_read_ptr = stdin->_IO_buf_end - 1llu;
}

size_t lengthString_f(FILE* in)
{
    size_t length = 0llu;
    if (in == stdin)
        length = strlen(stdin->_IO_read_base) - 1llu;
    else
    {
        fpos_t pos;
        fgetpos(in, &pos);
        while (!feof(in))
        {
            if (fgetc(in) == '\n')
                break;
            length++;
        }
        fsetpos(in, &pos);
    }
    return length;
}

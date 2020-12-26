#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

char* importString_f(FILE* in, char* str)
{
    if (in == stdin)
        printf("string> ");
    fgets(str, 256llu, in);
    return (char*)realloc((void*)str, strlen(str) + 1llu);
}


void swap(uintptr_t _a, uintptr_t _b, size_t _size)
{
    uintptr_t tmp = (uintptr_t)malloc(_size);
    memcpy((void*)tmp, (void*)_a, _size);
    memcpy((void*)_a, (void*)_b, _size);
    memcpy((void*)_b, (void*)tmp, _size);
}

bool isMaxI32(int32_t a, int32_t b)
{
    return a > b;
}

char* importString_f(FILE* in, char* str)
{
    if (in == stdin)
        printf("string> ");
    fgets(str, 256llu, in);
    return (char*)realloc((void*)str, strlen(str) + 1llu);
}

int32_t importI32()
{
    return importI32_f(stdin);
}

int32_t importI32_f(FILE* in)
{
    int32_t n;
    if (in == stdin)
        fprintf(stdout, "int32> ");
    fscanf(in, "%d", &n);
    return n;
}

int32_t** createI32Matrix(size_t n, size_t m)
{
    int32_t** matrix = (int32_t**)malloc(n * sizeof(int32_t*));
    for (size_t i = 0llu; i < n; i++)
        matrix[i] = (int32_t*)calloc(m, sizeof(int32_t));
    return matrix;
}

void importI32Matrix(int32_t** matrix, size_t n, size_t m)
{
    for (size_t i = 0llu; i < n; i++)
        for (size_t j = 0llu; j < m; j++)
        {
            printf("[%llu][%llu] ", i, j);
            matrix[i][j] = importI32();
        }
}

void importUI32Matrix_f(FILE* input, int32_t** matrix, size_t n, size_t m)
{
    for (size_t i = 0llu; i < n; i++)
        importI32Arr_f(input, matrix[i], m);
}

void displayUI32Matrix(FILE* out, int32_t** matrix, size_t n, size_t m)
{
    fprintf(out, "%llu\t%llu\n", n, m);
    size_t p = m - 1llu;
    for (size_t i = 0llu; i < n; i++)
    {
        for (size_t j = 0llu; j < m; j++)
        {
            fprintf(out, "%llu", matrix[i][j]);
            fputc((j == p) ? '\n' : '\t', out);
        }
    }
}

int32_t** getI32Matrix_f(FILE* input, size_t* n, size_t* m)
{
    int32_t** matrix;
    *n = importUI64_f(input);
    *m = importUI64_f(input);
    matrix = createI32Matrix(*n, *m);
    for (size_t i = 0llu; i < *n; i++)
        for (size_t j = 0llu; j < *m; j++)
            matrix[i][j] = importI32(input);
    return matrix;
}

size_t rowSizeOf(FILE* in)
{
    fseek(in, 0l, SEEK_SET);
    char c;
    bool r = false;
    size_t row = 0llu;
    do
    {
        c = fgetc(in);
        switch (c)
        {
        case ' ':
        case '\n':
        {
            if (r)
            {
                r = false;
                row++;
            }
            break;
        }
        default:
            if (!r)
                r = true;
        }
    } while (c != '\n');
    if (r) row++;
    return row;
}

size_t columnSizeOf(FILE* in)
{
    fseek(in, 0l, SEEK_SET);
    size_t column = 0llu;
    char c;
    bool r = true;
    do
    {
        c = fgetc(in);
        if (c == '\n')
        {
            column++;
            r = false;
        }
        if (!r)
            r = true;
    } while (!feof(in));
    if (r) column++;
    return column;
}

void matrixSizeOf(FILE* input, size_t* n, size_t* m)
{
    *m = rowSizeOf(input);
    *n = columnSizeOf(input);
    fseek(input, 0l, SEEK_SET);
}

int32_t** getUI32Matrix_f_auto(FILE* input, size_t* n, size_t* m)
{
    matrixSizeOf(input, n, m);
    int32_t** matrix = createI32Matrix(*n, *m);
    importUI32Matrix_f(input, matrix, *n, *m);
    return matrix;
}

void importI32Arr_f(FILE* input, int32_t* arr, uint64_t n)
{
    for (uint64_t i = 0llu; i < n; i++)
        arr[i] = importUi32_f(input);
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

float importFloat()
{
    return importFloat_f(stdin);
}

float importFloat_f(FILE* in)
{
    float f;
    if (in == stdin)
        printf("float> ");
    fscanf(in, "%f", &f);
    return f;
}

float* importFloatArry(uint64_t n)
{
    return importFloatArry_f(n, stdin);
}

float* importFloatArry_f(uint64_t n, FILE* in)
{
    float* f = (float*)calloc(n, sizeof(float));
    for (uint64_t i = 0; i < n; i++)
        f[i] = importFloat_f(in);
    return f;
}

float** createFloatMatrix(size_t n, size_t m)
{
    float** matrix = (float**)malloc(n * sizeof(float*));
    for (size_t i = 0llu; i < n; i++)
        matrix[i] = (float*)calloc(m, sizeof(float));
    return matrix;
}

float** getFloatMatrix_f(FILE* input, size_t* n, size_t* m)
{
    float** matrix;
    *n = importUI64_f(input);
    *m = importUI64_f(input);
    matrix = createFloatMatrix(*n, *m);
    for (size_t i = 0llu; i < *n; i++)
        for (size_t j = 0llu; j < *m; j++)
            matrix[i][j] = importFloat_f(input);
    return matrix;
}

void displayFloatMatrix(float** matrix, size_t n, size_t m)
{
    printf("Ma tran %llu x %llu \n", n, m);
    printf("-------------------------------------------\n");
    size_t p = m - 1llu;
    for (size_t i = 0llu; i < n; i++)
    {
        for (size_t j = 0llu; j < m; j++)
        {
            fprintf(stdout, "%5.2f", matrix[i][j]);
            fputc((j == p) ? '\n' : '\t', stdout);
        }
    }
}

bool isPrime(uint32_t n)
{
    bool check = true;
    switch (n)
    {
    case 2:
    case 3:
    case 5:
    case 7:
    case 11:
        break;
    default:
        if (n % 2)
        {
            for (uint32_t i = sqrt(n); i > 2u; i--)
                if ((n % i) == 0)
                {
                    check = false;
                    break;
                }
        }
        else check = false;
    }
    return check;
}

char* getLine(FILE* input)
{
    int32_t length = 0llu;
    do
        length++;
    while (fgetc(input));
    char* str = (char*)malloc(sizeof(char) * length);
    fseek(input, SEEK_CUR, -length);
    for (int i = 0; i < length; i++)
        str[i] = (char)fgetc(input);
    return str;
}

char* decToBin(uint32_t n)
{
    char* bin = (char*)calloc(33llu, sizeof(char));
    size_t i = 32llu;
    while (i)
    {
        i--;
        bin[i] = '0' + n % 2u;
        n /= 2u;
    }
    return bin;
}

char* decToHex(uint32_t n)
{
    char* hex = (char*)calloc(9llu, sizeof(char));
    size_t i = 8llu;
    while (i)
    {
        i--;
        hex[i] = '0' + n % 16u;
        if (hex[i] > '9')
            hex[i] += 7llu;
        n /= 16u;
    }
    return hex;
}

uint32_t gcd(size_t a, size_t b)
{
    while (a == b)
        if (a > b)
            a -= b;
        else
            b -= a;
    return a;
}

uint32_t lcm(size_t a, size_t b)
{
    return (a * b) / gcd(a, b);
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
    if (stdin->_IO_buf_base)
    {
        stdin->_IO_read_ptr = stdin->_IO_buf_end;
        stdin->_IO_write_ptr = stdin->_IO_buf_end;
        stdin->_IO_read_end = stdin->_IO_buf_end;
        stdin->_IO_write_end = stdin->_IO_buf_end;
    }
#endif
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

typedef struct NODE_S NODE;

struct NODE_S
{
    void* node;
    NODE* next;
};

struct NODE_S
{
    void* ptr;
    NODE* next;
};

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
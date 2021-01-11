#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int nhapGiaTri();
int* taoMaTran(int n, int m);
int* nhapMaTran(int* maTran, int n, int m);
int* chuyenViMaTran(int* maTran, int n, int m);
int* hienMaTran(int* maTran, int n, int m);
void swap(void* a, void* b, size_t size);


int main()
{
    int n, m;
    printf("Nhap n : ");
    n = nhapGiaTri();

    printf("Nhap m : ");
    m = nhapGiaTri();

    free(hienMaTran(chuyenViMaTran(nhapMaTran(taoMaTran(n, m), n, m), n, m), n, m));

    return 0;
}

int nhapGiaTri()
{
    int n;
    do
    {
        printf("> ");
        scanf("%d", &n);
    } while (n < 1);
    return n;
}

int* taoMaTran(int n, int m)
{
    return calloc(n * m, sizeof(int));
}

int* nhapMaTran(int* maTran, int n, int m)
{
    int i = 0;
    int j = 0;
    int* p = maTran;
    for (; i < n; i++)
        for (j = 0; j < m; j++)
        {
            printf("[%d][%d]\t: ", i, j);
            scanf("%d", p++);
        }
    return maTran;
}

int* chuyenViMaTran(int* maTran, int n, int m)
{
    size_t size = sizeof(int);
    int i = 0;
    int j = 0;
    for (; i < n; i++)
        for (j = 0; j < m; j++)
            swap(maTran + i * n + j * m, maTran + i * m + j * n, size);
    return maTran;
}

int* hienMaTran(int* maTran, int n, int m)
{
    int i = 0;
    int j = 0;
    int* p = maTran;
    for (; i < n; i++)
    {
        putchar('\n');
        for (j = 0; j < m; j++)
            printf("%4d", *(p++));
    }
    return maTran;
}

void swap(void* a, void* b, size_t size)
{
    putchar('!');
    void* c = malloc(size);
    memcpy(c, a, size);
    memcpy(a, b, size);
    memcpy(b, c, size);
    free(c);
}
#include <stdio.h>
#include <stdlib.h>


int nhapGiaTri();
int* taoMang(int n);
int* nhapMang(int* n);
int* xemMang(int* n);

int main()
{
    free(xemMang(nhapMang(taoMang(nhapGiaTri()))) - 1);
    return 0;
}

int nhapGiaTri()
{
    int n;
    do
    {
        printf("Nhap n : ");
        scanf("%d", &n);
    } while (n < 1);

    return n;
}

int* taoMang(int n)
{
    int* p = calloc(n + 1, sizeof(int));
    p++;
    p[-1] = n;
    return p;
}

int* nhapMang(int* p)
{
    int n = p[-1];
    int i = 0;
    for (; i < n; i++)
    {
        printf("[%d] : ", i);
        scanf("%d", p + i);
    }
    return p;
}

int* xemMang(int* p)
{
    printf("-------------------\n");
    int n = p[-1];
    int i = 0;
    for (; i < n; i++)
        printf("[%d] = %d\n", i, p[i]);
    return p;
}
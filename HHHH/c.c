#include <stdio.h>
#include <stdlib.h>

int *MaTran(int m, int n)
{
    return (int *)calloc(m * n, sizeof(int));
}

int *nhapMaTran(int *mt, int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            printf("0x%08x %d %d : ", (void *)(mt + n * m * i + n * j), i, j);
            scanf("%d", &mt[n * m * i + n * j]);
        }
    return mt;
}

void hienMaTran(int *mt, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", mt[n * m * i + n * j]);
        putchar('\n');
    }
}

int *congMaTran(int *a, int *b, int m, int n)
{
    int *mt = MaTran(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mt[n * (m * j + i)] = a[n * (m * j + i)] + b[n * (m * j + i)];
    perror("congMaTran");
    return mt;
}

int main()
{
    int *a = nhapMaTran(MaTran(3, 3), 3, 3);
    hienMaTran(congMaTran(a, a, 3, 3), 3, 3);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int **MATRAN(char *ten, int *n, int *m)
{
    FILE *f = fopen(ten, "r");
    fscanf(f, "%d%d", n, m);
    int **matran = (int **)malloc(sizeof(int *) * *n);
    for (int i = 0; i < *n; i++)
    {
        matran[i] = (int *)malloc(sizeof(int) * *m);
        for (int j = 0; j < *m; j++)
            fscanf(f, "%d", matran[i] + j);
    }
    fclose(f);
    return matran;
}

void hienMaTran(int **matran, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%6d", matran[i][j]);
        putchar('\n');
    }
}

void xoaMaTran(int **matran, int n, int m)
{
    for (int i = 0; i < n; i++)
        free(matran[i]);
    free(matran);
}

int main()
{
    int n, m;
    int **matran = MATRAN("input.txt", &n, &m);
    hienMaTran(matran, n, m);
    xoaMaTran(matran, n, m);
    return 0;
}
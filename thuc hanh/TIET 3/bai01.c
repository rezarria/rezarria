#include <stdio.h>

int tong(int n)
{
    int i, s = 0;
    for (i = 1; i <= n; i++)
        s += i;
    return s;
}

int main()
{
    FILE* file = fopen("bai01.inp", "r");
    int n;
    fscanf(file, "%d", &n);
    printf("n\t=\t%d\n", n);
    fclose(file);
    file = fopen("bai01.out", "w");
    n = tong(n);
    fprintf(file, "\n%5d", n);
    printf("Tong\t=\t%d", n);
    fclose(file);
    return 0;
}
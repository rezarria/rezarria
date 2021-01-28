#include <stdio.h>

int main()
{
    FILE* f1, * f2;
    f1 = fopen("mang.inp", "r");
    int n, m;
    fscanf(f1, "%d%d", &n, &m);
    int t = 0, a;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            fscanf(f1, "%d", &a);
            t += a;
        }
    fclose(f1);
    f2 = fopen("mang.out", "w");
    fprintf(f2, "%d", t);
    fclose(f2);
    return 0;
}
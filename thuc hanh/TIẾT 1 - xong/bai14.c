#include <stdio.h>
int main()
{
    int i, j;
    printf("Nhap hai so i va j :");
    scanf("%d%d", &i, &j);
    printf("!i\t=\t%d\n!j\t=\t%d\n", !i, !j);
    printf("! && j\t=\t%d\ni || j\t=\t%d\n", i && j, i || j);
    printf("~i\t=\t%d\n~j\t=\t%d\n", ~i, ~j);
    printf("i &  j\t=\t%d\ni |  j\t=\t%d\n", i & j, i | j);
    printf("i ^  j\t=\t%d\n", i ^ j);
    printf("i << j\t=\t%d\ni >> j\t=\t%d\n", i << j, i >> j);
    printf("j << i\t=\t%d\nj >> i\t=\t%d\n", j << i, j >> i);
    return 0;
}

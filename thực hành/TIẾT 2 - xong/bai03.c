#include <conio.h>
#include <stdio.h>
int main()
{
    float a[10], s = 0;
    int n, i;
    printf("\nNhap so phan tu cua mang n = ");
    scanf("%d", &n);
    printf("\nNhap mang:\n");
    for (i = 0; i < n; i++)
    {
        printf("\nNhap a[%d] = ", i);
        scanf("%f", &a[i]);
    }
    printf("\nXem mang:\n");
    for (i = 0; i < n; i++)
        printf("%5.2f", a[i]);
    for (i = 0; i < n; i++)
        s += a[i];
    printf("\n%5.2f", s);
    getch();
    return 0;
}
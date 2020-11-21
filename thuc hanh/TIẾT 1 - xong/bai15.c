#include <stdio.h>
int main()
{
    int a, b;
    printf("Nhap sao so a, b : ");
    scanf("%d%d", &a, &b);
    printf("Chu vi hinh chu nhat la\t=\t%d", 2 * (a + b));
    printf("\nDien tich hinh chu nhat\t=\t%d", a * b);
    return 0;
}
#include <stdio.h>
int main()
{
    int n;
    printf("Nhap n : ");
    scanf("%d", &n);
    float s = 0;
    int i = 100;
    while (i >= n)
    {
        s += 1.0 / n;
        i--;
    }
    printf("s = %f", s);
    return 0;
}

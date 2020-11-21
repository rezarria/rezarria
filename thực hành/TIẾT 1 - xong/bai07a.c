#include <stdio.h>
int main()
{
    int a, b, c, max;
    /*
        4 biến số nguyên a, b, c, max
        3 biến số nguyên a, b, c dùng để nhập giá trị vào
        biến số nguyên max được dùng trong việc tìm ra giá trị lớn nhất trong ba biến a, b, c
    */
    printf("Nhap a, b, c : ");
    scanf("%d%d%d", &a, &b, &c);
    max = a;
    if(max < b)
        max = b;
    if(max < c)
        max = c;
    printf("So lon nhat la %d\n", max);
    return 0;
}
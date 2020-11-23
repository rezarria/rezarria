#include <conio.h>
#include <stdio.h>
int main()
{
    float a, b, max;
    /*
        Hai biên số thực float a, b dùng để nhập.
        Biến số thực max dùng để lưu số lớn nhất
        trong hai số thực a và b.
    */
    printf("Nhap hai so a, b = ");
    scanf("%f%f", &a, &b);
    max = a > b ? a : b;
    // Biển thức so sánh, nếu a > b thì max sẽ = a, nếu không thì max = b
    printf("\nSo lon nhat cua %5.2f va %5.2f la: %5.2f", a, b, max);
    getch();
    return 0;
}
/*
    Chương trình nhập vào 2 số thực a và b và thông báo ra số lớn nhất trong hai.
*/

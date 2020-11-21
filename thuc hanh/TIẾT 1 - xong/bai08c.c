#include <stdio.h>
int main()
{
    int n;
    // Biến số nguyên n dùng để nhập vào
    printf("Nhap n : ");
    scanf("%d", &n);
    n++;
    int s = 0;
    // Biến s dùng làm tổng của dãy số nên khởi tạo ban đầu là 0
    int i = 0;
    // Biến số nguyên i dùng để lặp giá trị từ 0 đến n;
    do
    {
        s += (2 * i + 1);
        i++;
    } while (i < n);
    printf("S = %5d\n", s);
    return 0;
}
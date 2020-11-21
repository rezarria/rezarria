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
    for (int i = 0; i < n; i++)// Biến số nguyên i dùng để lặp giá trị từ 0 đến n;
        s += (2 * i + 1);
    printf("S = %5d\n", s);
    return 0;
}
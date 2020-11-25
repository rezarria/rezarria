#include <conio.h>
#include <stdio.h>
int main()
{
    // Biến mảng số thực a được khởi tạo với 10 phần tử
    // s được dùng để chứa giá trị tổng của biến mảng số thục a nên là biến số thực
    float a[10], s = 0;
    // Biến n để nhập số phần tử sẽ nhập vào a, với n < 11
    // Biến số nguyên i dùng để tham gia vòng lặp từ 0 đến n - 1
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
    // Sau từng vòng lặp thì s sẽ được cộng theo phần tử a[i] vào
    for (i = 0; i < n; i++)
        s += a[i];
    // Thông báo tổng
    printf("\n%5.2f", s);
    getch();
    return 0;
}
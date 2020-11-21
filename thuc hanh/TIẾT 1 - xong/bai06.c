/*
    Kiểm tra xem số nhập nếu >= 0 thì đó là số không âm
    nên sử dụng cấu trúc if với điều kiện n > -1(tương đương n => 0)
*/
#include <stdio.h>
int main()
{
    printf("Nhap so a: ");
    int n;
    scanf("%d", &n);
    if (n > -1)
        printf("a la so khong am");
    return 0;
}
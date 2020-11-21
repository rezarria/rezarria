#include <conio.h> //thư viện conio.h định nghĩa hàm getch
#include <stdio.h> //thư viện studio.h định nghĩa hàm printf và scanf
int main()
{
    //2 biến số nguyên a, b
    int a, b;

    //In xâu ký tự ra màn hình
    printf("Nhap hai so a, b = ");

    //Nhập giá trị vào 2 biến số nguyên a, b
    scanf("%d%d", &a, &b);


    printf("\nTong hai so %5d va %5d La %5d", a, b, a + b);
    printf("\nHieu hai so %5d va %5d la %5d", a, b, a - b);
    printf("\nTich hai so %5d va %5d la %5d", a, b, a * b);
    printf("\nThuong hai so %5d va %5d la %5d", a, b, a / b);
    
    //Dừng chương trình cho tới khi có phản hồi từ bàn phím
    getch();

    //Trả về giá trị 0 và kết thúc chương trình
    return 0;
}
/*
    Chương trình nào dùng để nhạp 2 số nguyên a và b.
    Rồi thông báo các giá trị của các phép cộng, trừ, nhân, chia của a và b.
*/

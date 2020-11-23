/*
	Chương trình này dùng để xem các giá trị của các phần tử trong biến mảng số nguyên a.
	Và đồng thời xem địa chỉ của phần tử trong biến mảng số nguyên a.
*/

#include <stdio.h>
#include <conio.h>

int main()
{
	// Khởi tạo bến mảng số nguyên a với số phần tử không biết trước mà theo dãy giá trị khởi tạo ban đầu
	int a[] = { 1, -2, 0, 4, -5, 3, 7 };
	// Biến số nguyên i dùng cho vòng lặp
	// Biến số nguyên n dùng để tính số phần tử trong biến mảng số nguyên a
	int i, n;
	// Để tính số phần tử của biến mảng số nguyên a thì ta lấy kích thước của biến a chia với kích thức của phần tử
	n = sizeof(a) / sizeof(int);
	// Hiện thị từng giá trị của biến mảng số nguyên a
	for (i = 0; i < n; i++)
		printf("%5d", a[i]);
	// Hiện thị từng địa chỉ của các phần tử của biến mảng số nguyên a bằng cách thêm '&' trước biến
	for (i = 0; i < n; i++)
		printf("\n%u", &a[i]);
	getch();
	return 0;
}

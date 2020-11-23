#include <stdio.h>
#include <conio.h>
int main()
{
	int a[5] = { 10, 20, 30, 40, 50 };
	// Biến mảng số nguyên a có 5 phần tử
	/*
		Cách khai báo biến mảng:
		<kiểu_dữ_liệu> <tên_biến>[số_phần_t];
		<kiểu_dữ_liệu> <tên_biến> = {dãy_giá_trị_của_cách_phần_tử};
	*/
	printf("\nXem cac phan tu cua mang:\n");
	printf("\n%5d", a[0]);
	printf("\n%5d", a[1]);
	printf("\n%5d", a[2]);
	printf("\n%5d", a[3]);
	printf("\n%5d", a[4]);
	/*
		Cách này không thuận tiện để hiển thị các phần tử của một mảng.
		Vì nó chỉ hiển thị duy nhất cho mảng có 5 phần tử.
		Đồng thời với n phần tử phải code n hàm printf cũng gây lãng phí thời gian
	*/
	printf("\n---------------------------\n");
	int n = sizeof(a) / sizeof(int);
	for (int i = 0; i < n; i++)
		printf("\n%5d", a[i]);
	//	Cách này hiểu qua hơn khi dùng vòng lặp để lặp lệnh thay vì code lặp đi lặp lại
	getch();
	return 0;
}


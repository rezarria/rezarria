#include <stdio.h>
#include <conio.h>
int main()
{
	int a[] = {1, -2, 0, 4, -5, 3, 7};
	/*
		biến a chính là biến mảng, có 7 phần tử
		Cú pháp
		<kiểu_biến> <tên_biến>[<số_phần_tử>];
	*/
	printf("\nXem cac phan tu cua mang:\n");
	printf("%5d", a[0]);
	printf("%5d", a[1]);
	printf("%5d", a[2]);
	printf("%5d", a[3]);
	printf("%5d", a[4]);
	/*
		Kiểu hiển thị này không phù hợp với mảng có nhiều phần tử
		Với kiểu này thì số phần tử sẽ bằng số lần nhập lại hàm printf, vậy rất mất thời gian và bất tiện
	*/
	printf("\n-------------------------------------\n");
	int i, n;
	n = sizeof(a) / sizeof(int);
	for (i = 0; i < n; i++)
		printf("%5d", a[i]);
	for (i = 0; i < n; i++)
		printf("\n%u", &a[i]);
	//Với vòng lặp for, ta chir cần khai báo printf một lần là đủ
	getch();
	return 0;
}

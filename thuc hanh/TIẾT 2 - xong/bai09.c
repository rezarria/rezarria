#include <stdio.h>
#include <conio.h>
int main()
{
	// Biến số nguyên n dùng để khởi tạo số hàng của mảng
	// Biến số nguyên m dùng để khởi tạo số cột của mảng
	int n, m;
	printf("Nhap n va m :");
	scanf("%d%d", &n, &m);
	// Khởi tạo biến mảng arr với số n hàng và m cột
	int arr[n][m];
	// Khởi tạo biến số nguyên t với giá trị khởi đầu là 0 để dùng tính tổng các giá trị nguyên dương có trong mảng
	int t = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			printf("Phan tu %3d cua hang %3d = ", j, i);
			scanf("%d", &arr[i][j]);
			if ((arr[i][j] % 2 == 0) && (arr[i][j] > 0))
				t += arr[i][j];
		}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%3d\t", arr[i][j]);
		putchar('\0');
	}
	printf("Tong duong chan trong mang la %5d\n", t);
	return 0;
}

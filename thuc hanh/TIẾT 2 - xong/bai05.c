#include <stdio.h>

int main()
{
	// Biến số nguyên n để nhập số phần tử của mảng
	int n;
	printf("Nhap n :");
	scanf("%d", &n);
	printf("Nhap mang:\n");
	// Tạo biến mảng số nguyên arr với n phần tử số nguyên
	int arr[n];
	// Vì trung bình cộng để chính xác giá trị thì nên dùng số thưc nên biến số thực s dùng để tính trung bình cộng của mảng arr
	// Giá trị khởi đầu phải bằng 0
	float s = 0;
	for (int i = 0; i < n; i++)
	{
		do
		{
			printf("\nphan tu thu %d :", i);
			scanf("%d", &arr[i]);
		} while (arr[i] > 0);
		// Sau khi nhập giá trị cho phần tử thì cũng cộng vào phần tử đố vào s luôn
		s += arr[i];
	}
	// Sau khi kết thúc việc nhập đồng thời là việc cộng vào s thì phải chia cho số phần tử để ra trung bình cộng
	s /= n;
	printf("TBC = %f", s);
	return 0;
}

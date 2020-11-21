#include <stdio.h>
int main()
{
	int n = -1;
	// Biến số nguyên n dùng để nhập các giá trị trong khoảng từ 1 đến 10
	int l = 1;
	//	Biến số nguyên l được sử dung để lưu giá trị tính giai thừa nên giá trị khởi đầu là 1
	while ((n < 0) || (n > 10))
	{
		printf("Nhap n : ");
		scanf("%d", &n);
	}

	int s = 0;
	// Biến số nguyên s được dùng là tổng nên giá trị ban đầu là 0
	int i = 0;
	// Biến số nguyên i dùng để lặp từ 1 đên n nên giá trị ban đầu sẽ là 0 để phù hợp với thuật toán lặp
	while (i != n)
	{
		i++;
		l *= i;
		s += l;
	}
	printf("S = %d\n", s);
	return 0;
}
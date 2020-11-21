#include <stdio.h>
int main()
{
	unsigned char a, b, c;
	a = 200;
	b = 60;
	c = a + b;
	printf("\nKet qua c = %d", c);
	/*
		c = 4
		vì kiểu unsigned char có khoảng giá trị từ 0 đến 255,
		nếu vượt quá 255 thì sẽ bắt đầu lại từ 0
		a + b = 200 + 60 = 260
		trừ đi giới hạn là 255 -> 260 - 255 = 5
		vì khoảng số bắt đầu từ 0 thay vì 1 nên c = 5 - 1 = 4		
	*/
	return 0;
}

#include <conio.h>
#include <stdio.h>
int main()
{
	int a[2][3] = { {1, 2, 3}, {4, 5, 6} };
	int i, j;
	printf("\nXem mang:\n");
	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			printf("%5d", a[i][j]);
	printf("\n");
	getch();
	return 0;
}
/*
	Khi xóa //1 và //2 thì tức xóa đia cặp dấu khối lệnh {}.
	nên lệnh printf("\n") để xuống dòng không còn thuộc vòng lặp nữa.
	Đồng nghĩa với việc lặp đi lặp lại thì không còn xuống dòng, các phần tử sẽ được in trên một dòng duy nhất
*/

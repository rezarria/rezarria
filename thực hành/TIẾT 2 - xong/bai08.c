#include <conio.h>
#include <stdio.h>
int main()
{
	int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
	int i, j;
	printf("\nXem mang:\n");
	for(i = 0; i < 2; i++)
	{ // 1
		for(j = 0; j < 3; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	} // 2
	getch();
	return 0;
}


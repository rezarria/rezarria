#include <stdio.h>
int main()
{
	int i, j;
	printf("Nhap hai so i, j : ");
	scanf("%d%d", &i, &j);
	printf("i > j : %d", i > j);
	printf("\ni < j : %d", i < j);
	printf("\ni >= j : %d", i >= j);
	printf("\ni <= j : %d", i <= j);
	printf("\ni == j : %d", i == j);
	printf("\ni != j : %d", i != j);
	return 0;
}

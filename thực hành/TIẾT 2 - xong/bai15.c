#include <stdio.h>
int main()
{
	int n, m, p;
	printf("Nhap n, m, p :");
	scanf("%d%d%d", &n, &m, &p);
	int a[n][m], b[m][p], c[n][p];
	printf("Nhap mang a %dx%d\n", n, m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			printf("Nhap phan tu [%3d,%3d] : ", i + 1, j + 1);
			scanf("%d", &a[i][j]);
		}
	printf("Nhap mang b %dx%d\n", m, p);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < p; j++)
		{
			printf("Nhap phan tu [%3d,%3d] : ", i + 1, j + 1);
			scanf("%d", &b[i][j]);
		}
	printf("-------------------------------\n");
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			printf("%5d  ", a[i][j]);
		printf("\n");
	}
	printf("-------------------------------\n");
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < p; j++)
			printf("%5d  ", b[i][j]);
		printf("\n");
	}
	printf("-------------------------------\n");
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < p; j++)
		{
			c[i][j] = 0;
			for(int n = 0; n < m; n++)
				c[i][j] += a[i][n] * b[n][j];
			printf("%5d  ", c[i][j]);
		}
		printf("\n");
	}	
	return 0;
}

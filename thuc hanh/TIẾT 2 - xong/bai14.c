#include <stdio.h>
int main()
{
	int n;
	printf("Nhap n : ");
	scanf("%d", &n);
	int arr[n][n];
	int t[n];
	for(int i = 0; i < n; i++)
	{
		t[i] = 0;
		printf("Nhap hang %d\n", i + 1);
		for(int j = 0; j < n; j++)
		{
			printf("Phan tu thu %d : ", j + 1);
			scanf("%d", &arr[i][j]);
			t[i] += arr[i][j];
		}
	}
	printf("\n");
	for(int i = 0; i < n; i++)
		printf("%d\n", t[i]);
	printf("--------------------------\n");
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%5d  ", arr[i][j]);
		printf("\n");
	}
	return 0;
}
	

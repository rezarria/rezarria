#include <stdio.h>
int main()
{
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int arr[2][n];
	for(char t = 0; t < 2; t++)
	{
		printf("Nhap mang %c :\n", 'a' + t);
		for(int i = 0; i < n; i++)
		{
			printf("Nhap phan tu %d : ", i);
			scanf("%d", &arr[t][i]);
		}
		for(int i = 0; i < n - 1; i++)
			for(int j = i + 1; j < n; j++)
			{
				arr[t][i] += arr[t][j];
				arr[t][j] = arr[t][i] - arr[t][j];
				arr[t][i] -= arr[t][j];
			}
	}
	char check = 0;
	for(int i = 0; i < n; i++)
		if(arr[0][i] != arr[1][i])
		{
			check++;
			break;
		}
	if(check)
		printf("\nHai mang khong tuong dong\n");
	else
		printf("\nHai mang tuong dong\n");
	return 0;
}

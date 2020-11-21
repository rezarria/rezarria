#include <stdio.h>
int main()
{
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	n++;
	int arr[n];
	printf("Nhap mang :\n");
	for(int i = 0; i < n; i++)
		if(i != n - 1)
		{
			printf("Nhap phan tu %d : ", i);
			scanf("%d", &arr[i]);
		}
		else
		{
			printf("Nap phan tu x : ");
			scanf("%d", &arr[i]);
		}
	printf("\nIn mang\n");
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
			if(arr[n] > arr[j])
			{
				arr[i] += arr[j];
				arr[j] = arr[i] - arr[j];
				arr[i] -= arr[j];
			}
		printf("%5d\t", arr[i]);
	}
	printf("%5d\n", arr[n - 1]);
	return 0;
}


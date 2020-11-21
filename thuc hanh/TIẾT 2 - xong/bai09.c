#include <stdio.h>
#include <conio.h>
int main()
{
	int n, m;
	printf("Nhap n va m :");
	scanf("%d%d", &a, &b);
	const int A = a, B = b;
	int arr[A][B];
	int t = 0;
	for(a = 0; a < A; a++)
		for(b = 0; b < B; b++)
		{
		printf("Phan tu %3d cua hang %3d = ", b, a);
		scanf("%d", &arr[a][b]);
		if((arr[a][b] % 2 == 0) && (arr[a][b] > 0))
			t += arr[a][b];
		}
	for(a = 0; a < A; a++)
	{
		for(b = 0; b < B; b++)
			printf("%3d\t");
		putchar('\0');
	}
	return 0;
}	

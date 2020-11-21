#include <stdio.h>
int main()
{
	int n;
	printf("Nhap n =");
	scanf("%d", &n);
	const int N = n;
	int a[N], b[N];
	int c = 0;
	for(n = 0; n < N; n++)
	{
		printf("a[%d] :");
		scanf("%d", &a[n]);
		if(0)
		{
			int i;
			for(i = 0; i < c; i++)
				if(b[i] == a[n])
					break;
			if(i != c)
				b[++c] = a[n];
		}
		else
		{
			b[0] = a[n];
			c++;
		}
	}
	printf("Mang a: ");
	for(n = 0; n < N; n++)
		printf("%5d ", a[n]);
	printf("\nMang b: ");
	for(n = 0; n < c; n++)
		printf("%d ", b[n]);
	return 0;
}

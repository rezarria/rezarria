#include <stdio.h>
int main()
{
	int s = 0;
	int n;
	printf("Nhap n : ");
	scanf("%d", &n);
	int i = 0;
	while (i < n)
	{
		i++;
		s += i * i;
	}
	printf("s = %d", s);
	return 0;
}

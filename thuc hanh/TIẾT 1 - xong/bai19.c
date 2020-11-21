#include <stdio.h>
int main()
{
	int n;
	printf("Nhap n : ");
	scanf("%d", &n);
	int s = 0;
	for (int i = n; i < 101; i++)
		s += i;
	printf("s = %d", s);
	return 0;
}

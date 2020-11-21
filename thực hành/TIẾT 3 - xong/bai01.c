#include <conio.h>
#include <stdio.h>
int tong(int n)
{
	int i, s = 0;
	for(i = 1; i <= n; i++)
	s += i;
	return s;
}
int main()
{
	int n;
	printf("\nNhap n = ");
	scanf("%d", &n);
	printf("\n%5d", tong(n));
	getch();
	return 0;
}

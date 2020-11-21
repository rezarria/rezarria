#include <stdio.h>

int nhapN();
int tongLe(int n);
void inTongLe(int n);

int main()
{
	inTongLe(tongLe(nhapN()));
	return 0;
}

//----------------------------

int nhapN()
{
	int n;
	printf("Nhap n : ");
	scanf("%d", &n);
	return n;
}

int tongLe(int n)
{
	int i, s = 0;
	for(i = 1; i <= n; i++)
		s += 2 * i;
	return s;
}

void inTongLe(int n)
{
	printf("T cua 1 + ... + (2*n + 1) = %d", n);
}

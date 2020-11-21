#include <stdio.h>

int nhapN();
int tongChia(int n);
void inTongChia(int n);

int main()
{
	inTongChia(tongChia(nhapN()));
	return 0;
}

//---------------------------------

int nhapN()
{
	int n;
	printf("Nhap n : ");
	scanf("%d", &n);
	return n;
}

int tongChia(int n)
{
	int i, s = 0;
	for(i = 1; i <= n; i++)
		s += 1.0 / i;
	return s;
}

void inTongChia(int n)
{
	printf("T cua 1 + ... +1/n = %d", n);
}

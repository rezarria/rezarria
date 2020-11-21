#include <stdio.h>

int nhapN();

int tongChia(int n);
void inTongChia(int n);

int tongLe(int n);
void inTongLe(int n);

int giaiThua(int n);
void inGiaiThua(int n);

int main()
{
	inTongLe(tongLe(nhapN()));
	inTongChia(tongChia(nhapN()));
	inGiaiThua(giaiThua(nhapN()));
	return 0;
}

//-----------------------------------

int nhapN()
{
	int n;
	printf("\nNhap n : ");
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
	printf("T cua 1 + ... + (2*n + 1) = %d\n", n);
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
	printf("T cua 1 + ... +1/n = %d\n", n);
}

int giaiThua(n)
{
	int r = 1;
	if (n != 1)
		r*=giaiThua(n - 1) * n;
	return r;
}

void inGiaiThua(int n)
{
	printf("Gia thua cua n = %d\n", n);
}
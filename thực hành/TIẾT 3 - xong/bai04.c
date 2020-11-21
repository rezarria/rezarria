#include <stdio.h>

int nhapN();
int giaiThua(n);
void inGiaiThua(int n);

int main()
{
	inGiaiThua(giaiThua(nhapN()));
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

int giaiThua(n)
{
	int r = 1;
	if (n != 1)
		r*=giaiThua(n - 1) * n;
	return r;
}

void inGiaiThua(int n)
{
	printf("Gia thua cua n = %d", n);
}
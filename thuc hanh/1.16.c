//205748010310003
//VÕ TÁ NAM
#include <stdio.h>


int uocChung(int a, int b);

int main()
{
	int a, b;
	printf("Nhap a : ");
	scanf("%d", &a);
	printf("Nhap b : ");
	scanf("%d", &b);
	printf("Uoc chung la %d\n", uocChung(a, b));
	return 0;
}

int uocChung(int a, int b)
{
	while( a!=b )
		if(a > b)
			a -= b;
		else
			b -= a;
	return a;
}

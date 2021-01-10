//205748010310003
//VÕ TÁ NAM
#include <stdio.h>

int S(int n);

int main()
{
	printf("Nhap n\t: ");
	int n;
	scanf("%d", &n);
	printf("s\t= %d\n", S(n));
	return 0;
}

int S(int n)
{
	int s = 0;
	int i = 0;
	while(i < n)
		s+= ++i * i;
	return s;
}

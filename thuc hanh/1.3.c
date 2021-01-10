//205748010310003
//VÕ TÁ NAM
#include <stdio.h>

float S(int n);

int main()
{
	printf("Nhap n\t: ");
	int n;
	scanf("%d", &n);
	printf("s\t= %3.2f\n", S(n));
	return 0;
}

float S(int n)
{
	float s = 0.0f;
	int i = 0;
	while(i < n)
		s+= 1.0f / ++i;
	return s;	
}

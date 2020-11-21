#include <stdio.h>
int main()
{
	float a;
	printf("Nhap a : ");
	scanf("%f", &a);
	int i = 0;
	do
	{
		i++;
		a -= 1.0 / i;
	}
	while (a > 0);
	printf("n = %d", i);
	return 0;
}

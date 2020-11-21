#include <stdio.h>
#include <cmath>
void ptb2(float a, float b, float c)
{
	float d = b * b - 4 * a * c;
	if (d)
		if (d > 0)
			printf("x1 = %5.3f\nx2 = %5.3f\n", (-b + sqrt(d)) / (2 * a), (-b - sqrt(d)) / (2 * a));
		else
			printf("x = %5.3f\n", b/(-2*a);
	else
		printf("Vo nghiem\n");
}
int main()
{
	int a, b, c;
	printf("Nhap a, b, c : ");
	scanf("%d%d%d", &a, &b, &c);
	ptb2(a, b, c);
	return 0;
}
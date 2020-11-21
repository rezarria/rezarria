#include <stdio.h>
#include <cmath>
int main()
{
	float a, b, c;
	printf("Nhap ba so : ");
	scanf("%f%f%f", &a, &b, &c);
	float d = b * b - 4 * a * c;
	if (d)
		if (d > 0)
		{
			float x1 = (-b - sqrt(d)) / (2 * a);
			float x2 = (-b + sqrt(d)) / (2 * a);
			printf("x1: %f\nx2: %f\n", x1, x2);
		}
		else
			printf("Khong nghiem\n");
	else
		printf("x: %f\n", (-b) / a);
	return 0;
}

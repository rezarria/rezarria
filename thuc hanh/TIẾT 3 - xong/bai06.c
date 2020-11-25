#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>


void ptb2(float a, float b, float c);

int main()
{
	int32_t a, b, c;
	printf("Nhap a, b, c : ");
	scanf("%d%d%d", &a, &b, &c);
	ptb2(a, b, c);
	return EXIT_SUCCESS;
}

void ptb2(float a, float b, float c)
{
	float d = b * b - 4.0f * a * c;
	if (d)
		if (d > 0.0f)
			printf("x1 = %5.3f\nx2 = %5.3f\n", (-b + sqrt(d)) / (2.0f * a), (-b - sqrt(d)) / (2.0f * a));
		else
			printf("x = %5.3f\n", b / (-2.0f * a));
	else
		printf("Vo nghiem\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void ptb1(float a, float b);

int main()
{
	int32_t a, b;
	printf("Nhap a, b : ");
	scanf("%d%d", &a, &b);
	ptb1(a, b);
	return EXIT_SUCCESS;
}

void ptb1(float a, float b)
{
	if (a == 0.0f)
		if (b == 0.0f)
			printf("Vo so nhiem\n");
		else
			printf("Vo nghiem\n");
	else
		printf("Nghiem cua pt la %5:3f\n", -b / a);
}
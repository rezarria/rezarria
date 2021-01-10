//205748010310003
//VÕ TÁ NAM
#include <stdio.h>

void giaiPt1(float a, float b);

int main()
{
	float a, b;
	printf("Nhap a : ");
	scanf("%f", &a);
	printf("Nhap b : ");
	scanf("%f", &b);
	giaiPt1(a, b);
}

void giaiPt1(float a, float b)
{
	if(a)
	{
		printf("phuong trinh co 1 nghiem\n");
		printf("x = %-6.2f\n", -1.0f*b/a);
	}
	else
		if(b)
			printf("phuong trinh vo nghiem vi a bang 0 va b khac\n");
		else
			printf("phuong trinh vo so nghiem vi a va b deu bang 0\n");
}

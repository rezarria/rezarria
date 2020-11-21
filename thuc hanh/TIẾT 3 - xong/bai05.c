#include <stdio.h>
void ptb1(float a, float b)
{
	if (a == 0)
		if (b == 0)
			printf("Vo so nhiem\n");
		else
			printf("Vo nghiem\n");
	else
		printf("Nghiem cua pt la %5:3f\n", float(-b) / a);
}
int main()
{
	int a, b;
	printf("Nhap a, b : ");
	scanf("%d%d", &a, &b);
	ptb1(a, b);
	return 0;
}
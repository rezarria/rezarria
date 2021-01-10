//205748010310003
//VÕ TÁ NAM
#include <stdio.h>
#include <math.h>

void nhapFloat(float *n, char *ten);
void giaiPt2(float a, float b, float c);

int main()
{
	float a, b, c;
	nhapFloat(&a, "a");
	nhapFloat(&b, "b");
	nhapFloat(&c, "c");
	giaiPt2(a, b, c);
	return 0;
}

void nhapFloat(float *n, char *ten)
{
	printf("Nhap vao %s\t: ");
	scanf("%f", n);
}

void giaiPt2(float a, float b, float c)
{
	if(a)
	{
		float delta = b*b - 4.0f * a * c;
		if(delta  > 0)
		{
			if(delta)
			{
				float x[] = {-(b + sqrt(delta))/(2.0f * a), -(b - sqrt(delta))/(2.0f * a)};
				printf("Co 2 nghiem.\n");
				int i = 0;
				for(; i < 2; i++)
					printf("x[%d]\t = %6.2f\n", i, x[i]);
			}
			else
			{
				printf("Co 1 nghiem.\n");
				printf("Nghiem cua phuong trinh la %6.2f\n", -b/(2.0f * a));
			}
		}
		else
			printf("Delta be hon 0 nen phuong trinh vo nhiem\n");
	}
	else
		printf("Vi a bang 0 nen vo nhiem");
}

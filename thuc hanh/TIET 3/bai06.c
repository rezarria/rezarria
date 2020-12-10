#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

int32_t importI32();
int32_t importI32_f(FILE* in);
void xQuadratic(float a, float b, float c);
void xQuadratic_f(float a, float b, float c, FILE* out);

int main()
{
	FILE* file = fopen("bai06.inp", "r");
	int32_t a = importI32_f(file);
	int32_t b = importI32_f(file);
	int32_t c = importI32_f(file);
	fclose(file);
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);
	file = fopen("bai06.out", "w");
	xQuadratic_f(a, b, c, file);
	fclose(file);
	return EXIT_SUCCESS;
}

int32_t importI32_f(FILE* in)
{
	int32_t n;
	if (in == stdin)
		printf("int32> ");
	fscanf(in, "%d", &n);
	return n;
}

int32_t importI32()
{
	return importI32_f(stdin);
}

void xQuadratic(float a, float b, float c)
{
	xQuadratic_f(a, b, c, stdout);
}

void xQuadratic_f(float a, float b, float c, FILE* out)
{
	if (a == 0.0f)
	{
		fprintf(out, "Day la phuong trinh bac nhat mot an\n");
		if (out != stdout)
			printf("Day la phuong trinh bac nhat mot an\n");
	}
	else
	{
		float d = b * b - 4.0f * a * c;
		if (d)
			if (d > 0.0f)
			{
				float x1 = (-b + sqrt(d)) / (2.0f * a);
				float x2 = (-b - sqrt(d)) / (2.0f * a);
				fprintf(out, "x1 = %5.3f\nx2 = %5.3f\n", x1, x2);
				if (out != stdout)
					printf("x1 = %5.3f\nx2 = %5.3f\n", x1, x2);
			}
			else
			{
				fprintf(out, "Vo nghiem\n");
				if (out != stdout)
					printf("Vo nghiem\n");

			}
		else
		{
			float x = b / (-2.0f * a);
			fprintf(out, "x = %5.3f\n", x);
			if (out != stdout)
				printf("x = %5.3f\n", x);
		}
	}

}
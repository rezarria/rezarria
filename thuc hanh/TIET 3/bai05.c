#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t importI32();
int32_t importI32_f(FILE* in);
void xLinear(float a, float b);
void xLinear_f(float a, float b, FILE* out);

int main()
{
	FILE* file = fopen("bai05.inp", "r");
	int32_t a = importI32(file), b = importI32(file);
	fclose(file);
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	file = fopen("bai05.out", "w");
	xLinear_f(a, b, file);
	fcose(file);
	return EXIT_SUCCESS;
}

void xLinear(float a, float b)
{
	xLinear_f(a, b, stdout);
}

void xLinear_f(float a, float b, FILE* out)
{
	if (a == 0.0f)
		if (b == 0.0f)
		{
			fprintf(out, "Vo so nhiem\n");
			if (out != stdout)
				printf("Vo so nhiem\n");
		}
		else
		{
			fprintf(out, "Vo nghiem\n");
			if (out != stdout)
				printf("Vo nghiem\n");
		}
	else
	{
		float n = -b / a;
		fprintf(out, "Nghiem cua pt la %5:3f\n", n);
		if (out != stdout)
			printf("Nghiem cua pt la %5:3f\n", n);
	}
}

int32_t importN()
{
	return importN(stdin);
}


int32_t importI32_f(FILE* in)
{
	int32_t n;
	if (in == stdin)
		printf("int32> ");
	fscanf(in, "%d", &n);
	return n;
}
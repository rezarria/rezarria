#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t importUI32();
uint32_t importUI32_f(FILE* in);
uint32_t Factorial(uint32_t n);
void printFactorial(uint32_t n);
void printFactorial_f(uint32_t n, FILE* out);

int main()
{
	FILE * file = fopen("bai04.inp", "r");
	uint32_t n = importUI32_f(file);
	printf("N = %u\n", n);
	fclose(file);
	n = Factorial(n);
	file = fopen("bai04.out", "w");
	printFactorial_f(n, file);
	fclose(file);
	printFactorial(n);
	return EXIT_SUCCESS;
}

uint32_t importUI32()
{
	return importUI32(stdin);
}

uint32_t importUI32_f(FILE* in)
{
	int32_t n;
	if (in == stdin)
		printf("uint32> ");
	fscanf(in, "%u", &n);
	return n;
}

uint32_t Factorial(uint32_t n)
{
	int32_t r = 1;
	if (n != 1)
		r *= Factorial(n - 1) * n;
	return r;
}

void printFactorial(uint32_t n)
{
	printf("Gia thua cua n = %3d\n", n);
}

void printFactorial_f(uint32_t n, FILE* out)
{
	fprintf(out, "%u", n);
}

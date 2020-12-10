#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint64_t	importUi64();
uint64_t	importUI64_f(FILE* in);
float		calcSumOfDivine(uint64_t n);
void		displaySumOfDivine(float n);
uint64_t	calcSumOfOdd(uint64_t n);
void		displaySumOfOdd(uint64_t n);
uint64_t	calcFactorial(uint64_t n);
void		displayFactorial(uint64_t n);
uint64_t	fwriteUI64(FILE* out, uint64_t n);
float		fwriteFloat(FILE* out, float n);

int32_t main()
{
	FILE* in = fopen("bai09.inp", "r");
	FILE* out = fopen("bai09.out", "w");
	float sumOfDivine = calcSumOfDivine(importUI64_f(in));
	uint64_t sumOfOdd = calcSumOfOdd(importUI64_f(in));
	uint64_t factorial = calcFactorial(importUI64_f(in));
	displaySumOfDivine(fwriteFloat(out, sumOfDivine));
	displaySumOfOdd(fwriteUI64(out, sumOfOdd));
	displayFactorial(fwriteUI64(out, factorial));
	fclose(in);
	fclose(out);
	return EXIT_SUCCESS;
}

uint64_t fwriteUI64(FILE* out, uint64_t n)
{
	fprintf(out, "%llu", n);
	return n;
}

float fwriteFloat(FILE* out, float n)
{
	fprintf(out, "%f", n);
	return n;
}

uint64_t importUI64()
{
	return importUI64_f(stdin);
}

uint64_t importUI64_f(FILE* in)
{
	int64_t n;
	if (in == stdin)
		printf("uint64> ");
	fscanf(in, "%llu", &n);
	return n;
}

uint64_t calcSumOfOdd(uint64_t n)
{
	uint64_t s = 0llu;
	for (uint64_t i = 1; i <= n; i++)
		s += 2 * i;
	return s;
}

float calcSumOfDivine(uint64_t n)
{
	float s = 0.0f;
	for (uint64_t i = 1llu; i <= n; i++)
		s += 1.0f / i;
	return s;
}

uint64_t calcFactorial(uint64_t n)
{
	uint64_t r = 1llu;
	if (n != 1llu)
		r *= calcFactorial(n - 1llu) * n;
	return r;
}

void displaySumOfOdd(uint64_t n)
{
	printf("T cua 1 + ... + (2*n + 1) = %4llu\n", n);
}

void displaySumOfDivine(float n)
{
	printf("T cua 1 + ... +1/n = %3.2f\n", n);
}

void displayFactorial(uint64_t n)
{
	printf("Gia thua cua n = %d\n", n);
}
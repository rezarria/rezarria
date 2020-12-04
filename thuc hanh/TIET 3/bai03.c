#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t importN();
float tongChia(int32_t n);
void displaySumOfDivine(float n);

int main()
{
	displaySumOfDivine(tongChia(importN()));
	return EXIT_SUCCESS;
}

//---------------------------------

int32_t importN()
{
	int32_t n;
	printf("Nhap n : ");
	scanf("%d", &n);
	return n;
}

float tongChia(int32_t n)
{
	float s = 1.0f;
	n++;
	for (int32_t i = 2; i < n; i++)
		s += 1.0f / i;
	return s;
}

void displaySumOfDivine(float n)
{
	printf("T cua 1 + ... +1/n = %d", n);
}

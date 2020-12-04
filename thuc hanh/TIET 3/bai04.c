#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t importN();
uint32_t giaiThua(uint32_t n);
void inGiaiThua(uint32_t n);

int main()
{
	inGiaiThua(giaiThua(importN()));
	return EXIT_SUCCESS;
}

uint32_t importN()
{
	int32_t n;
	printf("Nhap n : ");
	scanf("%d", &n);
	return n;
}

uint32_t giaiThua(uint32_t n)
{
	int32_t r = 1;
	if (n != 1)
		r *= giaiThua(n - 1) * n;
	return r;
}

void inGiaiThua(uint32_t n)
{
	printf("Gia thua cua n = %3d\n", n);
}
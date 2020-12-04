#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint64_t importN();

float tongChia(uint64_t n);
void inTongChia(float n);

uint64_t tongLe(uint64_t n);
void inTongLe(uint64_t n);

uint64_t giaiThua(uint64_t n);
void inGiaiThua(uint64_t n);

int32_t main()
{
	inTongLe(tongLe(importN()));
	inTongChia(tongChia(importN()));
	inGiaiThua(giaiThua(importN()));
	return EXIT_SUCCESS;
}


uint64_t importN()
{
	uint64_t n;
	printf("\nNhap n : ");
	scanf("%llu", &n);
	return n;
}

uint64_t tongLe(uint64_t n)
{
	uint64_t s = 0llu;
	for (uint64_t i = 1; i <= n; i++)
		s += 2 * i;
	return s;
}

void inTongLe(uint64_t n)
{
	printf("T cua 1 + ... + (2*n + 1) = %4llu\n", n);
}

float tongChia(uint64_t n)
{
	float s = 0;
	for (uint64_t i = 1; i <= n; i++)
		s += 1.0f / i;
	return s;
}

void inTongChia(float n)
{
	printf("T cua 1 + ... +1/n = %3.2f\n", n);
}

uint64_t giaiThua(uint64_t n)
{
	uint64_t r = 1llu;
	if (n != 1llu)
		r *= giaiThua(n - 1llu) * n;
	return r;
}

void inGiaiThua(uint64_t n)
{
	printf("Gia thua cua n = %d\n", n);
}
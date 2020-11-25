#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void nhapNMP(uint64_t* n, uint64_t* m, uint64_t* p);
int32_t** createIn32Arr(uint64_t n, uint64_t m);
void importArr(int32_t** arr, uint64_t n, uint64_t m);
void displayArr(int32_t** arr, uint64_t n, uint64_t m);
int32_t** addTwoArr(int32_t** arr1, int32_t** arr2, uint64_t n, uint64_t m, uint64_t p);

int main()
{
	uint64_t n, m, p;

	nhapNMP(&n, &m, &p);

	int32_t** a = createIn32Arr(n, m);
	int32_t** b = createIn32Arr(m, p);

	printf("Nhap mang a %dx%d\n", n, m);
	importArr(a, n, m);

	printf("Nhap mang b %dx%d\n", m, p);
	importArr(b, m, p);

	printf("-------------------------------\n");
	displayArr(a, n, m);

	printf("-------------------------------\n");
	displayArr(b, m, p);

	int32_t** c = addTwoArr(a, b, n, m, p);
	printf("-------------------------------\n");
	displayArr(c, n, p);

	return EXIT_SUCCESS;
}

void nhapNMP(uint64_t* n, uint64_t* m, uint64_t* p)
{
	printf("Nhap n: ");
	scanf("%llu", n);
	printf("Nhap m: ");
	scanf("%llu", m);
	printf("Nhap p: ");
	scanf("%llu", p);
}

int32_t** createIn32Arr(uint64_t n, uint64_t m)
{
	int32_t** tmp = (int32_t**)calloc(n, sizeof(int32_t*));
	for (uint64_t i = 0llu; i < n; i++)
		tmp[i] = (int32_t*)calloc(m, 4llu);
	return tmp;
}

void importArr(int32_t** arr, uint64_t n, uint64_t m)
{
	for (uint64_t i = 0llu; i < n; i++)
		for (uint64_t j = 0llu; j < m; j++)
		{
			printf("Nhap phan tu [%3llu,%3llu] : ", i + 1llu, j + 1llu);
			scanf("%d", &arr[i][j]);
		}
}

void displayArr(int32_t** arr, uint64_t n, uint64_t m)
{
	for (uint64_t i = 0llu; i < n; i++)
	{
		for (uint64_t j = 0llu; j < m; j++)
			printf("%5d  ", arr[i][j]);
		putchar('\n');
	}
}

int32_t** addTwoArr(int32_t** arr1, int32_t** arr2, uint64_t n, uint64_t m, uint64_t p)
{
	int32_t** arr3 = createIn32Arr(n, p);
	for (uint64_t i = 0llu; i < n; i++)
		for (uint64_t j = 0llu; j < p; j++)
			for (uint64_t _m = 0llu; _m < m; _m++)
				arr3[i][j] += arr1[i][_m] * arr2[_m][j];
	return arr3;
}
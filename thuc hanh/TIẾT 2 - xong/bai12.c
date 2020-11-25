#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b);
void displayArr(int* arr, unsigned int n);
void importArr(int* arr, unsigned int n);
void check(int* a, int* b, unsigned int n);

int main()
{
	unsigned int n;
	printf("Nhap so n : ");
	scanf("%u", &n);

	int* a = (int*)calloc(n + 1llu, 4llu);
	int* b = (int*)calloc(n + 1llu, 4llu);

	printf("\nNhap mang a\n");
	importArr(a, n);
	printf("\nNhap mang b\n");
	importArr(b, n);

	qsort(a, n, sizeof(int), cmp);
	qsort(b, n, sizeof(int), cmp);

	printf("\nSap xep lai...\n");

	displayArr(a, n);
	displayArr(b, n);
	check(a, b, n);

	return EXIT_SUCCESS;
}

void importArr(int* arr, unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		printf("Nhap phan tu %5u\t:\t", i);
		scanf("%d", &arr[i]);
	}
}

void displayArr(int* arr, unsigned int n)
{
	printf("\n----------------------\n");
	for (unsigned int i = 0; i < n; i++)
		printf("phan tu %2u\t:\t%4d\n", i, arr[i]);
}

void check(int* a, int* b, unsigned int n)
{
	unsigned int count = 0;
	for (unsigned int i = 0u; i < n; i++)
		if (a[i] != b[i])
		{
			count++;
			break;
		}
	if (count)
		printf("Hai mang khac nhau\n");
	else
		printf("Khac nhau ve trat tu\n");
}

int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
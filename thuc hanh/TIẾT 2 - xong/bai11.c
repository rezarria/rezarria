#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b);
void displayArr(int* arr, unsigned int n);
void importArr(int* arr, unsigned int n);

int main()
{
	unsigned int n;
	printf("Nhap so n : ");
	scanf("%u", &n);

	int* arr = (int*)calloc(n + 1llu, 4llu);

	importArr(arr, n);

	qsort(arr, n, 4, cmp);
	displayArr(arr, n);

	printf("Nhap phan tu x\t:\t");
	scanf("%d", &arr[n]);

	n++;
	qsort(arr, n, 4llu, &cmp);
	displayArr(arr, n);

	return EXIT_SUCCESS;
}

void importArr(int* arr, unsigned int n)
{
	printf("Nhap mang\n");
	for (unsigned int i = 0; i < n; i++)
	{
		printf("Nhap phan tu %5d\t:\t", i);
		scanf("%d", &arr[i]);
	}
}

void displayArr(int* arr, unsigned int n)
{
	printf("\n----------------------\n");
	for (unsigned int i = 0; i < n; i++)
		printf("phan tu %2u\t:\t%4d\n", i, arr[i]);
}

int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
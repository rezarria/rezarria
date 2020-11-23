#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void sort(uint32_t* i, uint64_t n);

int main()
{
	uint64_t n;
	printf("Nhap n : ");
	scanf("%llu", &n);

	int32_t arr[n + 1llu];

	for (uint64_t i = 0llu; i < n; i++)
	{
		printf("Nhap phan tu %llu\t:\t", i);
		scanf("%d", &arr[i]);
	}

	sort(arr, n);


	for (uint64_t i = 0llu; i < n; i++)
		printf("%5d", arr[i]);


	printf("\nNhap phan tu x\t:\t");
	scanf("%d", &arr[n]);
	n++;




	if (!(arr[n - 2llu] < arr[n - 1llu]))
		if (arr[0] > arr[n - 1llu])
			for (uint64_t i = n - 1; i > 0llu; i--)
			{
				arr[i] = arr[i] ^ arr[i - 1llu];
				arr[i - 1llu] = arr[i] ^ arr[i - 1llu];
				arr[i] = arr[i] ^ arr[i - 1llu];
			}
		else
			sort(arr, n);

	for (uint64_t i = 0llu; i < n; i++)
		printf("%5d", arr[i]);

	return EXIT_SUCCESS;

}

void sort(uint32_t* arr, uint64_t n)
{
	for (uint64_t i = 0; i < n - 1llu; i++)
		for (uint64_t j = i + 1llu; j < n; j++)
			if (arr[i] > arr[j])
			{
				arr[i] = arr[i] ^ arr[j];
				arr[j] = arr[i] ^ arr[j];
				arr[i] = arr[i] ^ arr[j];

			}
}
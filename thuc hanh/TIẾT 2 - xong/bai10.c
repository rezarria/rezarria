#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
	uint64_t n;
	printf("Nhap so n : ");
	scanf("%llu", &n);

	int32_t a[n];
	int32_t b[n + 1llu];

	// biến b có n + 1 phần tử vì phần tử thứ 0 được dùng làm để đếm số n phần tử còn lại
	for (uint64_t i = 0llu; i < n; i++)
	{
		printf("Nhap vao phan tu [%llu]\t:\t", i);
		scanf("%d", &a[i]);
	}

	for (uint64_t i = 0llu; i < n - 1llu; i++)
		for (uint64_t j = i + 1llu; j < n; j++)
			if (a[i] > a[j])
			{
				a[i] = a[i] ^ a[j];
				a[j] = a[i] ^ a[j];
				a[i] = a[i] ^ a[j];
			}

	b[0] = 1;
	b[1] = a[0];

	for (uint32_t i = 1llu; i < n; i++)
		if (a[i] != b[b[0]])
		{
			b[0]++;
			b[b[0]] = a[i];
		}

	b[0]++;

	printf("Mang a\n");
	for (uint32_t i = 1llu; i < n; i++)
		printf("%d\t", a[i]);

	printf("\nMang b\n");
	for (uint32_t i = 1llu; i < b[0]; i++)
		printf("%d\t", b[i]);

	return 0;
}
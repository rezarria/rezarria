//205748010310003
//VÕ TÁ NAM
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void* a, void* b, size_t size);

int main()
{
	int a, b;
	printf("Nhap a: ");
	scanf("%d", &a);
	printf("Nhap b: ");
	scanf("%d", &b);
	printf("a : %d\nb : %d\n", a, b);
	swap((void*)&a, (void*)&b, sizeof(a));
	printf("Da chuyen!\n");
	printf("a : %d\nb : %d\n", a, b);
	return 0;
}

void swap(void *a, void *b, size_t size)
{
	void * c = malloc(size);
	memcpy(c, a, size);
	memcpy(a, b, size);
	memcpy(b, c, size);
}

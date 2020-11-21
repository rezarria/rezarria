#include <stdio.h>
int main()
{
	int n;
	printf("Nhap n :");
	scanf("%d", &n);
	printf("Nhap mang:\n");
	const int N = n;
	int mang[N];
	float s = 0;
	for(int i = 0; i < n; i++)
	{
		printf("\nphan tu thu %d :", i);
		scanf("%d", &mang[i]);
		s += mang[i];
	}
	s /= n;
	printf("TBC = %f", s);
	return 0;
}

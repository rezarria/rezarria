//205748010310003
//VÕ TÁ NAM
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

unsigned int giaiThua(unsigned int n);
void nhapUI32(unsigned int *n);

int main()
{
	unsigned int n;
	nhapUI32(&n);
	printf("Giai thua cua %u la %u\n", n, giaiThua(n));
	return 0;
}

unsigned int giaiThua(unsigned int n)
{
	return ( n < 2u ) ? 1u : n * giaiThua( n - 1u );
}

void nhapUI32(unsigned int *n)
{
	bool run = true;
	while(run)
	{
		printf("Nhap so nguyen khong am : ");
		scanf("%u", n);
		if(strchr(stdin->_base, (int)'-'))
		{
			printf("So nhap vao la so am!\nHay nhap lai\n");
		}
		else
			run = false;

	}

}

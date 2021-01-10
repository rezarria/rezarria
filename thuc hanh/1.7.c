//205748010310003
//VÕ TÁ NAM
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n);

int main()
{
	printf("Nhap n\t: ");
	int n;
	scanf("%d", &n);
	printf("%d %s nguyen to\n", n, isPrime(n)?"la":"khong phai la");
	return 0;
}

bool isPrime(int n)
{
	bool kq = true;
	if(n > 0)
	{
		if(n > 3)
		{
			if(n % 2)
			{
				int i = sqrt(n);
				for(; i > 2; i--)
					if(n % i == 0)
					{
						kq = false;
						break;
					}
			}
			else
				kq = false;
		}
	}
	else
		kq = false;
	return kq;
}

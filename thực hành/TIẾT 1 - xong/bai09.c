#include <stdio.h>

int main()
{
	int n = 0;
	while ((n < 1) || (n > 9))
	{
		printf("Nhap n: ");
		scanf("%d", &n);
	}
	switch (n) //switch theo giá trị của n
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 9:
		// Khi n = 1, 3, 5, 7, 9  thì
		printf("\nLa so le");
		break;
	case 2:
	case 4:
	case 6:
	case 8:
		// Khi n = 2, 4, 6, 8 thì
		printf("\nLa so chan");
		break;
	};
	return 0;
}

//205748010310003
//VÕ TÁ NAM
#include <stdio.h>

int soChu(char * str);

int main()
{
	char str[256];
	printf("Nhap xau : ");
	gets(str);
	printf("So chu so xuat hien trong xau : %d\n", soChu(str));
	return 0;
}

int soChu(char* str)
{
	int count = 0;
	do
		if(*str >= '0' &&  *str <= '9')
			count++;
	while(*(str++));
	return count;
}

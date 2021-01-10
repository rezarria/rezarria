//205748010310003
//VÕ TÁ NAM
#include <stdio.h>

int soCach(char* str);

int main()
{
	char str[256];
	printf("Nhap xau\t: ");
	gets(str);
	printf("So dau cach trong xau la %d\n", soCach(str));
	return 0;
}

int soCach(char *str)
{
	int count = 0;
	do
		if(*str == ' ')
			count++;
	while(*(str++));
	return count;
}

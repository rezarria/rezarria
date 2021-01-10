//205748010310003
//VÕ TÁ NAM
#include <stdio.h>

void inHoa(char* str);

int main()
{
	char str[256];
	printf("Nhap xau : ");
	gets(str);
	inHoa(str);
	printf("--------------\n%s\n", str);
	return 0;
}

void inHoa(char* str)
{
	do
		if(*str >= 'a' && *str <= 'z')
			(*str) -= 32;
	while(*(str++));
}

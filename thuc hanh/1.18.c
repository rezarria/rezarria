//205748010310003
//VÕ TÁ NAM
#include <stdio.h>

int demChuHoa(char *str);

int main()
{
	char str[256];
	printf("Nhap xau : ");
	gets(str);
	printf("So chu in hoa trong xau la %d\n", demChuHoa(str));
	return 0;
}

int demChuHoa(char* str)
{
	int count;
	do
		if(*str >= 'A' && *str <= 'Z')
			count++;
	while(*(str++));
	return count;
}

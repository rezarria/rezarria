//205748010310003
//VÕ TÁ NAM
#include <stdio.h>
#include <stdbool.h>

int soTieng(char * str);

int main()
{
	char str[256];
	printf("Nhap xau : ");
	gets(str);
	printf("So tieng trong xau la %d\n", soTieng(str));
	return 0;
}

int soTieng(char * str)
{
	int count = 0;
	bool text = false;
	do
		switch(*str)
		{
			case ' ': case '\0' : case '\n' :
				if(text)
				{
					text = false;
					count++;

				}
				break;
			default:
				if(!text)
					text = true;
		}
	while(*(str++));
	return count;
}

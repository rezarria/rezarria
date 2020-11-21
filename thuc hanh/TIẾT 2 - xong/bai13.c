#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
	char s[256];
	unsigned int *arr = (unsigned int*)calloc(26, sizeof(unsigned int));
	unsigned int i = 0;
	unsigned int c = 0;
	printf("Nhap xau:\n");
	gets(s);
	while(s[i] != '\0')
	{
		arr[toupper(s[i]) - 65]++;
		i++;
	}
	printf("-------------------------------------\n");
	for(i = 0; i < 26; i++)
		if(arr[i])
		{
			if(c == 5)
			{
				printf("\n");
				c = 0;
			}
			printf("%5d ky tu '%c'\t", arr[i], i + 'A');
			c++;
		}
	return 0;
}

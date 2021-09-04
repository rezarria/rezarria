#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char **argv)
{
	if(argc == 2)
	{
		int i = 0;
		for(; argv[1][i] && isdigit(argv[1][i]); ++i);
		if(!argv[1][i])
		{
			const unsigned int k = atoi(argv[1]) - 65;
            		char str[255];
			printf("plaintext:  ");
			fgets(str, 255, stdin);
            		printf("ciphertext: ");
			for(i = 0; str[i] ; ++i)
				putchar(isalpha(str[i])
					?(((str[i]<'a')?'A':'a')+(toupper(str[i])+k)%26)
					:str[i]
				       );
			return 0;
		}
	}
	printf("Usage: %s key\n", argv[0]);
	return 0;
}

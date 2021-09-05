#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int k, string kv[]) //int or string kv
{

	if (k == 1 || k > 2) // có thể thay bằng k != 2
	{
		printf("Usage: ./caesar key(1)\n");
		return 1;
	}

	for (int i = 0, str = strlen(kv[1]); i < str; i++)
	{
		if (!isdigit(kv[1][i]))
		{
			printf("Usage: ./caesar key(2)\n");
			return 1;
		}
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	int argv = atoi(kv[1]);

	int ascii[26];

	for (int i = 0; i < 26; i++) // ci = (pi + k) % 26 , from CS50
	{
		// 'A' + 0 = 'A'; trong c kí tự có thể chuyển đổi thành giá trị số luôn
		// 'A' + 25 = 'Z';
		ascii[i] = 'A' + i;
	}

	string plaintext = get_string("plaintext:");

	printf("%s\n", plaintext);

	for (int i = 0, n = strlen(plaintext); i < n; i++)
	{
		if (isalpha(plaintext[i])) // Trừ dấu ra
		{
			if (islower(plaintext[i]))
			{
				plaintext[i] = plaintext[i] - 'a';
				plaintext[i] = ascii[(plaintext[i] + argv) % 26];
				plaintext[i] = plaintext[i] + 32; // Chữ Hoa -> chữ thường, có thể thay bằng plaintext[i] += 32;
			}
			else
			{
				plaintext[i] = plaintext[i] - 'A';
				plaintext[i] = ascii[(plaintext[i] + argv) % 26];
				//plaintext[i] = plaintext[i] + '65'; // Vốn là chữ Hoa, không cần lên
			}
		}
		printf("%c", plaintext[i]);
	}
	return 0;
}

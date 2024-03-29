#include <iostream>

size_t miniumBracketAdd(char* str)
{
	size_t count = 0;
	for(;*str;str++)
		if(str[0] == '{' && str[1] == '}')
			str++;
		else
			count++;
	return count;
}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		std::cout << miniumBracketAdd(argv[1]) << std::endl;
		return 0;
	}
	return 1;
}

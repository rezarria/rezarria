#include <iostream>

size_t miniumBracketAdd(char* str)
{
	if(!str[0])
		return 0;

	if(str[0] == '{' && str[1] =='}')
		return 0 +  miniumBracketAdd(str + 2);
	else
		return 1 + miniumBracketAdd(str + 1);
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

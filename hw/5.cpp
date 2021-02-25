#include <iostream>
#include <string>

bool isSymmetrical(std::string &str)
{
    std::string::iterator b = str.begin();
    std::string::iterator e = str.end();
    for (e--;
         b < e;
         b++, e--)
        if (*b != *e)
            return false;
    return true;
}

int main()
{
    std::cout << "str : ";
    std::string str;
    std::getline(std::cin, str);
    if (isSymmetrical(str))
        std::cout << "str is symmetrical";
    else
        std::cout << "str isn't symmetrical";
    std::cout << std::endl;
    return 0;
}
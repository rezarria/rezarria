#include <iostream>

int reverse(int n)
{
    int result = 0;
    while (n)
    {
        result *= 10;
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main()
{
    int n;
    std::cout << "n : ";
    std::cin >> n;
    std::cout << "> " << reverse(n) << std::endl;
    return 0;
}

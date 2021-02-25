#include <iostream>

bool isOdd(int n) { return n % 2; }

int main()
{
    std::cout << "Nhap n : ";
    int n;
    std::cin >> n;
    if (isOdd(n))
        std::cout << "La so le";
    else
        std::cout << "La so chan";
    std::cout << std::endl;
    return 0;
}
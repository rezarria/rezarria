#include <iostream>

int sumN(int n) { return n * (n + 1) / 2; }

int main()
{
    std::cout << "Nhap n : ";
    int n;
    std::cin >> n;
    std::cout << "Tong n so = " << sumN(n) << std::endl;
    return 0;
}
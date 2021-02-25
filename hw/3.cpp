#include <iostream>
#include <algorithm>

int *nhapMang(int n)
{
    int *rb = new int[n];
    for (int i = 0ull; i < n; i++)
    {
        std::cout << "[" << i << "]"
                  << " = ";
        std::cin >> rb[i];
    }
    return rb;
}

int main()
{
    int n;
    std::cout << "Nhap n : ";
    std::cin >> n;
    int *arr = nhapMang(n);
    std::cout << "Phan tu be nhat trong mang la : " << *std::min_element(arr, arr + n) << std::endl;
    return 0;
}
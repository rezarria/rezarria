#include<iostream>
#include<cstdint>

int32_t main()
{
    uint32_t a[32];
    for (uint32_t i = 0; i < 32; i++)
    {
        a[i] = 1 << i;
        std::cout << a[i] << std::endl;
    }


    uint32_t c = a[2] | a[3];

    std::cout << (c | 2) << std::endl;

    for (int i = 0; i < 11; i++);
    return EXIT_SUCCESS;
}
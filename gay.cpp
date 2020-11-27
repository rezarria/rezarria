#include <iostream>
#include <cstdint>

uint64_t func(uint64_t x, uint64_t y)
{
    uint64_t result = 0llu;
    switch (x)
    {
    case 0llu:
    {
        switch (y)
        {
        case 0llu:
            result = 0llu;
            break;
        case 1llu:
            result = 1llu;
            break;
        default:
            result = func(0llu, y - 1llu) + func(0llu, y - 2llu);
            break;
        }
    }
    break;
    case 1:
        if (y)
            result = func(x - 1llu, y) + func(x, y - 1llu);
        else
            result = 1llu;
        break;
    default:
        if (y)
            result = func(x, y - 1llu) + func(x - 1llu, y);
        else
            result = func(x - 1llu, 0llu) + func(x - 2llu, 0llu);
        break;
    }
    return result;
}

int main()
{
    uint64_t x, y;
    std::cin >> x >> y;
    std::cout << func(x, y) << std::endl;
    return 0;
}
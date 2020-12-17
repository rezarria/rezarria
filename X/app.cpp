#include "core.hpp"

int32_t main()
{
    core::MATRIX<int> a(2, 3), b(3, 3);
    a.display();
    b.display();
    return EXIT_SUCCESS;
}
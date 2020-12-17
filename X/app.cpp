#include "core.hpp"

int32_t main()
{
    core::MATRIX<int> a(std::filesystem::path("app.inp"));
    core::MATRIX<int> b(std::filesystem::path("app.inp"));
    a.display();
    b.display();
    return EXIT_SUCCESS;
}
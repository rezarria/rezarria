#include "mmm.hpp"

int main()
{
    MATRIX<int> a, b;
    std::fstream input, output;
    input.open("app.inp", std::ios::in);
    output.open("app.out", std::ios::out);
    a.importMatrix(input);
    b.operator=(a.D(1, 1));
    b.display();
    input.close();
    return EXIT_SUCCESS;
}
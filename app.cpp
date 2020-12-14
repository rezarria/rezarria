#include "mmm.hpp"

int main()
{
    MATRIX<int> a, b, c;
    std::fstream input, output;
    input.open("app.inp", std::ios::in);
    output.open("app.out", std::ios::out);
    a.importMatrix(input);
    b = a;
    a.display();
    b.display();
    c = a + b;
    c.display();
    c.exportMatrix(output);
    input.close();
    return EXIT_SUCCESS;
}
#include <iostream>

class Complex
{
private:
    double a, b;

public:
    Complex();
    void input();
    void output();
    friend Complex operator-(Complex &a, Complex &b);
    friend Complex operator+(Complex &a, Complex &b);
};

int main()
{
    Complex x, y;
    std::cout << std::endl
              << "Nhap so phuc x" << std::endl;
    x.input();
    std::cout << std::endl
              << "Nhap so phuc y" << std::endl;
    y.input();
    std::cout << "Hieu 2 so" << std::endl;
    (x - y).output();
    std::cout << std::endl
              << "Tong 2 so" << std::endl;
    (x + y).output();
    return 0;
}

// LOP Complex

Complex::Complex()
{
    a = b = 0.0;
}

inline void Complex::input()
{
    std::cout << "thuc = ";
    std::cin >> a;
    std::cout << "ao = ";
    std::cin >> b;
}

inline void Complex::output()
{
    std::cout << a;
    if (b > 0)
        std::cout << "+";
    if (b < 0)
        std::cout << "-";
    if (b != 0)
        std::cout << b << "*i";
}

inline Complex operator-(Complex &a, Complex &b)
{
    Complex t;
    t.a = a.a - b.a;
    t.b = a.b - b.b;
    return t;
}

inline Complex operator+(Complex &a, Complex &b)
{
    Complex t;
    t.a = a.a + b.a;
    t.b = a.b + b.b;
    return t;
}
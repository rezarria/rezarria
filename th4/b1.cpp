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

Complex::Complex()
{
    a = b = 0.0;
}

void Complex::input()
{
    std::cout << "thuc = ";
    std::cin >> a;
    std::cout << "ao = ";
    std::cin >> b;
}

void Complex::output()
{
    std::cout << a << "+i*" << b;
}

Complex operator-(Complex &a, Complex &b)
{
    Complex t;
    t.a = a.a - b.a;
    t.b = a.b - b.b;
    return t;
}

Complex operator+(Complex &a, Complex &b)
{
    Complex t;
    t.a = a.a + b.a;
    t.b = a.b + b.b;
    return t;
}
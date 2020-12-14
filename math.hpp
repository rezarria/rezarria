#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cmath>
#include <fstream>
template<typename T>
struct DATA
{
    T*** value;
    size_t n, m;
};


template <typename T>
class MATRIX
{
private:
    DATA<T> data;
    void customSize(size_t n, size_t m);
public:
    MATRIX(std::fstream file);
    MATRIX(size_t n, size_t m);
    MATRIX();
    void infoMatrix();
    void importMatrix();
    void importMatrix_f(std::fstream file);
    void displayMatrix();
    MATRIX& operator+(MATRIX& b);
    MATRIX& operator*(MATRIX& b);
    MATRIX& operator*(int32_t a);
    MATRIX& operator*(float a);
    MATRIX& operator*(double a);
    MATRIX& operator=(MATRIX& b);
};
template<typename T>
void MATRIX<T>::customSize(size_t n, size_t m)
{
    this.data.n = n;
    this.data.m = m;
    this.data.value = new T * [this.data.n];
    for (size_t i = 0llu; i < this.data.n; i++)
        this.data.value[i] = new T[this.data.m];
    std::cout << "dieu chinh xong" << std::endl;
}


template <typename T>
MATRIX<T>::MATRIX(size_t n, size_t m)
{
    customSize(n, m);
}


template <typename T>
void MATRIX<T>::infoMatrix()
{
    cout << "size\t:\t" << data.n << 'x' << data.m << std::endl;
}
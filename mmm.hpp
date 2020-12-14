#pragma once
#include "mmm_core.hpp"


template<typename T>
void MATRIX<T>::reSize()
{
    value.resize(column);
    for (std::vector<T>& p : value)
        p.resize(row);
    std::cout << "Thay doi kick thuoc thanh cong" << std::endl;
}

template<typename T>
void MATRIX<T>::importValue()
{
    for (size_t i = 0llu; i < column; i++)
        for (size_t j = 0llu; j < row; j++)
        {
            printf("[%llu,%llu]\t= ", i, j);
            std::cin >> value[i][j];
        }
}

template<typename T>
void MATRIX<T>::importValue(std::fstream& input)
{
    for (std::vector<T>& p : value)
        for (T& n : p)
            input >> n;
}

template<typename T>
MATRIX<T>::MATRIX(size_t n, size_t m)
{
    column = n;
    row = m;
    reSize();
}

template<typename T>
MATRIX<T>::MATRIX()
{
    std::cout << "Khoi tao mang tran rong" << std::endl;
}

template<typename T>
MATRIX<T>::~MATRIX()
{
    std::cout << "Xoa ma tran" << std::endl;
}

template<typename T>
void MATRIX<T>::importMatrix()
{
    importValue();
}

template<typename T>
void MATRIX<T>::importMatrix(std::fstream& input)
{
    input >> column >> row;
    reSize();
    importValue(input);
    std::cout << "Nhap thanh cong" << std::endl;
}

template<typename T>
void MATRIX<T>::exportMatrix(std::fstream& output)
{
    output << column << " " << row << std::endl;
    for (size_t i = 0llu; i < column; i++)
        for (size_t j = 0llu; j < row; j++)
        {
            output << value[i][j] << (j == row - 1llu) ? (std::endl) : " ";
        }
    std::cout << "Xuat thanh cong" << std::endl;
}

template<typename T>
void MATRIX<T>::display()
{
    for (size_t i = 0llu; i < column; i++)
    {
        for (size_t j = 0llu; j < row; j++)
            std::cout << value[i][j] << '\t';
        std::cout << std::endl;
    }
}

template<typename T>
MATRIX<T>& MATRIX<T>::operator+(MATRIX<T>& b)
{
    MATRIX* matrix;
    if (checkN(*this, b))
    {
        matrix = new MATRIX<T>(column, row);
        for (size_t i = 0llu; i < column; i++)
            for (size_t j = 0llu; j < row; j++)
                matrix->value[i][j] = this->value[i][j] + b.value[i][j];
    }
    return *matrix;
}

template<typename T>
MATRIX<T>& MATRIX<T>::operator*(MATRIX<T>& b)
{}

template<typename T>
MATRIX<T>& MATRIX<T>::operator*(float b)
{}

template<typename T>
MATRIX<T>& MATRIX<T>::operator=(MATRIX& b)
{
    column = b.column;
    row = b.column;
    value = b.value;
    return *this;
}

template<typename P>
bool checkN(MATRIX<P>& a, MATRIX<P>& b)
{
    return (a.column == b.column) && (a.row == b.row);
}



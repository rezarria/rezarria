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
    for (std::vector<T>& p : value)
        for (T& n : p)
            n = import<T>(std::cin);
}

template<typename T>
void MATRIX<T>::importValue(std::fstream& input)
{
    for (std::vector<T>& p : value)
        for (T& n : p)
            n = import<T>(input);
}

template<typename T>
void MATRIX<T>::importValue(size_t i, size_t j, T value)
{
    this->value[i][j] = value;
}

template<typename T>
void MATRIX<T>::importValue(std::vector<std::vector<T>> value)
{
    this->value = value;
}

template<typename T>
void MATRIX<T>::columnSet(size_t column)
{
    this->column = column;
}

template<typename T>
void MATRIX<T>::rowSet(size_t row)
{
    this->row = row;
}

template<typename T>
MATRIX<T>::MATRIX(size_t column, size_t row)
{
    columnSet(column);
    rowSet(row);
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
    column = import<T>(input);
    row = import<T>(input);
    reSize();
    importValue(input);
    std::cout << "Nhap thanh cong" << std::endl;
}

template<typename T>
void MATRIX<T>::exportMatrix(std::fstream& output)
{
    output << column << " " << row << std::endl;
    size_t pin = row - 1llu;
    for (size_t i = 0llu; i < column; i++)
        for (size_t j = 0llu; j < row; j++)
        {
            output << value[i][j];
            if (j == pin)
                output << std::endl;
            else
                output << " ";
        }
    std::cout << "Xuat thanh cong" << std::endl;
}

template<typename T>
void MATRIX<T>::display()
{
    std::cout << "--------------------------------------\n";
    for (size_t i = 0llu; i < column; i++)
    {
        for (size_t j = 0llu; j < row; j++)
            std::cout << value[i][j] << '\t';
        std::cout << std::endl;
    }
}

template<typename T>
T MATRIX<T>::det()
{
    if (column == row)
        return det(0llu, 0llu);
}

template<typename T>
MATRIX<T>& MATRIX<T>::operator+(MATRIX<T>& b)
{
    MATRIX* matrix = NULL;
    if (checkN(*this, b))
    {
        matrix = new MATRIX<T>(column, row);
        for (size_t i = 0llu; i < column; i++)
            for (size_t j = 0llu; j < row; j++)
                matrix->importValue(i, j, this->value[i][j] + b.value[i][j]);
    }
    return *matrix;
}

template<typename T>
MATRIX<T>& MATRIX<T>::operator*(MATRIX<T>& b)
{
    MATRIX* matrix = NULL;
    if (checkD(*this, b))
    {
        matrix = new MATRIX<T>(column, b.row);
        for (size_t i = 0llu; i < column; i++)
            for (size_t j = 0llu; j < b.row; j++)
            {
                T tmp = 0;
                for (size_t k = 0llu; k < row; k++)
                    tmp += value[i][k] * b.value[k][j];
                matrix->importValue(i, j, tmp);
            }
        return *matrix;
    }
    return *matrix;
}

template<typename T>
MATRIX<T>& MATRIX<T>::operator*(T b)
{
    for (std::vector<T>& p : value)
        for (T& n : p)
            n *= b;
    return *this;
}

template<typename T>
MATRIX<T>& MATRIX<T>::operator=(MATRIX& b)
{
    column = b.column;
    row = b.column;
    importValue(b.value);
    return *this;
}

template<typename P>
bool checkN(MATRIX<P>& a, MATRIX<P>& b)
{
    return (a.column == b.column) && (a.row == b.row);
}

template<typename P>
bool checkD(MATRIX<P>& a, MATRIX<P>& b)
{
    return a.row == b.column;
}

template<typename T>
template<typename P>
P MATRIX<T>::import()
{
    return import<P>(std::cin);
}

template<typename T>
template<typename P>
P MATRIX<T>::import(std::fstream& input)
{
    P n;
    input >> n;
    return n;
}

template<typename T>
T MATRIX<T>::det(size_t i, size_t j)
{
    T tmp = NULL;
    if (i - column == 2llu)
    {
        for (size_t _i = i + 1llu; _i < column; _i++)
            for (size_t _j = j + 1llu; _j < row; _j++)
                tmp += det(_i, _j);
        tmp *= value[i][j];
    }
    else
    {
        tmp = value[i][j] * value[column][row] - value[i][row] * value[j][column];
    }
    return tmp;
}
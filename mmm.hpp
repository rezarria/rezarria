#pragma once
#include "mmm_core.hpp"

template<typename T>
T mPow(T n, int e)
{
    T result = 1;
    for (int32_t i = 0; i < e; i++)
        if (n > 0)
            result *= n;
        else
            if (n < 0)
                result /= n;

    return result;
}

template<typename T>
void MATRIX<T>::reSize()
{
    value->resize(column);
    for (std::vector<T>& p : *value)
        p.resize(row);
    std::cout << "Thay doi kick thuoc thanh cong" << std::endl;
}

template<typename T>
void MATRIX<T>::importValue()
{
    for (std::vector<T>& p : *value)
        for (T& n : p)
            n = import<T>(std::cin);
}

template<typename T>
void MATRIX<T>::importValue(std::fstream& input)
{
    for (std::vector<T>& p : *value)
        for (T& n : p)
            n = import<T>(input);
}

template<typename T>
void MATRIX<T>::importValue(size_t i, size_t j, T value)
{
    this->value[i][j] = value;
}

template<typename T>
void MATRIX<T>::importValue(const std::vector<std::vector<T>>& value)
{
    for (size_t i = 0llu; i < column; i++)
        for (size_t j = 0llu; j < row; j++)
            (*this->value)[i][j] = (*value)[i][j];
}

template<typename T>
void MATRIX<T>::importValue(std::vector<std::vector<T>>&& value)
{
    this->value = value;
    value = NULL;
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
            std::cout << (*value)[i][j] << '\t';
        std::cout << std::endl;
    }
}

template<typename T>
void MATRIX<T>::info()
{
    std::cout << "---------------------------------" << std::endl;
    std::cout << column << "x" << row << std::endl;
    std::cout << "size : " << sizeof(T) << std::endl;
    std::cout << "addr : " << &value << std::endl;
    for (std::vector<T>& p : value)
    {
        std::cout << "column : " << &p << std::endl;
        for (T& n : p)
            std::cout << &n << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;
}

template<typename T>
MATRIX<T> MATRIX<T>::operator+(MATRIX<T>& b)
{
    MATRIX<T> matrix;
    if (checkN(*this, b))
    {
        matrix.columnSet(column);
        matrix.rowSet(row);
        matrix.reSize();
        for (size_t i = 0llu; i < column; i++)
            for (size_t j = 0llu; j < row; j++)
                matrix.importValue(i, j, this->value[i][j] + b.value[i][j]);
    }
    return matrix;
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
const MATRIX<T>& MATRIX<T>::operator=(const MATRIX& b)
{
    columnSet(b.column);
    rowSet(b.rowSet);
    reSize();
    importValue(b);
    return *this;
}

template<typename T>
const MATRIX<T>& MATRIX<T>::operator=(MATRIX&& b)
{
    column = b.column;
    row = b.column;
    importValue(std::move(b));
    return *this;
}

template<typename T>
T* MATRIX<T>::operator[](size_t x)
{
    return value[x];
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
MATRIX<T>& MATRIX<T>::D(size_t x, size_t y)
{
    size_t _i = 0llu, _j = 0llu;
    MATRIX<T>* matrix = new MATRIX<T>(column - 1llu, row - 1llu);
    matrix->info();
    for (size_t i = 0llu; i < column; i++)
        for (size_t j = 0llu; j < row; j++)
            if ((i != x) && (j != y))
            {
                matrix->value[_i][_j] = value[i][j];
                _j++;
                if (_j == matrix->row)
                {
                    _j = 0llu;
                    _i++;
                }
            }
    return *matrix;
}

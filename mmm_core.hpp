#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

template<typename T>
T mPow(T n, int e);

template<typename T>
class MATRIX
{
private:
    std::vector<std::vector<T>> value;
    size_t column = 0llu;
    size_t row = 0llu;
    void reSize();
    void importValue();
    void importValue(std::fstream& input);
    void importValue(size_t i, size_t j, T value);
    void importValue(std::vector<std::vector<T>> value);
    void columnSet(size_t column);
    void rowSet(size_t row);
    template<typename P>
    P import();
    template<typename P>
    P import(std::fstream& input);
public:
    MATRIX(size_t column, size_t row);
    MATRIX();
    ~MATRIX();
    void importMatrix();
    void importMatrix(std::fstream& input);
    void exportMatrix(std::fstream& output);
    void display();
    void info();
    MATRIX& operator+(MATRIX& b);
    MATRIX& operator*(MATRIX& b);
    MATRIX& operator*(T b);
    MATRIX& operator=(MATRIX& b);
    T* operator[](size_t x);
    template<typename P>
    friend bool checkN(MATRIX<P>& a, MATRIX<P>& b);
    template<typename P>
    friend bool checkD(MATRIX<P>& a, MATRIX<P>& b);
    template<typename P>
    friend P det(MATRIX<P>& a);
    template<typename P>
    friend P det(MATRIX<P>& a, size_t i, size_t j);
    MATRIX& D(size_t x, size_t y);
};
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

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
public:
    MATRIX(size_t n, size_t m);
    MATRIX();
    ~MATRIX();
    void importMatrix();
    void importMatrix(std::fstream& input);
    void exportMatrix(std::fstream& output);
    void display();
    MATRIX& operator+(MATRIX& b);
    MATRIX& operator*(MATRIX& b);
    MATRIX& operator*(float b);
    MATRIX& operator=(MATRIX& b);
    template<typename P>
    friend bool checkN(MATRIX<P>& a, MATRIX<P>& b);
};
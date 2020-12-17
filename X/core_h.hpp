#pragma once
#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <map>


namespace core
{
    template<typename T>
    class MATRIX
    {
    private:
        std::vector<std::vector<T>>* value = NULL;
        size_t id = 0llu;
        size_t column = 0llu;
        size_t row = 0llu;
        size_t&& getID();
        std::map<size_t, MATRIX<T>*>& getRecord();
        size_t createID();
        void addRecord();
        void removeRecord();
        void refeshValue();
        void reSizeAllColumn();
        void reSizeAllRow();
        void importValue(std::fstream input);
        void importValue(std::vector<std::vector<T>>& other);
        void setColumn(size_t column);
        void setRow(size_t row);
        void clearColumn(size_t begin, size_t end);
        void clearRow(size_t begin, size_t end);
        void eraseColumn(size_t begin, size_t end);
        void eraseRow(size_t begin, size_t end);
        void insertColumn(size_t pos, const std::vector<T>& list);
        void insertColumn(size_t pos, std::vector<T>&& list);
        void insertRow(size_t pos, const std::vector<T>& list);
        void insertRow(size_t pos, std::vector<T>&& list);
        void deleteValue();
    public:
        MATRIX();
        MATRIX(size_t column, size_t row);
        MATRIX(std::fstream input);
        MATRIX(const std::vector<std::vector<T>>& other);
        MATRIX(std::vector<std::vector<T>>&& other);
        MATRIX(const MATRIX<T>& other);
        MATRIX(MATRIX<T>&& other);
        ~MATRIX();
        MATRIX<T>&& operator+(const MATRIX<T>& other);
        MATRIX<T>&& operator*(const MATRIX<T>& other);
        const MATRIX<T>& operator=(const MATRIX<T>& other);
        const MATRIX<T>& operator=(MATRIX<T>&& other);
        T Det();
        MATRIX<T>&& D(size_t i, size_t j);
        void clear();
        void info();
        void showValue();
        void display();
        T* operator[](size_t x);
    };
}
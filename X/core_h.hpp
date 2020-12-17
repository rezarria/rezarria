#pragma once
#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <map>
#include <filesystem>

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
        void importValue(std::fstream& input);
        void importValue(std::fstream&& input);
        void importValue(std::vector<std::vector<T>>& other);
        void setColumn(size_t column);
        void setColumn(std::fstream& input);
        void setColumn(std::fstream&& input);
        void setRow(size_t row);
        void setRow(std::fstream& input);
        void setRow(std::fstream&& input);
        void setValue(std::vector<std::vector<T>>* value);
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
        MATRIX(const std::fstream& input);
        MATRIX(std::fstream&& input);
        MATRIX(const std::filesystem::path& path);
        MATRIX(std::filesystem::path&& path);
        MATRIX(const std::vector<std::vector<T>>& other);
        MATRIX(std::vector<std::vector<T>>&& other);
        MATRIX(const MATRIX<T>& other);
        MATRIX(MATRIX<T>&& other);
        void import(const std::fstream& input);
        void import(std::fstream&& input);
        void import(const std::filesystem::path& path);
        void import(std::filesystem::path&& path);
        void import(const std::vector<std::vector<T>>& other);
        void import(std::vector<std::vector<T>>&& other);
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
        friend bool isSameSize(const MATRIX<T>& a, const MATRIX<T>& b);
    };
}
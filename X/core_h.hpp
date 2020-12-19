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

#define text_mode false
#define binary_mode true

template<typename T>
class Matrix
{
private:
    std::vector<std::vector<T>>* value;
protected:
public:
    Matrix();
    Matrix(std::filesystem::path&& path, bool mode = text_mode);
    ~Matrix();
};
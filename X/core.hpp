#pragma once
#include "core_h.hpp"

namespace core
{
    template<typename T>
    size_t MATRIX<T>::createID()
    {
        static size_t ID = 0llu;
        return ++ID;
    }

    template<typename T>
    void MATRIX<T>::refeshValue()
    {
        reSizeAllColumn();
        reSizeAllRow();
        std::cout << "Da refesh Value xong" << std::endl;
    }

    template<typename T>
    void MATRIX<T>::reSizeAllColumn()
    {
        if (value)
        {
            if ((row != value->at(0llu).size()) && (column < value->size()))
                reSizeAllRow();
            value->resize(column);
            std::cout << "RESIZE hang thanh cong" << std::endl;
        }
    }

    template<typename T>
    void MATRIX<T>::reSizeAllRow()
    {
        if (value)
        {
            if (column > value->size())
                reSizeAllColumn();
            for (std::vector<T>& p : *value)
                p.resize(row);
            std::cout << "RESIZE cot thanh cong" << std::endl;
        }
    }

    template<typename T>
    void MATRIX<T>::importValue(std::fstream input)
    {
        for (std::vector<T>& p : *value)
            for (T& n : p)
                input >> n;
    }

    template<typename T>
    void MATRIX<T>::importValue(std::vector<std::vector<T>>& other)
    {
        clear();
        value = new std::vector<std::vector<T>>;
        *value = *other;
    }

    template<typename T>
    void MATRIX<T>::setColumn(size_t column)
    {
        this->column = column;
        std::cout << "Column = " << this->column << std::endl;
    }

    template<typename T>
    void MATRIX<T>::addRecord()
    {
        ID = createID();
    }

    template<typename T>
    void MATRIX<T>::setRow(size_t row)
    {
        this->row = row;
        std::cout << "Row = " << this->row << std::endl;
    }

    template<typename T>
    MATRIX<T>::MATRIX()
    {
        addRecord();
        std::cout << "Tao thanh cong ma tran" << std::endl;
    }

    template<typename T>
    MATRIX<T>::MATRIX(size_t column, size_t row)
    {
        setColumn(column);
        setRow(row);
        refeshValue();
        addRecord();
        std::cout << "Tao ma tran rong " << column << "x" << row << " thanh cong" << std::endl;
    }

    template<typename T>
    MATRIX<T>::MATRIX(std::fstream input)
    {
        input >> column >> row;
        refeshValue();
        importValue(input);
        addRecord();
        std::cout << "Nhap tu file thanh cong" << std::endl;
    }

    template<typename T>
    MATRIX<T>::MATRIX(const std::vector<std::vector<T>>& other)
    {
        setColumn(other.size());
        setRow(other[0].size());
        addRecord();
        importValue(other);
    }

    template<typename T>
    MATRIX<T>::~MATRIX()
    {
        std::cout << "Huy ham thanh cong" << std::endl;
    }

    template<typename T>
    void MATRIX<T>::clear()
    {
        for (std::vector<std::vector<T>>& p : *value)
            p.clear();
        value->clear();
        setColumn(0llu);
        setRow(0llu);

    }

    template<typename T>
    void MATRIX<T>::info()
    {
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "id    : " << ID << std::endl;
        std::cout << "addr  : " << value << std::endl;
        std::cout << "size  : " << column << "x" << row << std::endl;
    }

    template<typename T>
    void MATRIX<T>::showValue()
    {
        std::cout << "-------------------------------------" << std::endl;
        if (column && row && value)
            for (std::vector<T>& p : *value)
            {
                for (T& n : p)
                    std::cout << n << "\t";
                std::cout << std::endl;
            }
    }

    template<typename T>
    void MATRIX<T>::display()
    {
        info();
        showValue();
    }



}




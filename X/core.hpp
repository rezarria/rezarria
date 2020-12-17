#pragma once
#include "core_h.hpp"



namespace core
{
    template<typename T>
    size_t&& MATRIX<T>::getID()
    {
        static size_t ID = 0llu;
        ID++;
        return std::move(ID);
    }

    template<typename T>
    std::map<size_t, MATRIX<T>*>& MATRIX<T>::getRecord()
    {
        static std::map<size_t, core::MATRIX<T>*> record;
        return record;
    }

    template<typename T>
    size_t MATRIX<T>::createID()
    {
        if (!id)
            id = getID();
        return id;
    }

    template<typename T>
    void MATRIX<T>::addRecord()
    {
        id = createID();
        if (id && !getRecord().contains(id))
            getRecord().insert({ id, this });
    }

    template<typename T>
    void MATRIX<T>::removeRecord()
    {
    }
    template<typename T>
    void MATRIX<T>::refeshValue()
    {
        if (value)
        {
            reSizeAllColumn();
            reSizeAllRow();
        }
        else value = new std::vector<std::vector<T>>;
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
    void MATRIX<T>::importValue(std::fstream& input)
    {
        for (std::vector<T>& p : *value)
            for (T& n : p)
                input >> n;
    }

    template<typename T>
    void MATRIX<T>::importValue(std::fstream&& input)
    {
        std::streamsize size = sizeof(T);
        for (std::vector<T>& p : *value)
            for (T& n : p)
                input.read((char*)&n, size);
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
    void MATRIX<T>::setColumn(std::fstream& input)
    {
        input >> column;
    }

    template<typename T>
    void MATRIX<T>::setColumn(std::fstream&& input)
    {
        input.read((char*)&column, sizeof(size_t));
    }

    template<typename T>
    void MATRIX<T>::setRow(size_t row)
    {
        this->row = row;
        std::cout << "Row = " << this->row << std::endl;
    }

    template<typename T>
    void MATRIX<T>::setRow(std::fstream& input)
    {
        input >> row;
    }

    template<typename T>
    void MATRIX<T>::setRow(std::fstream&& input)
    {
        input.read((char*)&row, sizeof(size_t));
    }

    template<typename T>
    void MATRIX<T>::setValue(std::vector<std::vector<T>>* value)
    {
        this->value = value;
    }

    template<typename T>
    void MATRIX<T>::deleteValue()
    {
        if (value)
        {
            for (std::vector<T>& p : *value)
                p.clear();
            value->clear();
        }
    }

    template<typename T>
    MATRIX<T>::MATRIX()
    {
        std::cout << "Tao thanh cong ma tran" << std::endl;
    }

    template<typename T>
    MATRIX<T>::MATRIX(size_t column, size_t row)
    {
        addRecord();
        setColumn(column);
        setRow(row);
        refeshValue();
        std::cout << "Tao ma tran rong " << column << "x" << row << " thanh cong" << std::endl;
    }

    template<typename T>
    MATRIX<T>::MATRIX(const std::fstream& input)
    {
        setColumn(input);
        setRow(input);
        refeshValue();
        importValue(input);
        std::cout << "Nhap tu file ki tu thanh cong" << std::endl;
    }

    template<typename T>
    MATRIX<T>::MATRIX(std::fstream&& input)
    {
        setColumn(input);
        setRow(input);
        refeshValue();
        importValue(input);
        std::cout << "Nhap tu file nhi phan thanh cong" << std::endl;
    }

    template<typename T>
    MATRIX<T>::MATRIX(const std::filesystem::path& path)
    {
        std::fstream input;
        input.open(path, std::ios::in);
        import(input);
        input.close();
    }

    template<typename T>
    MATRIX<T>::MATRIX(std::filesystem::path&& path)
    {
        std::fstream input;
        input.open(path, std::ios::in | std::ios::binary);
        import(input);
        input.close();
    }

    template<typename T>
    MATRIX<T>::MATRIX(const std::vector<std::vector<T>>& other)
    {
        setColumn(other.size());
        setRow(other[0].size());
        importValue(other);
    }

    template<typename T>
    MATRIX<T>::~MATRIX()
    {
        deleteValue();
        getRecord().erase(id);
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "Huy ma tran" << std::endl;
        std::cout << "id : " << id << std::endl;
        std::cout << "n = " << getRecord().size() << std::endl;
        std::cout << "Huy ham thanh cong" << std::endl;
    }

    template<typename T>
    MATRIX<T>&& MATRIX<T>::operator+(const MATRIX<T>& other)
    {
        MATRIX out;
        if (isSameSize(*this, other))
        {
            out.setColumn(column);
            out.setRow(row);
            out.refeshValue();
            for (size_t i = 0llu; i < column; i++)
                for (size_t j = 0; j < row; j++)
                    out.value = this->value[i][j] + other.value[i][j];
        }
        return std::move(out);
    }

    template<typename T>
    const MATRIX<T>& MATRIX<T>::operator=(MATRIX<T>&& other)
    {
        setColumn(other.column);
        setRow(other.row);
        setValue(other.value);
        other.value = NULL;
        return this*;
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
        std::cout << "id    : " << id << std::endl;
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
    template<typename T>
    bool isSameSize(const MATRIX<T>& a, const MATRIX<T>& b)
    {
        return (a.column == b.column) && (a.row = b.row);
    }
}




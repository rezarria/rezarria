#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Info
{
    std::string ten;
    int nam;
    std::string mail;
};

class List : public std::vector<Info>
{
private:
    std::string cutName(const std::string name)
    {
        size_t pos = name.rfind(' ', name.size() - 1);
        return name.substr(pos, name.length() - pos);
    }
    bool nameCmp(const std::string a, const std::string b)
    {
        int t = cutName(a).compare(cutName(b));
        if (t)
            return t < 0;
        else
            return cutName(a).compare(b) > 0;
    }
    size_t partition(size_t l, size_t r)
    {
        if (l < r - 1)
        {
            r--;
            size_t count = 0;
            size_t where = l + std::rand() % (r - l);
            std::swap(at(where), at(r));
            for (size_t i = l; i < r; i++)
                if (nameCmp(at(i).ten, at(r).ten))
                    std::swap(at(i), at(count++));
            std::swap(at(count), at(r));
            return count;
        }
        else
            return l;
    }
    void quickSort(size_t l, size_t r)
    {
        if (l < r)
        {
            size_t pin = partition(l, r);
            quickSort(l, pin);
            quickSort(pin + 1, r);
        }
    }

public:
    List &readFile(const std::string path)
    {
        std::ifstream file(path, std::ios::in);
        Info buffer;
        while (std::getline(file, buffer.ten))
        {
            file >> buffer.nam;
            file.ignore(1);
            std::getline(file, buffer.mail);
            file.ignore(1);
            push_back(buffer);
        }
        file.close();
        return *this;
    }
    List &display()
    {
        for (Info &info : *this)
        {
            std::cout << "Ten\t: " << info.ten << std::endl
                      << "Nam\t: " << info.nam << std::endl
                      << "Mail\t: " << info.mail << std::endl
                      << std::endl;
        }
        return *this;
    }
    List &sort()
    {
        quickSort(0, size());
        return *this;
    }
};

int main()
{
    List list;
    list.readFile("input.txt").display().sort().display();
    return 0;
}
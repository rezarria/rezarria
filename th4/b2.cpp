#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

class Mydate
{
private:
    int day, month, year;

public:
    Mydate();
    void input();
    void output();
    friend bool operator>=(const Mydate &a, const Mydate &b);
};

bool Mydate__cmp(const Mydate &a, const Mydate &b);

int main()
{
    std::vector<Mydate> dates;
    dates.resize(5);
    for (Mydate &date : dates)
    {
        std::cout << std::endl;
        date.input();
    }
    std::cout << "Date co thoi gian lon nhat :";
    std::max_element(dates.begin(), dates.end(), Mydate__cmp)->output();
    return 0;
}

Mydate::Mydate()
{
    day = month = year = 0;
}

void Mydate::input()
{
    std::cout << "day : ";
    std::cin >> day;
    std::cout << "month: ";
    std::cin >> month;
    std::cout << "year: ";
    std::cin >> year;
}

void Mydate::output()
{
    std::cout << std::setfill('0') << std::setw(2) << day << " - " << std::setw(2) << month << " - " << std::setw(4) << year << std::endl;
}

bool operator>=(Mydate const &a, Mydate const &b)
{
    return ((a.year * 12 + a.month) * 30 + a.day) >= ((b.year * 12 + b.month) * 30 + b.day);
}

bool Mydate__cmp(const Mydate &a, const Mydate &b)
{
    return b >= a;
}
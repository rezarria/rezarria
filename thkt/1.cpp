#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Mytime
{
protected:
    int gio, phut, giay;

public:
    Mytime(int gio = 0, int phut = 0, int giay = 0);
    void nhap(), hien();
};

class MyDateTime : public Mytime
{
public:
    MyDateTime(int ngay = 0, int thang = 0, int nam = 0);
    void nhap(), hien();
};

int main()
{
    vector<MyDateTime> dates;
    dates.resize(5);

    for (MyDateTime &date : dates)
        date.nhap();

    for (MyDateTime &date : dates)
        date.hien();

    return 0;
}

Mytime::Mytime(int gio, int phut, int giay)
{
    this->giay = giay;
    this->gio = gio;
    this->phut = phut;
}

void Mytime::nhap()
{
    cout << endl
         << "++++++++++++++++++++++++" << endl;
    cout << "Gio : ";
    cin >> gio;
    cout << "Phut : ";
    cin >> phut;
    cout << "Giay : ";
    cin >> giay;
    cout << "++++++++++++++++++++++++" << endl;
}

void Mytime::hien()
{
    cout << setfill('0') << setw(2) << gio << " : " << phut << " : " << giay << endl;
}

MyDateTime::MyDateTime(int ngay, int thang, int nam) : MyDateTime::Mytime(ngay, thang, nam)
{
}

void MyDateTime::nhap()
{
    cout << endl
         << "++++++++++++++++++++++++" << endl;
    cout << "Ngay : ";
    cin >> gio;
    cout << "Thang : ";
    cin >> phut;
    cout << "Nam : ";
    cin >> giay;
    cout << "++++++++++++++++++++++++" << endl;
}

void MyDateTime::hien()
{
    cout << setfill('0') << setw(2) << gio;
    cout << "-" << setw(2) << phut;
    cout << "-" << setw(4) << giay << endl;
}
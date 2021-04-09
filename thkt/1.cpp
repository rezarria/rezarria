#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Mytime
{
private:
    int gio, phut, giay;

public:
    Mytime(int gio = 0, int phut = 0, int giay = 0);
    void nhap(), hien();
};

class MyDateTime : public Mytime
{
private:
    int ngay, thang, nam
public:
    MyDateTime(int ngay = 0, int thang = 0, int nam = 0, int gio = 0, int phut = 0, int giay = 0);
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

MyDateTime::MyDateTime(int ngay, int thang, int nam, int gio, int phut, int giay) : MyDateTime::Mytime(gio, phut, giay)
{
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
}

void MyDateTime::nhap()
{
    cout << endl
         << "++++++++++++++++++++++++" << endl;
    cout << "Ngay : ";
    cin >> ngay;
    cout << "Thang : ";
    cin >> thang;
    cout << "Nam : ";
    cin >> nam;
    Mytime::nhap();
    cout << "++++++++++++++++++++++++" << endl;
}

void MyDateTime::hien()
{
    cout << endl
         <<"++++++++++++++++++++++++" << endl;
    cout << setfill('0') << setw(2) << ngay;
    cout << "-" << setw(2) << thang;
    cout << "-" << setw(4) << nam << endl;
    Mytime::hien();
    cout << "++++++++++++++++++++++++" << endl;
}

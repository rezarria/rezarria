#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class MyAddress
{
protected:
    string tinh, huyen;

public:
    MyAddress(string tinh, string huyen);
    void nhap(), hien();
};

class Person : public MyAddress
{
protected:
    string Name;
    string Phone;
    string Salary;

public:
    Person(string Name = "Trong", string Phone = "Trong", string Salary = "Trong", string tinh = "Trong", string huyen = "Trong");
    void nhap(), hien();
};

void nhap(string &str);

int main()
{
    vector<Person> list;
    int n;
    cout << "Nhap n : ";
    cin >> n;
    cin.ignore();
    list.resize(n);

    for (Person &person : list)
        person.nhap();

    for (Person &person : list)
        person.hien();

    return 0;
}

MyAddress::MyAddress(string tinh, string huyen)
{
    this->tinh = tinh;
    this->huyen = huyen;
}

void MyAddress::nhap()
{
    cout << "Tinh : ";
    getline(cin, tinh);
    cout << "Huyen : ";
    getline(cin, huyen);
}

void MyAddress::hien()
{
    cout << "Tinh : " << tinh << endl
         << "Huyen : " << huyen << endl;
}

Person::Person(string Name, string Phone, string Salary, string tinh, string huyen) : Person::MyAddress(tinh, huyen)
{
    this->Name = Name;
    this->Phone = Phone;
    this->Salary = Salary;
}

void Person::nhap()
{
    cout << endl
         << "==============================" << endl;
    cout << "Ten : ";
    getline(cin, Name);
    cout << "So dien thoai : ";
    getline(cin, Phone);
    cout << "Luong : ";
    getline(cin, Salary);
    MyAddress::nhap();
    cout << "==============================" << endl;
}

void Person::hien()
{
    cout << endl
         << "------------------------------" << endl;
    cout << "Ten : " << Name << endl
         << "So dien thoai : " << Phone << endl
         << "Luong : " << Salary << endl;
    MyAddress::hien();
    cout << "------------------------------" << endl;
}
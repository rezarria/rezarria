#include <stdio.h>
#include <limits.h>

typedef struct
{
    int giay, phut, gio;
} Date;

int nhapRangBuoc(int a, int b);
void nhapThoiGian(Date date[], int n);
void inThoiGian(Date date[], int n);

int main()
{
    Date date[3];
    nhapThoiGian(date, 3);
    inThoiGian(date, 3);
};

int nhapRangBuoc(int a, int b)
{
    int n;
    do
    {
        puts(">\t");
        scanf("%d", &n);
    } while (n < a || n > b);

    return n;
}

void nhapThoiGian(Date date[], int n)
{
    Date* i = &date[n];
    for (; date < i; date++)
    {
        printf("------------------\n");
        printf("%-10s :\n", "Gio");
        date->gio = nhapRangBuoc(0, 23);
        printf("%-10s :\n", "Phut");
        date->phut = nhapRangBuoc(0, 59);
        printf("%-10s :\n", "Giay");
        date->giay = nhapRangBuoc(0, 59);
    }
    printf("------------------\n");
}

void inThoiGian(Date date[], int n)
{
    Date* i = &date[n];

    for (; date < i; date++)
        printf("%02d:%02d:%02d\n", date->gio, date->phut, date->giay);
}
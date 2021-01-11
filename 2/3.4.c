#include <stdio.h>
#include <limits.h>

typedef struct
{
    int ngay, thang, nam;
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
        printf("%-10s :\n", "Ngay");
        date->ngay = nhapRangBuoc(1, 31);
        printf("%-10s :\n", "Thang");
        date->thang = nhapRangBuoc(1, 12);
        printf("%-10s :\n", "Nam");
        date->nam = nhapRangBuoc(0, INT_MAX);
    }
    printf("------------------\n");
}

void inThoiGian(Date date[], int n)
{
    Date* i = &date[n];

    for (; date < i; date++)
        printf("%02d/%02d/%d\n", date->ngay, date->thang, date->nam);
}
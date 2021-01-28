#include <stdio.h>

struct SV
{
    char hoten[30];
    int tuoi;
    float diemki1, diemki2, diemcanam;
};

void nhapThongTin(struct SV *sv, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("hoc sinh thu %d\n", i + 1);
        printf("Ho va ten : ");
        fflush(stdin);
        gets(sv[i].hoten);
        printf("diem ki 1 : ");
        scanf("%f", &sv[i].diemki1);
        printf("diem ki 2 : ");
        scanf("%f", &sv[i].diemki2);
        sv[i].diemcanam = (sv[i].diemki1 + sv[i].diemki2 * 2) / 3;
    }
}

void thongTin(struct SV *sv, int n)
{
    printf("%-30s %10s %10s %10s\n", "ho va ten", "diem ki 1", "diem ki 2", "diem ca nam");
    for (int i = 0; i < n; i++)
        printf("%-30s %10.2f %10.2f %10.2f\n", sv[i].hoten, sv[i].diemki1, sv[i].diemki2, sv[i].diemcanam);
}

int main()
{
    int n = 5;
    struct SV sv[5];
    nhapThongTin(sv, 5);
    thongTin(sv, 5);
    return 0;
}
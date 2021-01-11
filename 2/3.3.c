#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char ten[30];
    char maSinhVien[15];
    struct
    {
        float toan;
        float ly;
        float hoa;
        float tong;
    } diem;
} HOSO;

void nhapHoSo(HOSO hoso[], int n);
void inHoSo(HOSO hoso[], int n);

int main()
{
    HOSO hoso[3];
    nhapHoSo(hoso, 3);
    inHoSo(hoso, 3);
    return 0;
}

void nhapHoSo(HOSO hoso[], int n)
{
    HOSO* i = &hoso[n];
    for (; hoso < i; hoso++)
    {
        printf("----------------------------------------------------------------------------------------------------\n");
        printf("%-20s : ", "Ho va ten");
        fflush(stdin);
        gets(hoso->ten);
        printf("%-20s : ", "Ma sinh vien");
        fflush(stdin);
        gets(hoso->maSinhVien);
        printf("%-20s : ", "Diem toan");
        scanf("%f", &hoso->diem.toan);
        printf("%-20s : ", "Diem ly");
        scanf("%f", &hoso->diem.ly);
        printf("%-20s : ", "Diem hoa");
        scanf("%f", &hoso->diem.hoa);
        hoso->diem.toan = hoso->diem.toan + hoso->diem.ly + hoso->diem.hoa;
    }
    printf("----------------------------------------------------------------------------------------------------\n");
}

void inHoSo(HOSO hoso[], int n)
{
    HOSO* i = &hoso[n];
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("| %-30s | %-15s | %-9s | %-9s | %-9s | %-9s |\n", "Ho va ten", "Ma sinh vien", "Diem toan", "Diem ly", "Diem hoa", "Diem tong");
    printf("----------------------------------------------------------------------------------------------------\n");
    for (; hoso < i; hoso++)
        printf("| %-30s | %-15s | %-9.2f | %-9.2f | %-9.2f | %-9.2f |\n", hoso->ten, hoso->maSinhVien, hoso->diem.toan, hoso->diem.ly, hoso->diem.hoa, hoso->diem.tong);
    printf("----------------------------------------------------------------------------------------------------\n");
}
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char ten[30];
    char maSinhVien[15];
    float diemTrungBinh;
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
    void* i = (void*)&hoso[n];
    for (; hoso < i; hoso++)
    {
        printf("----------------------------------------------------------------------\n");
        printf("%-20s : ", "Ho va ten");
        fflush(stdin);
        gets(hoso->ten);
        printf("%-20s : ", "Ma sinh vien");
        fflush(stdin);
        gets(hoso->maSinhVien);
        printf("%-20s : ", "Diem trung binh");
        scanf("%f", &hoso->diemTrungBinh);
    }
    printf("----------------------------------------------------------------------\n");
}

void inHoSo(HOSO hoso[], int n)
{
    void* i = (void*)&hoso[n];
    printf("----------------------------------------------------------------------\n");
    printf("| %-30s | %-15s | %-15s |\n", "Ho va ten", "Ma sinh vien", "Diem trung binh");
    printf("----------------------------------------------------------------------\n");
    for (; hoso < i; hoso++)
        printf("| %-30s | %-15s | %-15.2f |\n", hoso->ten, hoso->maSinhVien, hoso->diemTrungBinh);
    printf("----------------------------------------------------------------------\n");
}
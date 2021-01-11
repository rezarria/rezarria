#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char ten[30];
    float heSoLuong;
    float luongThuc;
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
    for (;hoso < i; hoso++)
    {
        printf("----------------------------------------------------------------------\n");
        printf("%-20s : ", "Ho va ten");
        fflush(stdin);
        gets(hoso->ten);
        printf("%-20s : ", "He so luong");
        scanf("%f", &hoso->heSoLuong);
        hoso->luongThuc = hoso->heSoLuong * 1210000.0f;
    }
    printf("----------------------------------------------------------------------\n");
}

void inHoSo(HOSO hoso[], int n)
{
    HOSO* i = &hoso[n];
    printf("----------------------------------------------------------------------\n");
    printf("| %-30s | %-15s | %-15s |\n", "Ho va ten", "He so luong", "Luong thuc");
    printf("----------------------------------------------------------------------\n");
    for (;hoso < i; hoso++)
        printf("| %-30s | %-15.2f | %-15.2f |\n", hoso->ten, hoso->heSoLuong, hoso->luongThuc);
    printf("----------------------------------------------------------------------\n");
}
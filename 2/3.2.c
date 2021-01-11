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
    int i;
    HOSO* p;
    for (p = &hoso[i = 0]; i < n; p = &hoso[++i])
    {
        printf("----------------------------------------------------------------------\n");
        printf("%-20s : ", "Ho va ten");
        fflush(stdin);
        gets(p->ten);
        printf("%-20s : ", "He so luong");
        scanf("%f", &p->heSoLuong);
        p->luongThuc = p->heSoLuong * 1210000.0f;
    }
    printf("----------------------------------------------------------------------\n");
}

void inHoSo(HOSO hoso[], int n)
{
    int i;
    HOSO* p;
    printf("----------------------------------------------------------------------\n");
    printf("| %-30s | %-15s | %-15s |\n", "Ho va ten", "He so luong", "Luong thuc");
    printf("----------------------------------------------------------------------\n");
    for (p = &hoso[i = 0]; i < n; p = &hoso[++i])
        printf("| %-30s | %-15.2f | %-15.2f |\n", p->ten, p->heSoLuong, p->luongThuc);
    printf("----------------------------------------------------------------------\n");
}
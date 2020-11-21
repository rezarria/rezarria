#include <conio.h>
#include <stdio.h>
int main()
{
    float r, cv, dt;
    printf("Nhap r = ");
    scanf("%f", &r);
    cv = 2.0f * 3.14f * r;
    dt = 3.14f * r * r;
    printf("\nBan kinh = %5.2f", r);
    printf("\nChu vi = %5.2f", cv);
    printf("\nDien tich = %5.2f", dt);
    getch();
    return 0;
}
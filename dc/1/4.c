#include <stdio.h>

void giaiPT1(float a, float b)
{
    if (a == 0.0f)
    {
        if (b == 0.0f)
            printf("vi a = b = 0 nen phuong trinh vo so nghiem\n");
        else
            printf("vi 0 = a != b, suy va b = 0 la vo ly, nen phuong trinh vo nghiem\n");
    }
    else
    {
        if (b == 0.0f)
            printf("vi a != b = 0 nen nghiem cua phuong trinh la 0\n");
        else
            printf("vi a != 0 != b nen phuong trinh co nhiem la %f\n", -b / a);
    }
}

int main()
{
    float a, b;
    printf("Nhap so a va b : ");
    scanf("%f%f", &a, &b);
    giaiPT1(a, b);
    return 0;
}
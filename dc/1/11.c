#include <stdio.h>
#include <math.h>

void giaiPT2(float a, float b, float c)
{
    if (a == 0.0f)
        printf("vi a = 0 nen day khong phai la mot phuong trinh bac hai\n");
    else
    {
        float delta = b * b - 4 * a * c;
        if (delta == 0.0f)
        {
            printf("Vi delta = 0, nen phuong trinh co 1 nghiem\n");
            printf("x = %6.2f\n", -b / (2.0f * a));
        }
        if (delta > 0.0f)
        {
            float sqrtDelta = sqrt(delta);
            printf("vi delta > 0, nen phuong trinh co 2 nghiem\n");
            printf("x1 = %6.2f\nx2 = %6.2f\n", (-b - sqrtDelta) / (2.0f * a), (-b + sqrtDelta) / (2.0f * a));
        }
        else
            printf("vi delta < 0, nen phuong trinh vo nghiem\n");
    }
}

int main()
{
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);
    giaiPT2(a, b, c);
    return 0;
}
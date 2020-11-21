#include <conio.h>
#include <stdio.h>
int main()
{
    unsigned int n;
    printf("Nhap n : ");
    scanf("%u", &n);
    unsigned int a[n];
    // Biến mảng số nguyên a có n phần tử
    unsigned int min = 0, max = 0; // Biến min, max sẽ tham gia việc so sánh
    for(unsigned int i = 0; i < n)
        do
        {
            printf("Nhap phan tu %u : ");
            scanf("%u", &a[i]);
            if(max < a[i])
                max = &a[i];
            if(min > a[i])
                min = &a[i];
        }
        while(a[i] < 1);
    printf("Phan tu lon nhat la %u\n", max);
    printf("Phan tu nho nhat la %u\n", min);
    return 0;
}

#include <conio.h>
#include <stdio.h>
#include <limits.h>

int main()
{
    // Biến số nguyên n với giá trị khởi tạo ban đầu = -1 để kích hoạt vòng lặp tiếp theo
    int n = -1;
    // Vòng lặp sẽ tiếp tục khi n không thỏa mãn điều kiện là số nguyên dương
    while (n < 1)
    {
        printf("Nhap n : ");
        scanf("%u", &n);
    }
    // Biến mảng số nguyên a có n phần tử
    unsigned int a[n];
    // Biến min, max sẽ tham gia việc so sánh
    // Cả max = 0 vì 0 nằm ngoài phạm vi số được phép theo đề và là số bé hơn phạm vi theo đề
    // min = giá trị lớn nhất của max để để có thể tìm ra số bé nhất trong mảng
    unsigned int min = INT_MAX, max = 0;
    for (unsigned int i = 0; i < n; i++)
        do
        {
            printf("Nhap phan tu %u : ");
            scanf("%u", &a[i]);
            // Sau khi nhập giá trị vào mảng xong thì kiểm tra giá trị đó có lớn hơn hay bé hơn min và max không.
            // Nếu lớn hơn max thì giá trị đó sẽ là max
            if (max < a[i])
                max = a[i];
            // Nếu bé hơn min thì giá trị đó sẽ là min
            if (min > a[i])
                min = a[i];
        } while (a[i] < 1);
        printf("Phan tu lon nhat la %u\n", max);
        printf("Phan tu nho nhat la %u\n", min);
        return 0;
}

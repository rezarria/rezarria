#include <stdio.h>
#include <stdlib.h>
#define swap(x, y) \
    if (x != y)    \
    (x += y, y = x - y, x = x - y)

int *create(int n)
{
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("[%d]: ", i);
        scanf("%d", arr + i);
    }
    return arr;
}

void display(int *arr, int l, int r)
{
    putchar('[');
    for (int i = l; i < r; i++)
    {
        printf("%2d", arr[i]);
        if (i + 1 < r)
            putchar('\t');
    }
    putchar(']');
}

void heapify(int *arr, int n, int i)
{
    printf("\t\tTạo/Cập nhật heap tại vị trí %d\n", i);
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        printf("\t\tĐổi root arr[%d] <-> arr[%d]\n", i, largest);
        printf("\t%d\t-->\t\t%d\n", arr[i], arr[largest]);
        printf("%d\t\t%d\t%d\t\t%d\n", arr[l], arr[r], arr[l == largest ? i : l], arr[r == largest ? i : r]);
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n)
{
    puts("**************************************");
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    printf("Sau khi tạo đống\n");
    display(arr, 0, n);
    putchar(10);
    puts("**************************************");
    for (int i = n - 1; i > 0; i--)
    {
        printf("Phạm vi đang xét %d!\t", i);
        display(arr, 0, i + 1);
        putchar(10);
        printf("Đưa phần tử ở cuối phạm vi lên đầu\n");
        printf("arr[%d] <-> arr[%d]\n", 0, i);
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        display(arr, 0, i + 1);
        putchar(10);
    puts("**************************************");
    }
}

int main()
{
    int n, *arr = NULL;
    do
    {
        printf("n : ");
        scanf("%d", &n);
    } while (n < 0);
    arr = create(n);
    printf("Đầu vào : ");
    display(arr, 0, n);
    putchar(10);
    heapSort(arr, n);
    display(arr, 0, n);
    return 0;
}
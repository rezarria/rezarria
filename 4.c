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
        printf("%2d\t", arr[i]);
    }
    putchar(']');
}

int partition(int *arr, int l, int r)
{
    printf("\t\tBắt đầu phân chia dãy từ %d đến %d\t", l, r - 1);
    display(arr, l, r--);
    putchar(10);
    printf("Dùng vị trí cuối làm mốc.");
    printf(" pin <- %d\n", arr[r]);
    int pin = arr[r];
    int count = l;
    for (int i = l; i < r; i++)
        if (pin > arr[i])
        {
            printf("arr[%d] <-> arr[%d]\n", i, count);
            swap(arr[i], arr[count]);
            count++;
        }
    swap(arr[r], arr[count]);
    printf("\t\t");
    display(arr, l, count);
    printf(" [ %d ] ", arr[count]);
    display(arr, count + 1, r + 1);
    return count;
}

void quickSort(int *arr, int l, int r)
{
    if (l < r - 1)
    {
        puts("*****************************************");
        printf("Xét từ %d đến %d!\n", l, r - 1);
        int pin = partition(arr, l, r);
        puts("\n*****************************************");
        quickSort(arr, l, pin);
        quickSort(arr, pin + 1, r);
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
    quickSort(arr, 0, n);
    display(arr, 0, n);
    return 0;
}
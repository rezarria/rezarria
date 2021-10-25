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

void display(int *arr, int n)
{
    putchar('[');
    for (int i = 0; i < n; i++)
    {
        printf("%3d\t", arr[i]);
    }
    puts("]");
}

void bubbleSort(int *arr, int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        puts("----------------------------");
        printf("Xét vị trí thứ %2d\n", i);
        for (j = n - 1; j + 1 > i; j--)
            if (arr[j] < arr[j - 1])
            {
                printf("\t\tĐẩy arr[%2d] lên.\t", j - 1);
                swap(arr[j], arr[j - 1]);
                display(arr, n);
            }
        printf("\t\t\t\t\t");
        display(arr, n);
        puts("----------------------------\n");
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
    bubbleSort(arr, n);
    display(arr, n);
    return 0;
}
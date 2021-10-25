#include <stdio.h>
#include <stdlib.h>
#define swap(x, y) if(x!=y) (x += y, y = x - y, x = x - y)

        void
        display(int *arr, int n)
{
    putchar('[');
    for (int i = 0; i < n; i++)
    {
        printf("%3d\t", arr[i]);
    }
    puts("]");
}

void selectionSort(int *arr, int n)
{
    int end = n - 1;
    int i, j, t, min;
    for (i = 0; i < end; i++)
    {
        printf("Vao vi tri %2d\n----------------------------------------------------------------------\n", i);
        min = i;
        printf("min <-%2d.\narr[min] = %2d\n", i, arr[min]);
        for (j = i + 1; j < n; j++)
        {
            printf("\t\tXet arr[%2d] < arr[min] : %2d < %2d\t", j, arr[j], arr[min]);
            if (arr[min] > arr[j])
            {
                printf("ok\t- min <-%2d.\n", j);
                min = j;
            }
            else
                printf("sai\t- bỏ qua.\n");
        };
        printf("arr[%2d] <-> arr[%2d]\n", i, min);
        display(arr, n);
        swap(arr[i], arr[min]);
        display(arr, n);
        printf("----------------------------------------------------------------------\n");
    }
}

int *create(int n)
{
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("[%d]: ", i);
        scanf("%d", arr + i);
    }
    return arr;
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
    selectionSort(arr, n);
    display(arr, n);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

FILE *output;

void readFromFile(const char *path, int **arr, int *n)
{
    FILE *file = fopen(path, "r");
    *n = 0;
    int i = 0;
    int buffer;
    while (fscanf(file, "%d", &buffer) != EOF)
        (*n)++;
    *arr = malloc((*n) * sizeof(int));
    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%d", *arr + i++) != EOF)
        ;
    fclose(file);
}

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
    putc('[', output);
    for (int i = 0; i < n; i++)
    {
        fprintf(output, "%3d", arr[i]);
    }
    fprintf(output, "]\n");
}

void insertionSort(int *arr, int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        fprintf(output, "\ni = %2d\n", i);
        fprintf(output, "------------------------------------------------\n");
        j = i - 1;
        x = arr[i];
        while (j >= 0 && arr[j] > x)
        {
            fprintf(output, "\t\tđẩy arr[%2d] lên!!\t", j);
            arr[j-- + 1] = arr[j];
            display(arr, n);
        }
        fprintf(output, "đặt arr[i] gốc vào đúng vị trí!!\t");
        arr[j + 1] = x;
        display(arr, n);
        fprintf(output, "------------------------------------------------\n");
    }
}

int main()
{
    int n, *arr = NULL;
    output = fopen("output.txt", "w");
    readFromFile("input.txt", &arr, &n);
    display(arr, n);
    insertionSort(arr, n);
    display(arr, n);
    return 0;
}
#include <stdio.h>

void nhapMang(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%d] : ", i);
        scanf("%d", arr + i);
    }
}

void ghiVaoTep(char *ten, int *arr, int n)
{
    FILE *f = fopen(ten, "w");
    for (int i = 0; i < n; i++)
        if (arr[i] > 0)
            fprintf(f, "%d\t", arr[i]);
    fclose(f);
}

int main()
{
    printf("Nhap n : ");
    int n;
    scanf("%d", &n);
    int arr[n];
    nhapMang(arr, n);
    ghiVaoTep("output.txt", arr, n);
    return 0;
}
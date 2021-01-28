#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

size_t soDoiTuong(FILE *f)
{
    fseek(f, 0, SEEK_SET);
    bool cut = false;
    size_t dem = 0llu;
    while (!feof(f))
        switch (fgetc(f))
        {
        case ' ':
        case '\n':
        case '\0':
        case EOF:
            if (cut)
            {
                cut = false;
                dem++;
            }
            break;
        default:
            if (!cut)
                cut = true;
        }
    fseek(f, 0, SEEK_SET);
    return dem;
}

int tongDuongLe(int *arr, size_t n)
{
    int t = 0;
    for (size_t i = 0llu; i < n; i++)
        if (arr[i] > 0 && arr[i] % 2)
            t += arr[i];
    return t;
}

void layTuTep(FILE *f, int *arr, size_t n)
{
    for (size_t i = 0llu; i < n; i++)
        fscanf(f, "%d", arr + i);
}

int main()
{
    FILE *f = fopen("input.txt", "r");
    size_t n = soDoiTuong(f);
    int arr[n];
    layTuTep(f, arr, n);
    fclose(f);
    printf("%d\n", tongDuongLe(arr, n));
    return 0;
}
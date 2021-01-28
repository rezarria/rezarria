#include <stdio.h>
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

void docTuTep(FILE *f, int *arr, size_t n)
{
    for (size_t i = 0llu; i < n; i++)
        fscanf(f, "%d", arr + i);
}

int max(int *arr, size_t n)
{
    int m = *arr;
    for (size_t i = 1; i < n; i++)
        if (m < arr[i])
            m = arr[i];
    return m;
}

int main()
{
    FILE *f = fopen("input.txt", "r");
    size_t n = soDoiTuong(f);
    int arr[n];
    docTuTep(f, arr, n);
    printf("%d\n", max(arr, n));
    fclose(f);
    return 0;
}